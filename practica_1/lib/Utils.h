// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Cadenas y lenguajes
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/09/2024

// Archivo cya-P02-strings.cc:  programa cliente.
//                              Contiene la función main del proyecto que usa las clases X e Y
//                              para ... (indicar brevemente el objetivo)

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/09/2024 - Creación (primera versión) del código

#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "../lib/Cadena.h"

void FuncionAlfabeto(std::vector<Cadena*>& cadenas, std::ofstream& output_file);
void FuncionLongitud(std::vector<Cadena*>& cadenas, std::ofstream& output_file);
void FuncionInversa(std::vector<Cadena*>& cadenas, std::ofstream& output_file);
void FuncionPrefijos(std::vector<Cadena*>& cadenas, std::ofstream& output_file);
void FuncionSufijos(std::vector<Cadena*>& cadenas, std::ofstream& output_file);