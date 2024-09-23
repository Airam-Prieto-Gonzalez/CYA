// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Cadenas y lenguajes
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/09/2024

// Archivo Utils.h:  declaración de las funciones principales del programa.
//                              Contiene la implementación de las funciones
//                              principales del programa

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/09/2024 - Creación (primera versión) del código

#pragma once

#include <fstream>
#include <iostream>
#include <vector>

#include "../lib/Cadena.h"

/// @brief Función en cargada de imprimir los alfabetos de las cadenas recogidas
/// en el fichero de entrada
/// @param cadenas vector donde se encuentran las cadenas con las que trabajar
/// @param output_file el deescritor del fichero de salida donde se escribirán
/// los resultados
void FuncionAlfabeto(std::vector<Cadena *> &cadenas,
                     std::ofstream &output_file);
/// @brief Función encargada de imprimir las longitudes de las cadenas recogidas
/// en el fichero de entrada
/// @param cadenas vector donde se encuentran las cadenas con las que trabajar
/// @param output_file el descriptor del fichero de salida donde se escribirán
/// los resultados
void FuncionLongitud(std::vector<Cadena *> &cadenas,
                     std::ofstream &output_file);
/// @brief Función encargada de imprimir las cadenas recogidas en el fichero de
/// entrada de forma inversa
/// @param cadenas vector donde se encuentran las cadenas con las que trabajar
/// @param output_file el descriptor del fichero de salida donde se escribirán
/// los resultados
void FuncionInversa(std::vector<Cadena *> &cadenas, std::ofstream &output_file);
/// @brief Función encargada de imprimir los prefijos de las cadenas recogidas
/// en el fichero de salida
/// @param cadenas vector donde se encuentran las cadenas con las que trabajar
/// @param output_file el descriptor del fichero de salida donde se escribirán
/// los resultados
void FuncionPrefijos(std::vector<Cadena *> &cadenas,
                     std::ofstream &output_file);
/// @brief Función encargada de imprimir los sufijos de las cadenas recogidas en
/// el fichero de salida
/// @param cadenas vector donde se encuentran las cadenas con las que trabajar
/// @param output_file el descriptor del fichero de salida donde se escribirán
/// los resultados
void FuncionSufijos(std::vector<Cadena *> &cadenas, std::ofstream &output_file);


void FuncionSubcadenas(std::vector<Cadena *> &cadenas, std::ofstream &output_file);
void FuncionSubsecuencias(std::vector<Cadena *> &cadenas, std::ofstream &output_file);