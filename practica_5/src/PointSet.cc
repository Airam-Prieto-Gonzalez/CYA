// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 11: Mínimo Árbol de Expansión Euclídeo
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 8/12/2024

// Archivo PointSet.cc: Archivo de implementación de la clase point_set
// Contiene la implementación de los métodos de la clase point_set

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 31/10/2024 - Creación (primera versión) del código

#include <algorithm>

#include "../lib/PointSet.hh"
#include "../lib/SubTree.hh"

using namespace EMST;

/// @brief Constructor de la clase point_set
/// @param points Vector de puntos
point_set::point_set(const CyA::point_vector &points)
    : CyA::point_vector(points), emst_() {}

/// @brief  Destructor de la clase point_set
/// @param  void
point_set::~point_set(void) {}

/// @brief  Escribe en un flujo de salida los puntos del conjunto
/// @param  os Flujo de salida
/// @return void
void point_set::write(std::ostream &os) const {
  os << size() << std::endl;
  for (const CyA::point &p : *this) {
    os << p << std::endl;
  }
}

/// @brief  Calcula el árbol de expansión mínima
/// @param  void
/// @return void
void point_set::EMST(void) {
  CyA::arc_vector av;
  // Calculamos el vector de arcos
  compute_arc_vector(av);
  forest st;
  // Inicializamos el vector de subárboles con un subárbol por cada punto
  for (const CyA::point &p : *this) {
    sub_tree s;
    s.add_point(p);
    st.push_back(s);
  }
  // Ordenamos los arcos por peso
  for (const CyA::weigthed_arc &a : av) {
    int i, j;
    // Buscamos los subárboles incidentes a los puntos del arco
    find_incident_subtrees(st, a.second, i, j);
    if (i != j) {
      // Si los subárboles son distintos, los fusionamos
      merge_subtrees(st, a, i, j);
    }
  }
  emst_ = st[0].get_arcs();
}

/// @brief  Calcula el vector de arcos
/// @param  av Vector de arcos
/// @return void
void point_set::compute_arc_vector(CyA::arc_vector &av) const {
  av.clear();
  const int n = size();
  // Calculamos la distancia euclídea entre todos los pares de puntos
  for (int i = 0; i < n - 1; ++i) {
    const CyA::point &p_i = (*this)[i];
    for (int j = i + 1; j < n; ++j) {
      const CyA::point &p_j = (*this)[j];
      const double dist = euclidean_distance(std::make_pair(p_i, p_j));
      av.push_back(std::make_pair(dist, std::make_pair(p_i, p_j)));
    }
  }
  // Ordenamos los arcos por peso
  std::sort(av.begin(), av.end());
}

/// @brief  Busca los subárboles incidentes a los puntos del arco
/// @param  st Vector de subárboles
/// @param  a Arco
/// @param  i Índice del subárbol incidente al primer punto del arco
/// @param  j Índice del subárbol incidente al segundo punto del arco
/// @return void
void point_set::find_incident_subtrees(const forest &st, const CyA::arc &a,
                                       int &i, int &j) const {
  i = j = -1;
  for (int k = 0; k < st.size(); ++k) {
    // si el subárbol k contiene el punto a.first, i = k
    if (st[k].contains(a.first)) {
      i = k;
    }
    // si el subárbol k contiene el punto a.second, j = k
    if (st[k].contains(a.second)) {
      j = k;
    }
  }
}

/// @brief  Fusiona dos subárboles
/// @param  st Vector de subárboles
/// @param  a Arco
/// @param  i Índice del subárbol incidente al primer punto del arco
/// @param  j Índice del subárbol incidente al segundo punto del arco
/// @return void
void point_set::merge_subtrees(forest &st, const CyA::weigthed_arc &a, int i,
                               int j) const {
  st[i].merge(st[j], a);
  st.erase(st.begin() + j);
}

/// @brief  Calcula el coste del árbol de expansión mínima
/// @param  void
/// @return Coste del árbol de expansión mínima
double point_set::compute_cost(void) const {
  double cost = 0.0;
  for (const CyA::arc &a : emst_) {
    cost += euclidean_distance(a);
  }
  return cost;
}

/// @brief  Calcula la distancia euclídea entre dos puntos
/// @param  a Arco
/// @return Distancia euclídea entre los puntos del arco
double point_set::euclidean_distance(const CyA::arc &a) const {
  const CyA::point &p_i = a.first;
  const CyA::point &p_j = a.second;
  const double dx = p_i.first - p_j.first;
  const double dy = p_i.second - p_j.second;
  return std::sqrt(dx * dx + dy * dy);
}

/// @brief  Escribe en un flujo de salida el árbol de expansión mínima
/// @param  os Flujo de salida
/// @return void
void point_set::write_tree(std::ostream &os) const {
  os << "graph EMST {" << std::endl;
  for (const CyA::arc &a : emst_) {
    os << "  " << a.first << " -- " << a.second << std::endl;
  }
  os << "}" << std::endl;
}