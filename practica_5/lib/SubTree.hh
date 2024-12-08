// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 11: Mínimo Árbol de Expansión Euclídeo
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 8/12/2024

// Archivo SubTree.hh: Archivo de cabecera de la clase sub_tree
// Contiene la declaración de la clase sub_tree, que representa un subárbol

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 31/10/2024 - Creación (primera versión) del código

#pragma once

#include <cmath>
#include <iostream>

#include "PointTypes.hh"

namespace EMST {
class sub_tree {
 private:
  CyA::tree arcs_;
  CyA::point_collection points_;
  double cost_;

 public:
  sub_tree(void);
  ~sub_tree(void);

  void add_arc(const CyA::arc &a);
  void add_point(const CyA::point &p);
  bool contains(const CyA::point &p) const;
  void merge(const sub_tree &st, const CyA::weigthed_arc &a);

  inline const CyA::tree &get_arcs(void) const { return arcs_; }
  inline double get_cost(void) const { return cost_; }
};

typedef std::vector<sub_tree> sub_tree_vector;
}  // namespace EMST