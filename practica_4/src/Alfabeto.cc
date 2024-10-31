// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulador de autómatas finitos
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/10/2024

// Archivo Alfabeto.cc:     Definición de la clase Alfabeto.
//                          Contiene la implementación de los métodos de la
//                          clase Alfabeto que representa un alfabeto de un
//                          autómata finito.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/10/2024 - Creación (primera versión) del código

#include "../lib/Simbolos.h"

int main() {
  Simbolos simbolos("abc");
//   std::string simbolos_string{"abc"};
//   simbolos.InsertarSimbolo(simbolos_string);
  std::cout << simbolos;
  std::string simbolo{"a"};
  std::string nuevo_simbolo{"d"};
  simbolos.SustituirSimbolo(simbolo, nuevo_simbolo);
    std::cout << simbolos;
  return 0;
}