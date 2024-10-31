#include "../lib/Producciones.h"

void Producciones::InsertarProduccion(const std::string &kClave,
                                      const Simbolos &kValor) {
  // Si la clave ya existe, no inserto la producción
  for (const auto &produccion : producciones_) {
    if (produccion.first == kClave &&
        produccion.second.getSimbolos() == kValor.getSimbolos()) {
      return;
    }
  }
  producciones_.insert(std::pair<std::string, Simbolos>(kClave, kValor));
}

void Producciones::EliminarProduccion(const std::string &kClave,
                                      const Simbolos &kValor) {
  for (auto produccion : producciones_) {
    if (produccion.first == kClave &&
        produccion.second.getSimbolos() == kValor.getSimbolos()) {
      auto it = producciones_.find(produccion.first);
      producciones_.erase(it);
      break;
    }
  }
}

std::ostream &operator<<(std::ostream &os, const Producciones &producciones) {
  os << "\tProducciones: " << std::endl;
  for (const auto &produccion : producciones.producciones_) {
    os << "\t\t" << produccion.first << " -> " << produccion.second;
  }
  return os;
}