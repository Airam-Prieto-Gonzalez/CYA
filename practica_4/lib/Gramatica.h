// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 8: Gramáticas en forma normal de Chomsky
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 31/10/2024

// Archivo Gramatica.h: Declaración de la clase Gramatica
// Contiene un objeto de la clase Simbolos que representa los simbolos terminales
// Contiene un objeto de la clase Simbolos que representa los simbolos no terminales
// Contiene un objeto de la clase Producciones que representa las producciones de la gramática

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 31/10/2024 - Creación (primera versión) del código

#include <iostream>
#include <string>
#include <vector>

#include "Producciones.h"
#include "Simbolos.h"

#pragma once

class Gramatica {
public:
  /// @brief Constructor por defecto
  Gramatica() = default;
  /// @brief Constructor con parámetros
  /// @param kTerminales Objeto de la clase Simbolos que representa los simbolos terminales
  /// @param kNo_terminales Objeto de la clase Simbolos que representa los simbolos no terminales
  /// @param kProducciones Objeto de la clase Producciones que representa las producciones
  /// @param kSimbolo_inicial std::string que representa el simbolo inicial
  Gramatica(const Simbolos &kTerminales, const Simbolos &kNo_terminales,
            const Producciones &kProducciones,
            const std::string &kSimbolo_inicial)
      : terminales_(kTerminales), no_terminales_(kNo_terminales),
        producciones_(kProducciones), simbolo_inicial_(kSimbolo_inicial) {}

  /// @brief Getter de los simbolos terminales
  /// @return Objeto de la clase Simbolos que representa los simbolos terminales
  Simbolos getTerminales() const { return terminales_; }
	/// @brief Getter de los simbolos no terminales
	/// @return Objeto de la clase Simbolos que representa los simbolos no terminales
  Simbolos getNoTerminales() const { return no_terminales_; }
	/// @brief Getter de las producciones
	/// @return Objeto de la clase Producciones que representa las producciones
  Producciones getProducciones() const { return producciones_; }
	/// @brief Getter del simbolo inicial
	/// @return std::string que representa el simbolo inicial
	std::string getSimboloInicial() const { return simbolo_inicial_; }
  /// @brief Comprueba si la gramática tiene producciones vacías
  /// @return Booleano que será true si encuentra alguna producción vacía
  bool ProduccionesVacias();
  /// @brief Comprueba si la gramática tiene producciones unitarias
  /// @return Booleano que será true si incumple alguna producción unitaria
  bool ProduccionesUnitarias();

	/// @brief Inserta una producción en el multimap de producciones
	/// @param kClave std::string que representa el símbolo no terminal que produce la producción
	/// @param kValor Objeto de la clase Simbolos que representa los simbolos de la producción
  void InsertaProduccion(const std::string kClave, const Simbolos &kValor);
	/// @brief Elimina una producción del multimap de producciones
	/// @param kClave std::string que representa el símbolo no terminal que produce la producción
	/// @param kValor Objeto de la clase Simbolos que representa los simbolos de la producción
  void EliminaProduccion(const std::string kClave, const Simbolos &kValor);

	/// @brief Convierte la gramática a la forma normal de Chomsky
  void FormaNormalChomsky();

	/// @brief Sobrecarga del operador de salida
	/// @param os std::ostream donde se almacenará la salida
	/// @param gramatica Objeto de la clase Gramatica que se quiere imprimir
	/// @return std::ostream donde se ha almacenado la salida
  friend std::ostream &operator<<(std::ostream &os, const Gramatica &gramatica);

private:
  Simbolos terminales_;
  Simbolos no_terminales_;
  Producciones producciones_;
  std::string simbolo_inicial_;
};