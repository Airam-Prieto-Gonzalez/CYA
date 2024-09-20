// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Cadenas y lenguajes
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/09/2024

// Archivo Alfabeto.h:  declaración de los métodos de la clase Alfabeto.
//                              Contiene la declaración de los métodos de la
//                              clase Alfabeto.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/09/2024 - Creación (primera versión) del código

#pragma once

#include <iostream>
#include <string>
#include <unordered_set>

class Alfabeto {
 public:
    Alfabeto();
    Alfabeto(const std::string &alfabeto);
    ~Alfabeto();

    const std::unordered_set<char> &alfabeto() const;

    void insertar(const char &caracter);
    // void borrar(const char &caracter);
    // bool pertenece(const char &caracter) const;
 private:
    std::unordered_set<char> alfabeto_;
};