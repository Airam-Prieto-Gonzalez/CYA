// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulador de autómatas finitos
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/10/2024

// Archivo Estado.cc:   Implementación de la clase Estado.
//                      Contiene la implementación de los métodos de la clase
//                      Estado.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/10/2024 - Creación (primera versión) del código

#include "../lib/Estado.h"

Estado::Estado(std::string &line) {
  std::stringstream ss(line);
  ss >> id_;
  ss >> aceptacion_;
  ss >> transiciones_;
  for (int i = 0; i < transiciones_; i++) {
    char c;
    int id;
    ss >> c;
    ss >> id;
    map_transiciones_.insert({c, id});
  }
}

Estado::~Estado() { map_transiciones_.clear(); }

void Estado::ImprimeEstado() const {
  std::cout << "Estado: " << id_ << std::endl;
  std::cout << "\tAceptacion: " << aceptacion_ << std::endl;
  std::cout << "\tTransiciones: " << std::endl;
  for (const auto &transicion : map_transiciones_) {
    std::cout << "\t\t";
    std::cout << transicion.first << " -> " << transicion.second << std::endl;
  }
}
