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

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "../lib/Cadena.h"
#include "../lib/Utils.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "/// Error: Ha introducido erróneamente los parámetros" << std::endl;
        return 1;
        // completar con las instrucciones del programa
    } else {
        // DECLARACIÓN DE VARIABLES DE USO GENERAL
        std::string filein{argv[1]};
        std::string fileout{argv[2]};
        std::string opcode{argv[3]};
        std::vector<Cadena*> cadenas;
        // APERTURA DE FICHEROS
        std::ifstream input_file{filein};
        std::ofstream output_file{fileout};
        // COMPROBACIÓN DE APERTURA DE FICHEROS
        if (!input_file.is_open()) {
            std::cout << "/// Error: No se ha podido abrir el fichero de entrada." << std::endl;
            return 1;
        }
        if (!output_file.is_open()) {
            std::cout << "/// Error: No se ha podido abrir el fichero de salida." << std::endl;
            return 1;
        }
        // LECTURA DE FICHERO DE ENTRADA
        std::string entrada;
        while (std::getline(input_file, entrada)) {
            std::stringstream linea{entrada};
            std::string cadena;
            std::string alfabeto;
            linea >> cadena >> alfabeto;
            cadenas.push_back(new Cadena(cadena, alfabeto));
        }
        // SELECCIÓN DE OPCIÓN Y EJECUCIÓN DE LA MISMA
        std::cout << "Opcion seleccionada: " << opcode << std::endl;
        if (opcode == "alfabeto") {
            FuncionAlfabeto(cadenas, output_file);
            std::cout << "/// Funcion alfabeto ejecutada con exito." << std::endl;
        } else if (opcode == "longitud") {
            FuncionLongitud(cadenas, output_file);
            std::cout << "/// Funcion longitud ejecutada con exito." << std::endl;
        } else if (opcode == "inversa") {
            FuncionInversa(cadenas, output_file);
            std::cout << "/// Funcion inversa ejecutada con exito." << std::endl;
        } else if (opcode == "prefijos") {
            FuncionPrefijos(cadenas, output_file);
            std::cout << "/// Funcion prefijos ejecutada con exito." << std::endl;
        } else if (opcode == "sufijos") {
            FuncionSufijos(cadenas, output_file);
            std::cout << "/// Funcion sufijos ejecutada con exito." << std::endl;
        } else {
            std::cout << "/// Opcion opcion introducida es desconocida." << std::endl;
            std::cout << "Abortando..." << std::endl;
        }
        // CIERRE DE FICHEROS
        input_file.close();
        output_file.close();
        // LIBERACIÓN DE MEMORIA
        for (int i = 0; i < cadenas.size(); ++i) {
            delete cadenas[i];
        }
    }
    return 0;
}
