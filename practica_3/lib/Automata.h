// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulador de autómatas finitos
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/10/2024

// Archivo Automata.h:     Declaración de la clase Automata.
//                         Contiene la declaración de los atributos y
//                         métodos de la clase Automata que representa
//                         un autómata finito.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/10/2024 - Creación (primera versión) del código

#pragma once

#include <fstream>
#include <iostream>

#include "Alfabeto.h"
#include "Estado.h"

class Automata {
public:
  /// @brief Constructor de la clase Automata.
  /// @param input_file Fichero de entrada que contiene la definición del autómata.
  Automata(std::ifstream &input_file);
	/// @brief Destructor de la clase Automata.
  ~Automata();

	/// @brief Getter del estado inicial del autómata.
	/// @return Referencia constante al estado inicial del autómata.
  const Estado &getEstadoInicial() { return estado_inicial_; };

  /// @brief Imprime el autómata.
  void ImprimeAutomata();

	/// @brief Comprueba si una cadena esta escrita sobre el lenguaje del autómata.
	/// @param cadena Cadena a comprobar.
	/// @return True si la cadena esta escrita sobre el lenguaje del autómata, false en caso contrario.
  bool CombruebaCadena(std::string &cadena);
  /// @brief Método que itera sobre una cadena para comprobar si esta es aceptada por el autómata de forma recursiva.
  /// @param cadena String que contiene la cadena a comprobar.
  /// @param estados_actuales Set que contiene los estados actuales del autómata.
  /// @param iteration Int que contiene la iteración actual.
  /// @return true si la cadena es aceptada por el autómata, false en caso contrario.
  bool IteraCadena(std::string &cadena, std::set<Estado> &estados_actuales, int iteration = 0) const;
	/// @brief Método que calcula la clausura epsilon de un conjunto de estados.
	/// @param estados_actuales Set que contiene los estados actuales del autómata, este set es modificado añadiendo todas las epsilon transiciones de cada estado.
  void EpsilonClausura(std::set<Estado> &estados_actuales) const;

private:
  Alfabeto alfabeto_;
  Estado estado_inicial_;
  std::map<int, Estado> estados_;
  std::set<int> estados_aceptacion_;
};