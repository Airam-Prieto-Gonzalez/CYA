// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 11: Mínimo Árbol de Expansión Euclídeo
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 8/12/2024

// Archivo PointTypes.hh: Declaración de la clase sub_tree
// Contiene la declaración de la clase sub_tree, que representa un subárbol

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 31/10/2024 - Creación (primera versión) del código

#pragma once

#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define MAX_SZ 3
#define MAX_PREC 0

namespace CyA {
typedef std::pair<double, double> point;

typedef std::pair<point, point> line;
typedef std::vector<point> point_vector;

typedef std::pair<point, point> arc;
typedef std::pair<double, arc> weigthed_arc;
typedef std::vector<weigthed_arc> arc_vector;

typedef std::set<point> point_collection;

typedef std::vector<arc> tree;
}  // namespace CyA

std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps);
std::ostream& operator<<(std::ostream& os, const CyA::point& ps);

std::istream& operator>>(std::istream& is, CyA::point_vector& ps);
std::istream& operator>>(std::istream& is, CyA::point& ps);
