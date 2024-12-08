// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 11: Mínimo Árbol de Expansión Euclídeo
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 8/12/2024

// Archivo SubTree.cc: Archivo de implementación de la clase sub_tree
// Contiene la implementación de los métodos de la clase sub_tree

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 31/10/2024 - Creación (primera versión) del código

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <utility>

#include "../lib/SubTree.hh"

namespace EMST {

/// @brief Constructor de la clase sub_tree
/// @param void 
sub_tree::sub_tree(void) : arcs_(), points_(), cost_(0) {}

/// @brief Destructor de la clase sub_tree
/// @param void
sub_tree::~sub_tree(void) {}

/// @brief Añade un arco al subárbol
/// @param a Arco
void sub_tree::add_arc(const CyA::arc &a) {
  arcs_.push_back(a);
  points_.insert(a.first);
  points_.insert(a.second);
}

/// @brief Añade un punto al subárbol
/// @param p Punto
void sub_tree::add_point(const CyA::point &p) { points_.insert(p); }

/// @brief Comprueba si el subárbol contiene un punto
/// @param p Punto
/// @return true si el subárbol contiene el punto, false en caso contrario
bool sub_tree::contains(const CyA::point &p) const {
  return points_.find(p) != points_.end();
}

/// @brief Fusiona dos subárboles
/// @param st Vector de subárboles
/// @param a Arco
/// @return void
void sub_tree::merge(const sub_tree &st, const CyA::weigthed_arc &a) {
  arcs_.insert(arcs_.end(), st.arcs_.begin(), st.arcs_.end());
  arcs_.push_back(a.second);
  points_.insert(st.points_.begin(), st.points_.end());
  cost_ += a.first + st.get_cost();
}
}  // namespace EMST