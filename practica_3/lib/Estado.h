#pragma once

#include <iostream>
#include <map>
#include <string>
#include <sstream>

class Estado {
 public:
    Estado (std::string &data);
    ~Estado ();

    int getId () const {return id_;};
    bool getAceptacion () const {return aceptacion_;};
    int getTransiciones () const {return transiciones_;};
    const std::multimap<char, int> &getMapTransiciones () const {return map_transiciones_;};

 private:
    int id_;
    bool aceptacion_;
    int transiciones_;
    std::multimap<char, int> map_transiciones_;
};