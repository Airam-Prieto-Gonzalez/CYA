// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulador de autómatas finitos
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/10/2024

// Archivo Estado.h:     Declaración de la clase Estado.
//                       Contiene la declaración de los atributos y
//                       métodos de la clase Estado que representa
//                       un estado de un autómata finito.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/10/2024 - Creación (primera versión) del código

#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

class Estado {
public:
  /// @brief Constructor por defecto
  Estado() = default;
  /// @brief Constructor de la clase Estado
  /// @param data String con los datos del estado
  Estado(std::string &data);
  /// @brief Destructor de la clase Estado
  ~Estado();

  /// @brief Getter del id del estado
  /// @return int Id del estado
  int getId() const { return id_; };
  /// @brief Getter de la aceptación del estado
  /// @return bool Aceptación del estado
  bool getAceptacion() const { return aceptacion_; };
  /// @brief Getter de las transiciones del estado
  /// @return Int que representa el número de transiciones
  int getTransiciones() const { return transiciones_; };
  /// @brief Getter del mapa de transiciones del estado
  /// @return Getter del mapa de transiciones del estado
  const std::multimap<char, int> &getMapTransiciones() const {
    return map_transiciones_;
  };

  /// @brief Impresión del estado
  void ImprimeEstado() const;

  /// @brief Sobrecarga de los operadores de comparación
  bool operator<(const Estado &estado) const { return id_ < estado.getId(); }
  bool operator==(const Estado &estado) const { return id_ == estado.getId(); }
  bool operator!=(const Estado &estado) const { return id_ != estado.getId(); }
  bool operator>(const Estado &estado) const { return id_ > estado.getId(); }
  bool operator<=(const Estado &estado) const { return id_ <= estado.getId(); }
  bool operator>=(const Estado &estado) const { return id_ >= estado.getId(); }

private:
  int id_;
  bool aceptacion_;
  int transiciones_;
  std::multimap<char, int> map_transiciones_;
};