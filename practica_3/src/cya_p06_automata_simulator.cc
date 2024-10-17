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
//                                          Contiene la función main que se encarga de leer los ficheros de entrada
//                                          y de salida, y de llamar a las funciones necesarias para la creación y simulación de un autómata finito.
//                                          También se encarga de imprimir por pantalla el autómata y de comprobar si una cadena es aceptada o rechazada
//                                          por el autómata.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 17/10/2024 - Creación (primera versión) del código

#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <sstream>

#include "../lib/Automata.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        if (argc == 2 && std::string(argv[1]) == "--help") {
            std::ifstream help_file;
            help_file.open("files/help.txt");
            if (!help_file.is_open()) {
                std::cerr << "Error: No se ha podido abrir el fichero de ayuda." << std::endl;
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
            std::cerr << "Uso: " << argv[0] << " <fichero_FA> <fichero_entrada>" << std::endl;
            std::cerr << "Use --help para más información" << std::endl;
            return 1;
        }
    }
    std::ifstream input_FA;
    input_FA.open(argv[1]);
    if (!input_FA.is_open()) {
        std::cerr << "Error: No se ha podido abrir el fichero de entrada." << std::endl;
        return 1;
    }
    Automata automata(input_FA);
    automata.ImprimeAutomata();
    input_FA.close();

    std::ifstream input_cadena;
    input_cadena.open(argv[2]);
    if (!input_cadena.is_open()) {
        std::cerr << "Error: No se ha podido abrir el fichero de entrada." << std::endl;
        return 1;
    }
    std::cout << "\n\nANALIZANDO CADENAS" << std::endl;
    std::string cadena{};
    std::set<Estado> estados_actuales;
    Estado estado_inicial = automata.getEstadoInicial();
    estados_actuales.insert(estado_inicial);
    while (getline(input_cadena, cadena)) {
        std::cout << cadena;
        if (automata.CombruebaCadena(cadena)) {
            if (automata.IteraCadena(cadena, estados_actuales)) {
                std::cout << " --- Accepted" << std::endl;
            } else {
                std::cout << " --- Rejected" << std::endl;
            }
        } else {
            std::cout << " --- invalid" << std::endl;
        }
    }
    input_cadena.close();
    return 0;
}