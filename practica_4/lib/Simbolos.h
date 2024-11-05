// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 8: Gramáticas en forma normal de Chomsky
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 31/10/2024

// Archivo Simbolos.h: Declaración de la clase Simbolos
// Contiene un vector de strings que representa los simbolos de una gramática
// Los simbolos pueden ser terminales o no terminales
// Los simbolos no pueden contener espacios

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 31/10/2024 - Creación (primera versión) del código

#include <iostream>
#include <string>
#include <vector>

#pragma once

class Simbolos {
public:
  /// @brief Constructor por defecto
  Simbolos() = default;
  /// @brief Constructor principal
  Simbolos(const std::string &simbolos);

  /// @brief Getter del vector de simbolos
  /// @return std::vector<std::string>
  const std::vector<std::string> &getSimbolos() const { return simbolos_; }
  /// @brief Comprueba si un simbolo existe en el vector de simbolos
  /// @param simbolo std::string que representa el simbolo a comprobar
  /// @return bool que será true si el simbolo existe y false en caso contrario
  bool ExisteSimbolo(std::string simbolo) const;

  /// @brief Inserta un simbolo al final del vector de simbolos
  /// @param simbolos std::string que representa el simbolo a insertar
  void InsertarSimbolo(std::string &simbolos);
  /// @brief Elimina un simbolo del vector de simbolos
  /// @param simbolo std::string que representa el simbolo a eliminar
  void EliminarSimbolo(std::string &simbolo);
  /// @brief Elimina el último simbolo del vector de simbolos
  void EliminaUltimoSimbolo() { simbolos_.pop_back(); }
  /// @brief Sustituye un simbolo por otro en el vector de simbolos
  /// @param simbolo_antiguo std::string que representa el simbolo a sustituir
  /// @param nuevo_simbolo std::string que representa el simbolo nuevo
  void SustituirSimbolo(std::string &simbolo_antiguo,
                        std::string &nuevo_simbolo);
  /// @brief Limpiar el vector de simbolos
  void Clear() { simbolos_.clear(); }

  /// @brief Sobrecarga del operador de asignación
  /// @param simbolos const Simbolos & que representa el objeto a asignar
  /// @return Simbolos & que representa el objeto asignado
  Simbolos &operator=(const Simbolos &simbolos);
  /// @brief Sobrecarga del operador de inserción en flujo
  /// @param os std::ostream & que representa el flujo de salida
  /// @param simbolos const Simbolos & que representa el objeto a insertar
  /// @return std::ostream & que representa el flujo de salida
  friend std::ostream &operator<<(std::ostream &os, const Simbolos &simbolos);

private:
  std::vector<std::string> simbolos_;
};