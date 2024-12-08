    #include <algorithm>
    
    #include "PointSet.hh"
    #include "SubTree.hh"
    
    using namespace EMST;

    point_set::point_set(const CyA::point_vector &points) : CyA::point_vector(points),
                                                             emst_()
    {
    }

    point_set::~point_set(void)
    {
    }

    void point_set::write(std::ostream &os) const
    {
        os << size() << std::endl;

        for (const CyA::point &p : *this)
        {
            os << p << std::endl;
        }
    }
    
    void point_set::EMST(void)
    {
        CyA::arc_vector av;
        compute_arc_vector(av);

        forest st;

        for (const CyA::point &p : *this)
        {
            sub_tree s;
            s.add_point(p);

            st.push_back(s);
        }

        for (const CyA::weigthed_arc &a : av)
        {
            int i, j;
            find_incident_subtrees(st, a.second, i, j);

            if (i != j)
            {
                merge_subtrees(st, a, i, j);
            }
        }

        emst_ = st[0].get_arcs();
    }

    void point_set::compute_arc_vector(CyA::arc_vector &av) const
    {
        av.clear();
        
        const int n = size();
 
        for (int i = 0; i < n - 1; ++i)
        {
            const CyA::point &p_i = (*this)[i];
 
            for (int j = i + 1; j < n; ++j)
            {
                const CyA::point &p_j = (*this)[j];
 
                const double dist = euclidean_distance(std::make_pair(p_i, p_j));
 
                av.push_back(std::make_pair(dist, std::make_pair(p_i, p_j)));
            }
        }
 
        std::sort(av.begin(), av.end());
    }

    void point_set::find_incident_subtrees(const forest& st, const CyA::arc &a, int& i, int& j) const
    {
        i = j = -1;

        for (int k = 0; k < st.size(); ++k)
        {
            if (st[k].contains(a.first))
            {
                i = k;
            }

            if (st[k].contains(a.second))
            {
                j = k;
            }
        }
    }

    void point_set::merge_subtrees(forest& st, const CyA::weigthed_arc &a, int i, int j) const
    {
        st[i].merge(st[j], a);
        st.erase(st.begin() + j);
    }

    double point_set::compute_cost(void) const
    {
        double cost = 0.0;

        for (const CyA::arc &a : emst_)
        {
            cost += euclidean_distance(a);
        }

        return cost;
    }

    double point_set::euclidean_distance(const CyA::arc& a) const
    {
        const CyA::point &p_i = a.first;
        const CyA::point &p_j = a.second;

        const double dx = p_i.first - p_j.first;
        const double dy = p_i.second - p_j.second;

        return std::sqrt(dx * dx + dy * dy);
    }

    void point_set::write_tree(std::ostream &os) const
    {
        os << "graph EMST {" << std::endl;

        for (const CyA::arc &a : emst_)
        {
            os << "  " << a.first << " -- " << a.second << std::endl;
        }

        os << "}" << std::endl;
    }
