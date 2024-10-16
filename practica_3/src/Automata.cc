#include "../lib/Automata.h"

Automata::Automata (std::ifstream &input_file) {
    std::string line{};
    std::getline(input_file, line);
    alfabeto_ = Alfabeto(line);
    std::getline(input_file, line);
    int num_estados = std::stoi(line);
    int incial;
    std::getline(input_file, line);
    incial = std::stoi(line);
    for (int i = 0; i < num_estados; i++) {
        std::getline(input_file, line);
        Estado estado(line);
        if (estado.getAceptacion()) {
            estados_aceptacion_.insert(estado.getId());
        }
        if (estado.getId() == incial) {
            estado_inicial_ = &estado;
        }
        estados_.insert({estado.getId(), estado});
    }

}

Automata::~Automata () {
    alfabeto_.getAlfabeto().clear();
}

void Automata::ImprimeAutomata () {
    std::cout << "Alfabeto: ";
    for (const char &c : alfabeto_.getAlfabeto()) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    std::cout << "Estado inicial: " << estado_inicial_->getId() << std::endl;
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

bool Automata::CombruebaCadena (std::string &cadena) {
    for (const char &c : cadena) {
        if (alfabeto_.getAlfabeto().find(c) == alfabeto_.getAlfabeto().end()) {
            return false;
        }
    }
}

bool Automata::IteraCadena (std::string &cadena, std::set<Estado> &estados_actuales, int iteration) const {
    
    return false;
}

