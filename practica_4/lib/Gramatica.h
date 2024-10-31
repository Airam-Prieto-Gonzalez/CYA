#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Simbolos.h"
#include "Producciones.h"

class Gramatica {
 public:
    Gramatica() = default;
    Gramatica(const Simbolos &kTerminales, 
              const Simbolos &kNo_terminales, 
              const Producciones &kProducciones, 
              const std::string &kSimbolo_inicial) : terminales_(kTerminales), 
                                                     no_terminales_(kNo_terminales), 
                                                     producciones_(kProducciones), 
                                                     simbolo_inicial_(kSimbolo_inicial) {}

    bool ProduccionesVacias () {
        for (const auto &produccion : producciones_.getProducciones()) {
            if (produccion.second.ExisteSimbolo("&")) {
                return true;
            }
        }
        return false;
    }
    bool ProduccionesUnitarias () {
        for (const auto &produccion : producciones_.getProducciones()) {
            if (produccion.second.getSimbolos().size() == 1 && no_terminales_.ExisteSimbolo(produccion.second.getSimbolos().begin()->c_str())) {
                return true;
            }
        }
        return false;
    }

    void InsertaProduccion(const std::string kClave, const Simbolos &kValor) {
        producciones_.InsertarProduccion(kClave, kValor);
    }
    void EliminaProduccion(const std::string kClave, const Simbolos &kValor) {
        producciones_.EliminarProduccion(kClave, kValor);
    }

    void FormaNormalChomsky() {
        std::cout << "\n\t\t\t/////////  Forma Normal de Chomsky  /////////\n\n";
        // Añadir las producciones de la forma A -> a
        for (auto &produccion : producciones_.getProducciones()) {
            // Por cada producción
            if (produccion.second.getSimbolos().size() >= 2) {
                // Si esta tiene 2 o más símbolos
                for (int i = 0; i < produccion.second.getSimbolos().size(); i++) {
                    std::string simbolo = produccion.second.getSimbolos()[i];
                    // Analizamos cada símbolo de la producción
                    if (terminales_.ExisteSimbolo(produccion.second.getSimbolos()[i])) {
                        std::string simbolo_nuevo = "C_" + produccion.second.getSimbolos()[i];
                        if (!no_terminales_.ExisteSimbolo(simbolo_nuevo)) {
                            no_terminales_.InsertarSimbolo(simbolo_nuevo);
                            Simbolos simbolos_terminales;
                            simbolos_terminales.InsertarSimbolo(simbolo);
                            producciones_.InsertarProduccion(simbolo_nuevo, simbolos_terminales);
                        }

                        produccion.second.SustituirSimbolo(simbolo, simbolo_nuevo);
                    }
                }
            }
        }
    }

    Simbolos getTerminales() const { return terminales_; }
    Simbolos getNoTerminales() const { return no_terminales_; }
    Producciones getProducciones() const { return producciones_; }

    friend std::ostream &operator<<(std::ostream &os, const Gramatica &gramatica) {
        os << "/// Gramática: " << std::endl;
        os << "\tTerminales: ";
        os << gramatica.terminales_;
        os << "\tNo Terminales: ";
        os << gramatica.no_terminales_;
        os << "\tSimbolo inicial: " << gramatica.simbolo_inicial_ << std::endl;
        os << "\tProducciones: " << std::endl;
        os << gramatica.producciones_;
        return os;
    }

 private:
    Simbolos terminales_;
    Simbolos no_terminales_;
    Producciones producciones_;
    std::string simbolo_inicial_;
};