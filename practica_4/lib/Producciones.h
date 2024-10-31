#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Simbolos.h"

class Producciones {
 public:
    Producciones() = default;
    
    void InsertarProduccion (const std::string &kClave, const Simbolos &kValor) {
        producciones_.insert(std::pair<std::string,Simbolos>(kClave,kValor));
    }
    void EliminarProduccion (const std::string &kClave, const Simbolos &kValor) {
        for (auto produccion : producciones_) {
            if (produccion.first == kClave && produccion.second.getSimbolos() == kValor.getSimbolos()) {
                auto it = producciones_.find(produccion.first);
                producciones_.erase(it);
                break;
            }
        }
    }
    std::multimap<std::string,Simbolos>& getProducciones() { return producciones_; }

    friend std::ostream &operator<<(std::ostream &os, const Producciones& producciones) {
        os << "\tProducciones: " << std::endl;
        for (const auto &produccion : producciones.producciones_) {
            os << "\t\t" << produccion.first << " -> " << produccion.second;
        }
        return os;
    }

 private:
    std::multimap<std::string,Simbolos> producciones_;
};