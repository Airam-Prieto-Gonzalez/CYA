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
    // Abro el fichero con las cadenas a comprobar
    std::ifstream input_cadena;
    input_cadena.open(argv[2]);
    if (!input_cadena.is_open()) {
        std::cerr << "Error: No se ha podido abrir el fichero de entrada." << std::endl;
        return 1;
    } else {
        std::string cadena{};
        while (getline(input_cadena, cadena)) {
            if (automata.CombruebaCadena(cadena)) {
                // La cadena es del alfabeto del autómata, se comprueba si es aceptada
                std::set<Estado> estados_actuales;
                estados_actuales.insert(*(automata.getEstadoInicial()));
                if (automata.IteraCadena(cadena, estados_actuales)) {
                    // La cadena es aceptada por el autómata
                } else {
                    // La cadena no es aceptada por el autómata
                }
            } else {
                // La cadena no es del alfabero del autómata
            }
        }
        input_cadena.close();
    }

    return 0;
}