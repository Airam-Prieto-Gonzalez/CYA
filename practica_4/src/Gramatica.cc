#include "../lib/Gramatica.h"

bool Gramatica::ProduccionesVacias() {
  for (const auto &produccion : producciones_.getProducciones()) {
    if (produccion.second.ExisteSimbolo("&") &&
        produccion.first != simbolo_inicial_) {
      return true;
    }
  }
  return false;
}

bool Gramatica::ProduccionesUnitarias() {
  for (const auto &produccion : producciones_.getProducciones()) {
    if (produccion.second.getSimbolos().size() == 1 &&
        no_terminales_.ExisteSimbolo(
            produccion.second.getSimbolos().begin()->c_str())) {
      return true;
    }
  }
  return false;
}

void Gramatica::InsertaProduccion(const std::string kClave,
                                  const Simbolos &kValor) {
  producciones_.InsertarProduccion(kClave, kValor);
}
void Gramatica::EliminaProduccion(const std::string kClave,
                                  const Simbolos &kValor) {
  producciones_.EliminarProduccion(kClave, kValor);
}

void Gramatica::FormaNormalChomsky() {
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
            producciones_.InsertarProduccion(simbolo_nuevo,
                                             simbolos_terminales);
          }

          produccion.second.SustituirSimbolo(simbolo, simbolo_nuevo);
        }
      }
    }
  }
  int D_index = 0;
  for (auto &produccion : producciones_.getProducciones()) {
    if (produccion.second.getSimbolos().size() >= 3) {
      // // Calculamos el número de producciones que hay que añadir
      int m_producciones = produccion.second.getSimbolos().size() - 2;
      int num_simbolos = produccion.second.getSimbolos().size();
      // // Creo un string auxiliar para almacenar los símbolos que se van a
      // eliminar y una variable simbolos_nuevos para almacenar los nuevos
      // símbolos
      std::string aux_string_ultimo;
      std::string aux_string_penultimo;
      Simbolos simbolos_nuevos;
      // // Entro al bucle, cada iteración añade una producción de la forma D_i
      // -> XY y elimina los dos últimos símbolos de la producción para
      // sustituirlos por D_i
      for (int i = 0; i < m_producciones; i++) {
        // // Selecciono los dos últimos símbolos de la producción,
        // eliminandolos El primero
        aux_string_ultimo = produccion.second.getSimbolos()[num_simbolos - 1];
        produccion.second.EliminaUltimoSimbolo();
        // El segundo
        aux_string_penultimo =
            produccion.second.getSimbolos()[num_simbolos - 2];
        --num_simbolos;
        produccion.second.EliminaUltimoSimbolo();
        simbolos_nuevos.InsertarSimbolo(aux_string_penultimo);
        simbolos_nuevos.InsertarSimbolo(aux_string_ultimo);
        // // Creo el simbolo no terminal nuevo
        std::string simbolo_nuevo = "D_" + std::to_string(D_index);

        // // Añado el simbolo no terminal nuevo a la lista de no terminales
        if (!no_terminales_.ExisteSimbolo(simbolo_nuevo)) {
          no_terminales_.InsertarSimbolo(simbolo_nuevo);
        }

        // // Inserto el nuevo símbolo no terminal en su lugar
        produccion.second.InsertarSimbolo(simbolo_nuevo);
        // // Añado la producción D_i -> XY
        producciones_.InsertarProduccion(simbolo_nuevo, simbolos_nuevos);
        // // Limpio la lista de símbolos nuevos
        simbolos_nuevos.Clear();
        ++D_index;
      }
    }
  }
}

std::ostream &operator<<(std::ostream &os, const Gramatica &gramatica) {
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