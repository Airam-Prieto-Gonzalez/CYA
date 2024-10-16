# include "../lib/Alfabeto.h"

Alfabeto::Alfabeto () {}

Alfabeto::Alfabeto (std::string &alfabeto) {
    for (char &c : alfabeto) {
        alfabeto_.insert(c);
    }
}

Alfabeto::~Alfabeto () {
    alfabeto_.clear();
}