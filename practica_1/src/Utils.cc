// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Cadenas y lenguajes
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/09/2024

// Archivo Utils.cc:  Definición de las funciones del programa.
//                              Contiene la definición de las funciones que se
//                              encargan de realizar las principales operaciones
//                              con las cadenas y alfabetos.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/09/2024 - Creación (primera versión) del código

#include "../lib/Utils.h"
#include "../lib/Cadena.h"

void FuncionAlfabeto(std::vector<Cadena *> &cadenas,
                     std::ofstream &output_file) {
  for (int i = 0; i < cadenas.size(); ++i) {
    cadenas[i]->alfabeto(output_file);
  }
}

void FuncionLongitud(std::vector<Cadena *> &cadenas,
                     std::ofstream &output_file) {
  for (int i = 0; i < cadenas.size(); ++i) {
    output_file << cadenas[i]->longitud() << std::endl;
  }
}

void FuncionInversa(std::vector<Cadena *> &cadenas,
                    std::ofstream &output_file) {
  for (int i = 0; i < cadenas.size(); ++i) {
    cadenas[i]->inversa(output_file);
  }
}

void FuncionPrefijos(std::vector<Cadena *> &cadenas,
                     std::ofstream &output_file) {
  for (int i = 0; i < cadenas.size(); ++i) {
    cadenas[i]->prefijos(output_file);
  }
}

void FuncionSufijos(std::vector<Cadena *> &cadenas,
                    std::ofstream &output_file) {
  for (int i = 0; i < cadenas.size(); ++i) {
    cadenas[i]->sufijos(output_file);
  }
}

void FuncionPalim(std::vector<Cadena *> &cadenas, std::ofstream &output_file) {
  for (int i = 0; i < cadenas.size(); ++i) {
    cadenas[i]->ispalim(output_file);
  }
}