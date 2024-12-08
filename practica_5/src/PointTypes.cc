// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 11: Mínimo Árbol de Expansión Euclídeo
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 8/12/2024

// Archivo PointTypes.cc: Archivo de implementación de los operadores de entrada
// y salida para los tipos de datos de la clase point_set

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 31/10/2024 - Creación (primera versión) del código

#include <iomanip>

#include "../lib/PointTypes.hh"

/// @brief Operador de salida para un vector de puntos
/// @param os Objeto de tipo ostream por referencia
/// @param ps Vector de puntos por referencia constante
/// @return Objeto de tipo ostream por referencia
std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps) {
  os << ps.size() << std::endl;
  for (const CyA::point& p : ps) {
    os << p << std::endl;
  }
  return os;
}

/// @brief Operador de salida para un punto
/// @param os Objeto de tipo ostream por referencia
/// @param p Punto por referencia constante
/// @return Objeto de tipo ostream por referencia
std::ostream& operator<<(std::ostream& os, const CyA::point& p) {
  os << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC)
     << p.first << "\t" << std::setw(MAX_SZ) << std::fixed
     << std::setprecision(MAX_PREC) << p.second;
  return os;
}

/// @brief Operador de entrada para un vector de puntos
/// @param is Objeto de tipo istream por referencia
/// @param ps Vector de puntos por referencia
/// @return Objeto de tipo istream por referencia
std::istream& operator>>(std::istream& is, CyA::point_vector& ps) {
  int n;
  is >> n;
  ps.clear();
  for (int i = 0; i < n; ++i) {
    CyA::point p;
    is >> p;
    ps.push_back(p);
  }
  return is;
}

/// @brief Operador de entrada para un punto
/// @param is Objeto de tipo istream por referencia
/// @param p Punto por referencia
/// @return Objeto de tipo istream por referencia
std::istream& operator>>(std::istream& is, CyA::point& p) {
  is >> p.first >> p.second;
  return is;
}