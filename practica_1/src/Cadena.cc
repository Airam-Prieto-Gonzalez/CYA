// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Cadenas y lenguajes
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/09/2024

// Archivo cya-P02-strings.cc:  programa cliente.
//                              Contiene la función main del proyecto que usa las clases X e Y
//                              para ... (indicar brevemente el objetivo)

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/09/2024 - Creación (primera versión) del código

#include "../lib/Cadena.h"

Cadena::Cadena() {
  cadena_ = "&";
}

Cadena::Cadena(const std::string &cadena, const std::string &alfabeto) {
  cadena_ = cadena;
  for (int i = 0; i < alfabeto.size(); i++) {
    alfabeto_.insert(alfabeto[i]);
  }
}

Cadena::~Cadena() {}

const std::string& Cadena::cadena() const {
  return cadena_;
}

const std::string Cadena::alfabeto() const {
    std::string alfabeto;
    for (auto it = alfabeto_.begin(); it != alfabeto_.end(); it++) {
        alfabeto += *it;
    }
    return alfabeto;
}

int Cadena::longitud() const {
  return cadena_.size();
}

// const std::string& Cadena::inversa() const {
//   std::string inversa;
// }

// const std::set<std::string>& Cadena::prefijos() const {
//   std::vector<std::string> prefijos;

// }

// const std::set<std::string>& Cadena::sufijos() const {
//   std::vector<std::string> sufijos;

// }