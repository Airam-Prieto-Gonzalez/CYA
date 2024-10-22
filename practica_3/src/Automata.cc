// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulador de autómatas finitos
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/10/2024

// Archivo Automata.cc:     Implementación de la clase Automata.
//                          Contiene la implementación de los métodos de la
//                          clase Automata que representan un autómata finito.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/10/2024 - Creación (primera versión) del código

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

#include "../lib/Automata.h"

Automata::Automata(std::ifstream &input_file) {
  std::string line{};
  std::getline(input_file, line);
  alfabeto_ = Alfabeto(line);
  std::getline(input_file, line);
  int num_estados = std::stoi(line);
  int inicial;
  std::getline(input_file, line);
  inicial = std::stoi(line);
  for (int i = 0; i < num_estados; i++) {
    std::getline(input_file, line);
    Estado estado(line);
    for (const auto &transicion : estado.getMapTransiciones()) {
      if (alfabeto_.getAlfabeto().find(transicion.first) == alfabeto_.getAlfabeto().end()) {
        if (transicion.first != '&') {
          std::cerr << "Las trasciciones del estado " << estado.getId() << " son incorrectas, abortando..." << std::endl;
          exit(-1);
        }
      }
    }
    if (estado.getAceptacion()) {
      estados_aceptacion_.insert(estado.getId());
    }
    if (estado.getId() == inicial) {
      estado_inicial_ = estado;
    }
    estados_.insert({estado.getId(), estado});
  }
  bool is_dfa = true;
  for (const auto& estado : estados_) {
    if (estado.second.getMapTransiciones().size() != alfabeto_.getAlfabeto().size()) {
      is_dfa = false;
    }
  }
  if (is_dfa) {
    std::cout << "This automata is a DFA" << std::endl;
    
  } else {
    std::cout << "This automata is not a DFA" << std::endl;
  }
}

Automata::~Automata() { alfabeto_.getAlfabeto().clear(); }

void Automata::ImprimeAutomata() {
  std::cout << "Alfabeto: ";
  for (const char &c : alfabeto_.getAlfabeto()) {
    std::cout << c << " ";
  }
  std::cout << std::endl;
  std::cout << "Estado inicial: " << estado_inicial_.getId() << std::endl;
  for (const auto &estado : estados_) {
    std::cout << "Estado: " << estado.first << std::endl;
    std::cout << "\tAceptacion: " << estado.second.getAceptacion() << std::endl;
    std::cout << "\tTransiciones: " << std::endl;
    for (const auto &transicion : estado.second.getMapTransiciones()) {
      std::cout << "\t\t";
      std::cout << transicion.first << " -> " << transicion.second << std::endl;
    }
  }
  std::cout << "Estados de aceptacion: ";
  for (const int &estado : estados_aceptacion_) {
    std::cout << estado << " ";
  }
  std::cout << std::endl;
}

bool Automata::CombruebaCadena(std::string &cadena) {
  for (const char &c : cadena) {
    if (c == '&') {
      return true;
    }
    if (alfabeto_.getAlfabeto().find(c) == alfabeto_.getAlfabeto().end()) {
      return false;
    }
    return true;
  }
  return false;
}

void Automata::EpsilonClausura(std::set<Estado> &estados_actuales) const {
  for (const Estado &estado : estados_actuales) {
    for (const auto &transicion : estado.getMapTransiciones()) {
      if (transicion.first == '&') {
        estados_actuales.insert(estados_.at(transicion.second));
      }
    }
  }
}

bool Automata::IteraCadena(std::string &cadena,
                           std::set<Estado> &estados_actuales,
                           int iteration) const {
  EpsilonClausura(estados_actuales);
  if (iteration == cadena.size() || cadena == "&") {
    for (const Estado &estado : estados_actuales) {
      if (estados_aceptacion_.find(estado.getId()) != estados_aceptacion_.end()) {
        return true;
      }
      return false;
    }
  } else {
    std::set<Estado> nuevos_estados;
    for (const Estado &estado : estados_actuales) {
      for (const auto &transicion : estado.getMapTransiciones()) {
        if (transicion.first == cadena[iteration]) {
          nuevos_estados.insert(estados_.at(transicion.second));
        }
      }
    }
    return IteraCadena(cadena, nuevos_estados, iteration + 1);
  }
}