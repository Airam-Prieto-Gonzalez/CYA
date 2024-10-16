#pragma once

#include <iostream>
#include <fstream>
#include <set>

class Alfabeto {
 public:
    Alfabeto ();
    Alfabeto (std::string &alfabeto);
    ~Alfabeto ();

    std::set<char> &getAlfabeto () {return alfabeto_;};

 private:
 	std::set<char> alfabeto_;
};