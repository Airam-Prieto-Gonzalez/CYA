// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 6: Simulador de autómatas finitos
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/10/2024

// Archivo cya_p06_automata_simulator.cc:   Archivo principal de la práctica 6.
//                                          Contiene la función main que se
//                                          encarga de leer los ficheros de
//                                          entrada y de salida, y de llamar a
//                                          las funciones necesarias para la
//                                          creación y simulación de un autómata
//                                          finito. También se encarga de
//                                          imprimir por pantalla el autómata y
//                                          de comprobar si una cadena es
//                                          aceptada o rechazada por el
//                                          autómata.

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
#include <vector>

#include "../lib/Gramatica.h"

int main(int argc, char *argv[]) {
  if (argc != 3) {
    if (argc == 2 && std::string(argv[1]) == "--help") {
      std::ifstream help_file;
      help_file.open("files/help.txt");
      if (!help_file.is_open()) {
        std::cerr << "Error: No se ha podido abrir el fichero de ayuda."
                  << std::endl;
        return 1;
      } else {
        std::string line{};
        while (getline(help_file, line)) {
          std::cout << line << std::endl;
        }
      }
      return 0;
    } else {
      std::cerr << "Error: Número de argumentos incorrecto." << std::endl;
      std::cerr << "Uso: " << argv[0] << " <fichero_FA> <fichero_entrada>"
                << std::endl;
      std::cerr << "Use --help para más información" << std::endl;
      return 1;
    }
  }
  std::ifstream input_file;
  input_file.open(argv[1]);
  if (!input_file.is_open()) {
    std::cerr << "Error: No se ha podido abrir el fichero de entrada."
              << std::endl;
    return 1;
  }
  std::string line{};
  int num_terminales{}, num_no_terminales{}, num_producciones{};
  std::string simbolo_inicial{};
  Simbolos aux_simbolos;
  // Leo los simbolos terminales
  std::getline(input_file, line);
  num_terminales = std::stoi(line);
  std::string terminales_vector;
  for (int i = 0; i < num_terminales; i++) {
    std::getline(input_file, line);
    terminales_vector += line;
  }
  // Leo los simbolos no terminales
  std::getline(input_file, line);
  num_no_terminales = std::stoi(line);
  std::string no_terminales_vector;
  for (int i = 0; i < num_no_terminales; i++) {
    std::getline(input_file, line);
    if (i == 0) {
      simbolo_inicial = line;
    }
    no_terminales_vector += line;
  }
  // Leo las producciones
  std::getline(input_file, line);
  num_producciones = std::stoi(line);
  Producciones producciones;
  for (int i = 0; i < num_producciones; i++) {
    std::getline(input_file, line);
    std::istringstream ss(line);
    std::string clave;
    std::string valor;
    ss >> clave >> valor;
    Simbolos aux_simbolos(valor);
    producciones.InsertarProduccion(clave, aux_simbolos);
    aux_simbolos.Clear();
  }
  // Creo la gramática
  Simbolos terminales(terminales_vector);
  Simbolos no_terminales(no_terminales_vector);
  Gramatica gramatica(terminales, no_terminales, producciones, simbolo_inicial);
  std::cout << gramatica;
  if (gramatica.ProduccionesVacias() || gramatica.ProduccionesUnitarias()) {
    std::cout << "/// La gramática tiene producciones inválidas (son vacias o unitarias)." << std::endl;
    return 1;
  }
  std::cout << "/// La gramática no tiene producciones vacías ni unitarias." << std::endl;

  // PRUEBAS
  // gramatica.InsertaProduccion("S", "aA");
  // gramatica.InsertaProduccion("A", "b");
  // gramatica.EliminaProduccion("A", "b");
  // gramatica.EliminaProduccion("S", "aA");
  // gramatica.EliminaProduccion("S", "aXbX");
  // std::cout << gramatica;
  
  gramatica.FormaNormalChomsky();
  std::cout << gramatica;
  return 0;
}