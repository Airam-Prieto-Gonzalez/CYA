// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 11: Mínimo Árbol de Expansión Euclídeo
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 8/12/2024

// Archivo main.cc: Archivo principal del programa
// Contiene el punto de entrada al programa, que lee un conjunto de puntos de un
// fichero, calcula el árbol de expansión mínima y lo escribe por pantalla y en
// un fichero de salida

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 31/10/2024 - Creación (primera versión) del código

#include "../lib/PointSet.hh"
#include "../lib/PointTypes.hh"
#include "../lib/SubTree.hh"
#include "../lib/Utils.hh"

using namespace EMST;
using namespace CyA;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }
  // Si el usuario introduce un fichero de salida adicional, se crea en la carpeta files un fichero con el nombre introducido y la extensión .txt
  std::string output_file = "files/" + std::string(argv[1]) + ".txt";
  std::ofstream output(output_file);
  if (!output) {
    std::cerr << "Error creating output file " << output_file << std::endl;
    return 3;
  }
  point_vector points;
  if (!read_points(argv[1], points)) {
    std::cerr << "Error reading points from file " << argv[1] << std::endl;
    return 2;
  }

  point_set ps(points);
  ps.EMST();
  ps.write_tree(std::cout);
  std::cout << "Cost: " << ps.get_cost() << std::endl;
  // Se escribe el árbol en el fichero de salida, redirigiendo el flujo de salida al fichero

  std::streambuf* original_buffer = std::cout.rdbuf(); // Guardar el buffer original
  std::cout.rdbuf(output.rdbuf()); // Redirigir std::cout al archivo
  ps.write_tree(output);
  output << "Cost: " << ps.get_cost() << std::endl;
  // Restaurar std::cout al flujo estándar
  std::cout.rdbuf(original_buffer);
  // Cerrar el archivo
  output.close();
  return 0;
}