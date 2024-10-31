for (auto &produccion : producciones_.getProducciones()) {
            // Por cada producción
            std::string conjunto_de_simbolos{*produccion.second.getSimbolos().begin()};
            if (conjunto_de_simbolos.size() >= 2) {
                // Si esta tiene 2 o más símbolos
                for (int i = 0; i < conjunto_de_simbolos.size(); i++) {
                    // Analizamos cada símbolo de la producción
                    std::string simbolo{conjunto_de_simbolos[i]};
                    if (terminales_.ExisteSimbolo(simbolo)) {
                        // Si es un terminal creamos un no terminal que lo genere
                        std::string no_terminal{"C_" + simbolo};
                        if (!no_terminales_.ExisteSimbolo(no_terminal)) {
                            // Si no existe lo añadimos a los no terminales y creamos la producción
                            no_terminales_.InsertarSimbolo(no_terminal);
                            Simbolos simbolos_terminales;
                            simbolos_terminales.InsertarSimbolo(simbolo);
                            producciones_.InsertarProduccion(no_terminal, simbolos_terminales);
                        }
                        produccion.second.SustituirSimbolo(simbolo, no_terminal);
                    }
                }
            }
        }