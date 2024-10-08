// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Cadenas y lenguajes
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 05/10/2024

// Archivo CodeAnalyser.h:     Declaración de la clase CodeAnalyser.
//                             Contiene la declaración de los atributos y métodos de la clase CodeAnalyser
//                             que analizan un archivo de texto y almacenan información relevante
//                             en atributos de la clase.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 4/10/2024 - Creación (primera versión) del código

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

# pragma once

class CodeAnalyser {
    public:
        /// @brief Constructor por defecto
        CodeAnalyser() {}
        /// @brief Destructor por defecto
        ~CodeAnalyser() {}

        /// @brief Getter del atributo filename
        /// @return Referencia constante del atributo filename
        const std::string& get_filename() const;
        /// @brief Getter del atributo main
        /// @return Un booleano que será "true" si el programa detectó una funcion principal.
        bool get_main() const;
        /// @brief Getter del atributo variables_int_
        /// @return Referencia constante del atributo variables_int_
        const std::map<int, std::string>& get_variables_int() const;
        /// @brief Getter del atributo variables_double_
        /// @return Referencia constante del atributo variables_double_
        const std::map<int, std::string>& get_variables_double() const;
        /// @brief Getter del atributo loops_
        /// @return Referencia constante del atributo loops_
        const std::map<std::string, std::set<int>>& get_loops() const;
        /// @brief Getter del atributo monoline_comments_
        /// @return Referencia constante del atributo monoline_comments_
        const std::map<int, std::string>& get_monoline_comments() const;
        /// @brief Getter del atributo multiline_comments_
        /// @return Referencia constante del atributo multiline_comments_
        const std::map<std::pair<int,int>, std::string>& get_multiline_comments() const;
        /// @brief Getter del atributo return_
        /// @return Referencia constante del atributo return_
        const std::map<int, std::string>& get_return() const;

        /// @brief Setter del atributo exist_main_
        void set_main();
        /// @brief Setter del atributo variables_int_
        /// @param line Clave del std::map variables_int_
        /// @param variable Valor almacenado en la clave line
        void set_variable_int(int line, std::string variable);
        /// @brief  Setter del atributo variables_double_
        /// @param line Clave del std::map variables_double_
        /// @param variable Valor almacenado en la clave line
        void set_variable_double(int line, std::string variable);
        /// @brief Setter del atributo loops_
        /// @param loop Clave del std::map loops_
        /// @param line Valor almacenado en la clave loop
        void set_loop(std::string loop, int line);
        /// @brief Setter del atributo monoline_comments_
        /// @param line Clave del std::map monoline_comments_
        /// @param comment Valor almacenado en la clave line
        void set_monoline_comment(int line, std::string comment);
        /// @brief Setter del atributo multiline_comments_
        /// @param lines Clave del std::map multiline_comments_
        /// @param comment Valor almacenado en la clave lines
        void set_multiline_comment(std::pair<int,int> lines, std::string comment);
        /// @brief Setter del atributo filename_
        /// @param filename Valor que se le asignará al atributo filename_
        void set_filename(std::string filename);
        /// @brief Setter del atributo return_
        /// @param lines Clave del std::map return_
        /// @param comment Valor almacenado en la clave lines
        void set_return(int line, std::string return_statement);

        /// @brief Analiza el código de un archivo de texto
        /// @param output_file Archivo de texto que contiene el código a analizar
        void AnalyseCode(std::string &input_file_name);
        /// @brief Imprime el análisis del código en un archivo de texto
        /// @param output_file Archivo de texto donde se imprimirá el análisis
        void PrintAnalysis(std::ofstream &output_file);

    private:
        std::string filename_;
        bool exist_main_{false};
        std::map<int, std::string> variables_int_;
        std::map<int, std::string> variables_double_;
        std::map<std::string, std::set<int>> loops_;
        std::map<int, std::string> monoline_comments_;
        std::map<std::pair<int,int>, std::string> multiline_comments_;
        std::map<int, std::string> return_;
};