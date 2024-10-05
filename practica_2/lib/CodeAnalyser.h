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

        bool get_main() const;
        std::map<int, std::string> get_variables_int() const;
        std::map<int, std::string> get_variables_double() const;
        std::map<std::string, std::set<int>> get_loops() const;
        std::map<int, std::string> get_monoline_comments() const;
        std::map<std::pair<int,int>, std::string> get_multiline_comments() const;

        void set_main();
        void set_variable_int(int line, std::string variable);
        void set_variable_double(int line, std::string variable);
        void set_loop(std::string loop, int line);
        void set_monoline_comment(int line, std::string comment);
        void set_multiline_comment(std::pair<int,int> lines, std::string comment);

        void AnalyseCode(std::ifstream &output_file);
        void PrintAnalysis(std::ofstream &output_file);

    private:
        bool exist_main_{false};
        std::map<int, std::string> variables_int_;
        std::map<int, std::string> variables_double_;
        std::map<std::string, std::set<int>> loops_;
        std::map<int, std::string> monoline_comments_;
        std::map<std::pair<int,int>, std::string> multiline_comments_;
};