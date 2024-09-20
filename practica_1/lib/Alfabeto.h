// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Cadenas y lenguajes
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/09/2024

// Archivo Alfabeto.h:  declaración de los métodos de la clase Alfabeto.
//                              Contiene la declaración de los métodos de la
//                              clase Alfabeto.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/09/2024 - Creación (primera versión) del código

#pragma once

#include <iostream>
#include <set>
#include <string>

class Alfabeto {
public:
  /// @brief Constructor por defecto de la clase Alfabeto.
  Alfabeto();
  /// @brief Constructor de la clase Alfabeto.
  /// @param alfabeto String que contiene los caracteres del alfabeto.
  Alfabeto(const std::string &alfabeto);
  /// @brief Destructor de la clase Alfabeto.
  ~Alfabeto();
  /// @brief Getter de la clase Alfabeto.
  /// @return El atributo alfabeto_ de la clase Alfabeto.
  const std::set<char> &get_alfabeto() const;
  /// @brief Método de la clase Alfabeto que inserta un caracter en el alfabeto.
  /// @param caracter el caracter a insertar en el alfabeto.
  void insertar(const char &caracter);
  // void borrar(const char &caracter);
  // bool pertenece(const char &caracter) const;
private:
  std::set<char> alfabeto_;
};