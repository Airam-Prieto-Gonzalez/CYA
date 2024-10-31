
#include "../lib/Simbolos.h"

Simbolos::Simbolos(const std::string &simbolos) {
  for (int i = 0; i < simbolos.size(); i++) {
    std::string simbolo{simbolos[i]};
    simbolos_.emplace_back(simbolo);
  }
}

void Simbolos::InsertarSimbolo(std::string &simbolos) {
  simbolos_.emplace_back(simbolos);
}

void Simbolos::SustituirSimbolo(std::string &simbolo_antiguo,
                                std::string &nuevo_simbolo) {
  for (int i = 0; i < simbolos_.size(); i++) {
    if (simbolos_[i] == simbolo_antiguo) {
      simbolos_[i] = nuevo_simbolo;
    }
  }
}

bool Simbolos::ExisteSimbolo(std::string simbolo) const {
  for (const auto &simb : simbolos_) {
    if (simb == simbolo) {
      return true;
    }
  }
  return false;
}

void Simbolos::EliminarSimbolo(std::string &simbolo) {
  for (auto it = simbolos_.begin(); it != simbolos_.end(); ++it) {
    if (*it == simbolo) {
      simbolos_.erase(it);
      break;
    }
  }
}

Simbolos &Simbolos::operator=(const Simbolos &simbolos) {
  if (this != &simbolos) {
    simbolos_ = simbolos.simbolos_;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Simbolos &simbolos) {
  os << "\t";
  for (const auto &simbolo : simbolos.simbolos_) {
    os << simbolo << " ";
  }
  os << std::endl;
  return os;
}