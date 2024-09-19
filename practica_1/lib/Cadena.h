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

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <set>

class Cadena {
 public:
  Cadena();
  Cadena(const std::string &cadena, const std::string &alfabeto);
  ~Cadena();

  const std::string& cadena() const;
  const std::string alfabeto() const;
  
  int longitud() const;
  const std::string& inversa() const;
  const std::set<std::string>& prefijos() const;
  const std::set<std::string>& sufijos() const;

  friend std::ostream& operator<<(std::ostream &out, const Cadena &cadena) {
    out << cadena.cadena();
    return out;
  }

 private:
  std::string cadena_;
  std::set<char> alfabeto_;
};