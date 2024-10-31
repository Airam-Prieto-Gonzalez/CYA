
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Simbolos.h"

#pragma once

class Producciones {
public:
  /// @brief Constructor por defecto
  Producciones() = default;

  /// @brief Getter de las producciones
  /// @return std::multimap<std::string,Simbolos> que representa el atributo
  /// producciones_
  std::multimap<std::string, Simbolos> &getProducciones() {
    return producciones_;
  }

  /// @brief Inserta una producción en el multimap de producciones
  /// @param kClave std::string que representa la clave de la producción
  /// @param kValor Objeto de la clase Simbolos que representa el valor de la
  /// producción
  void InsertarProduccion(const std::string &kClave, const Simbolos &kValor);

  /// @brief Elimina una producción del multimap de producciones
  /// @param kClave std::string que representa la clave de la producción
  /// @param kValor Objeto de la clase Simbolos que representa el valor de la
  /// producción
  void EliminarProduccion(const std::string &kClave, const Simbolos &kValor);

  /// @brief Elimina todas las producciones de un símbolo no terminal
  /// @param kClave std::string que representa la clave de la producción
  friend std::ostream &operator<<(std::ostream &os,
                                  const Producciones &producciones);

private:
  std::multimap<std::string, Simbolos> producciones_;
};