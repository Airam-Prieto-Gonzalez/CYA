// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Cadenas y lenguajes
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 17/09/2024

// Archivo cya_p04_RegularExpression.cc:  programa cliente.
//                                        Contiene la implementación del
//                                        programa cliente que analiza un
//                                        archivo de texto y almacena
//                                        información relevante en un archivo de
//                                        salida.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 05/10/2024 - Creación (primera versión) del código

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "../lib/CodeAnalyser.h"

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::string param_1{argv[1]};
    if (argc == 2 && param_1 == "--help") {
      std::ifstream help_file{"files/CorrectUsage.txt"};
      if (help_file.is_open()) {
        std::string line;
        while (std::getline(help_file, line)) {
          std::cout << line << std::endl;
        }
      } else {
        std::cout << "/// Error: No se ha podido abrir el fichero de ayuda."
                  << std::endl;
        return 1;
      }
    } else {
      std::cout << "/// Error: Ha introducido erróneamente los parámetros"
                << std::endl;
      std::cout
          << "/// Pruebe a ejecutar el programa --help para mayor información"
          << std::endl;
    }
    return 1;
    // completar con las instrucciones del programa
  } else {
    // DECLARACIÓN DE VARIABLES DE USO GENERAL
    std::string filein{argv[1]};
    std::string fileout{argv[2]};
    // APERTURA DE FICHEROS
    std::ofstream output_file{fileout};
    // COMPROBACIÓN DE APERTURA DE FICHEROS
    if (!output_file.is_open()) {
      std::cout << "/// Error: No se ha podido abrir el fichero de salida."
                << std::endl;
      return 1;
    }
    // EJECUCIÓN DEL ANALISIS
    CodeAnalyser code_analyser;
    code_analyser.AnalyseCode(filein);
    code_analyser.PrintAnalysis(output_file);
    // CIERRE DE FICHEROS
    output_file.close();
    // LIBERACIÓN DE MEMORIA
  }
  return 0;
}
