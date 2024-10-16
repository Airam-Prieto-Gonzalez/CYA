#include "../lib/Estado.h"

Estado::Estado(std::string &line) {
    std::stringstream ss(line);
    ss >> id_;
    ss >> aceptacion_;
    ss >> transiciones_;
    for (int i = 0; i < transiciones_; i++) {
        char c;
        int id;
        ss >> c;
        ss >> id;
        map_transiciones_.insert({c, id});
    }
}

Estado::~Estado() {
    map_transiciones_.clear();
}
