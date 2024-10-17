// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulador de autómatas finitos
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/10/2024

// Archivo Alfabeto.h:     Declaración de la clase Alfabeto.
//                         Contiene la declaración de los atributos y
//                         métodos de la clase Alfabeto que representa
//                         un alfabeto de un autómata finito.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/10/2024 - Creación (primera versión) del código

#pragma once

#include <fstream>
#include <iostream>
#include <set>

class Alfabeto {
public:
  /// @brief Constructor por defecto de la clase Alfabeto.
  Alfabeto();
	/// @brief Constructor de la clase Alfabeto.
	/// @param alfabeto String que contiene el alfabeto.
  Alfabeto(std::string &alfabeto);
	/// @brief Destructor de la clase Alfabeto.
  ~Alfabeto();

  /// @brief Getter del atributo alfabeto_.
  /// @return Referencia constante al atributo alfabeto_.
  std::set<char> &getAlfabeto() { return alfabeto_; };

private:
  std::set<char> alfabeto_;
};