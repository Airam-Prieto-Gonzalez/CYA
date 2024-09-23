// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Cadenas y lenguajes
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/09/2024

// Archivo Alfabeto.cc:  definición de los métodos de la clase Alfabeto.
//                              Contiene la declaración de los métodos de la
//                              clase Alfabeto.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/09/2024 - Creación (primera versión) del código

#include "../lib/Alfabeto.h"

Alfabeto::Alfabeto() {}

Alfabeto::Alfabeto(const std::string &alfabeto) {
  for (int i = 0; i < alfabeto.size(); i++) {
    alfabeto_.insert(alfabeto[i]);
  }
}

Alfabeto::~Alfabeto() {}

const std::set<char> &Alfabeto::get_alfabeto() const { return alfabeto_; }

void Alfabeto::insertar(const char &caracter) { alfabeto_.insert(caracter); }
