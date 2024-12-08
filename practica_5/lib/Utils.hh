// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 11: Mínimo Árbol de Expansión Euclídeo
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 8/12/2024

// Archivo Utils.hh: Archivo de cabecera de funciones auxiliares
// Contiene la declaración de funciones auxiliares para la lectura de puntos

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 31/10/2024 - Creación (primera versión) del código

#include <fstream>

#include "PointSet.hh"
#include "PointTypes.hh"
#include "SubTree.hh"

bool read_points(const char *filename, CyA::point_vector &points) {
  std::ifstream is(filename);
  if (!is) {
    return false;
  }
  points.clear();
  int n;
  is >> n;
  for (int i = 0; i < n; ++i) {
    CyA::point p;
    is >> p;
    points.push_back(p);
  }

  return true;
}