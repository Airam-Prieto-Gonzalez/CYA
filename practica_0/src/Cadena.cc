// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Cadenas y lenguajes
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/09/2024

// Archivo Cadena.cc:  definición de los métodos de la clase Cadena.
//                              Contiene la implementación de los métodos de la
//                              clase Cadena

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/09/2024 - Creación (primera versión) del código

#include "../lib/Cadena.h"
#include "../lib/Utils.h"

Cadena::Cadena() { cadena_ = "&"; }

Cadena::Cadena(const std::string &cadena, const std::string &alfabeto) {
  cadena_ = cadena;
  for (int i = 0; i < alfabeto.size(); i++) {
    alfabeto_.insertar(alfabeto[i]);
  }
}

Cadena::~Cadena() {}

const std::string &Cadena::cadena() const { return cadena_; }

void Cadena::alfabeto(std::ofstream &output_file) const {
  output_file << "{";
  for (auto it = alfabeto_.get_alfabeto().begin(); it != alfabeto_.get_alfabeto().end(); ++it) {
    output_file << *it;
    if (std::next(it) != alfabeto_.get_alfabeto().end()) {
      output_file << ", ";
    }
  }
  output_file << "}" << std::endl;
  return;
}

int Cadena::longitud() const { return cadena_ != "&" ? cadena_.size() : 0; }

void Cadena::inversa(std::ofstream &output_file) const {
  std::string inversa;
  for (int i = cadena_.size() - 1; i >= 0; i--) {
    inversa += cadena_[i];
  }
  output_file << inversa << std::endl;
}

void Cadena::prefijos(std::ofstream &output_file) const {
  if (cadena_ == "&") {
    output_file << "{&}" << std::endl;
    return;
  }
  output_file << "{&, ";
  for (int i = 1; i <= cadena_.size() - 1; i++) {
    for (int j = 0; j < i; j++) {
      output_file << cadena_[j];
    }
    output_file << ", ";
  }
  output_file << cadena_ << "}" << std::endl;
}

void Cadena::sufijos(std::ofstream &output_file) const {
  if (cadena_ == "&") {
    output_file << "{&}" << std::endl;
    return;
  }
  output_file << "{&, ";
  for (int i = cadena_.size() - 1; i >= 0; i--) {
    for (int j = cadena_.size() - 1; j >= i; j--) {
      output_file << cadena_[j];
    }
    if (i != 0)
    output_file << ", ";
    else {
      output_file << "}" << std::endl;;
    }
  }
}

void Cadena::subcadenas(std::ofstream &output_file) const {
  if (cadena_ == "&") {
    output_file << "{&}" << std::endl;
    return;
  }
  std::set<std::string> subcadenas {};
  for (int i = 0; i < cadena_.size(); ++i) {
    for (int j = i; j < cadena_.size(); ++j) {
      subcadenas.insert(cadena_.substr(i, j - i + 1));
    }
  }
  output_file << "{&";
  for (auto it = subcadenas.begin(); it != subcadenas.end(); ++it) {
    output_file << ", " << *it;
  }
  output_file << "}" << std::endl;
}

void Cadena::subsecuencias(std::ofstream &output_file) const {
  if (cadena_ == "&") {
    output_file << "{&}" << std::endl;
    return;
  }
  std::set<std::string> subsecuencias {};
  CalcularSubsecuencias(cadena_, "", subsecuencias);
  subsecuencias.extract("");
  output_file << "{&";
  for (auto it = subsecuencias.begin(); it != subsecuencias.end(); ++it) {
    output_file << ", " << *it;
  }
  output_file << "}  " << subsecuencias.size() << std::endl;
}
