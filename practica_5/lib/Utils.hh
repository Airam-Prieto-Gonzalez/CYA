#include <fstream>

#include "PointTypes.hh"
#include "SubTree.hh"
#include "PointSet.hh"

bool read_points(const char *filename, CyA::point_vector &points)
{
    std::ifstream is(filename);
    if (!is)
    {
        return false;
    }

    points.clear();

    int n;
    is >> n;

    for (int i = 0; i < n; ++i)
    {
        CyA::point p;
        is >> p;
        points.push_back(p);
    }

    return true;
}