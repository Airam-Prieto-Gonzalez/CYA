// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Cadenas y lenguajes
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/09/2024

// Archivo Cadena.h:  definición de los métodos de la clase Cadena.
//                              Contiene la declaración de los métodos de la
//                              clase Cadena.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/09/2024 - Creación (primera versión) del código

#pragma once

#include <fstream>
#include <iostream>
#include <set>
#include <vector>

#include "Alfabeto.h"

/// @brief Clase Cadena: representa la sucesion de caracteres basados en un
/// alfabeto
class Cadena {
public:
  /// @brief Contructor por defecto de la clase Cadena
  Cadena();
  /// @brief Contructor de la clase Cadena
  /// @param cadena string que representa la cadena
  /// @param alfabeto string que representa el alfabeto de la cadena
  Cadena(const std::string &cadena, const std::string &alfabeto);
  /// @brief Destructor de la clase Cadena
  ~Cadena();

  /// @brief Getter de la cadena
  /// @return referencia constante del parametro cadena_
  const std::string &cadena() const;

  /// @brief Método que escribe el alfabeto de la cadena en el fichero de salida
  /// @param output_file el descriptor del fichero de salida donde se escribirán
  /// los resultados
  void alfabeto(std::ofstream &output_file) const;
  /// @brief Método que devuelve la longitud de la cadena
  /// @return Un entero que representa la logitud de la cadena
  int longitud() const;
  /// @brief Método que imprime la cadena de forma inversa en el fichero de
  /// salida
  /// @param output_file descriptor del fichero de salida donde se escribirán
  /// las cadenas inversas
  void inversa(std::ofstream &output_file) const;
  /// @brief Método que imprime los prefijos de la cadena en el fichero de
  /// salida
  /// @param output_file Descriptor del fichero de salida donde se escribirán
  /// los prefijos
  void prefijos(std::ofstream &output_file) const;
  /// @brief Método que imprime los sufijos de la cadena en el fichero de salida
  /// @param output_file Descriptor del fichero de salida donde se escribirán
  /// los sufijos
  void sufijos(std::ofstream &output_file) const;

  /// @brief Sobrecarga del operador de salida
  /// @param out referencia al flujo de salida
  /// @param cadena referencia al objeto cadena a escribir
  /// @return referencia al flujo de salida
  friend std::ostream &operator<<(std::ostream &out, const Cadena &cadena) {
    out << cadena.cadena();
    return out;
  }

private:
  std::string cadena_;
  Alfabeto alfabeto_;
};