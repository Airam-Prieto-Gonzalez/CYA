#pragma once

#include <iostream>
#include <fstream>

#include "Estado.h"
#include "Alfabeto.h"

class Automata {
 public:
	Automata (std::ifstream &input_file);
	~Automata ();
	Estado *getEstadoInicial () {return estado_inicial_;};
	void ImprimeAutomata ();

	bool CombruebaCadena (std::string &cadena);
	bool IteraCadena (std::string &cadena, std::set<Estado> &estados_actuales, int iteration = 0) const;


 private:
	Alfabeto alfabeto_;
	Estado *estado_inicial_;
	std::map<int, Estado> estados_;
	std::set<int> estados_aceptacion_;

};