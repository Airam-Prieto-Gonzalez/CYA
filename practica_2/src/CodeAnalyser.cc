// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 3º
// Práctica 2: Cadenas y lenguajes
// Autor: Airam Prieto González
// Correo: alu0101546377@ull.edu.es
// Fecha: 05/10/2024

// Archivo CodeAnalyser.cc:     Implementación de la clase CodeAnalyser.
//                              Contiene la implementación de los métodos de la
//                              clase CodeAnalyser que analizan un archivo de
//                              texto y almacenan información relevante en
//                              atributos de la clase.

// Referencias:
// Enlaces de interés:
// Historial de revisiones
// 4/10/2024 - Creación (primera versión) del código

#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <string>

#include "../lib/CodeAnalyser.h"

const std::string &CodeAnalyser::get_filename() const { return filename_; }

bool CodeAnalyser::get_main() const { return exist_main_; }

const std::map<int, std::string> &CodeAnalyser::get_variables_int() const {
  return variables_int_;
}

const std::map<int, std::string> &CodeAnalyser::get_variables_double() const {
  return variables_double_;
}

const std::map<std::string, std::set<int>> &CodeAnalyser::get_loops() const {
  return loops_;
}

const std::map<int, std::string> &CodeAnalyser::get_monoline_comments() const {
  return monoline_comments_;
}

const std::map<std::pair<int, int>, std::string> &
CodeAnalyser::get_multiline_comments() const {
  return multiline_comments_;
}

const std::map<int, std::string> &CodeAnalyser::get_return() const {
  return return_;
}

void CodeAnalyser::set_main() { exist_main_ = true; }

void CodeAnalyser::set_variable_int(int line, std::string variable) {
  variables_int_[line] = variable;
}

void CodeAnalyser::set_variable_double(int line, std::string variable) {
  variables_double_[line] = variable;
}

void CodeAnalyser::set_loop(std::string loop, int line) {
  loops_[loop].insert(line);
}

void CodeAnalyser::set_monoline_comment(int line, std::string comment) {
  monoline_comments_[line] = comment;
}

void CodeAnalyser::set_multiline_comment(std::pair<int, int> lines,
                                         std::string comment) {
  multiline_comments_[lines] = comment;
}

void CodeAnalyser::set_filename(std::string filename) { filename_ = filename; }

void CodeAnalyser::set_return(int line, std::string return_statement) {
  return_[line] = return_statement;
}

void CodeAnalyser::AnalyseCode(std::string &input_file_name) {
  std::ifstream input_file{input_file_name};
  if (!input_file.is_open()) {
    std::cout << "/// Error: No se ha podido abrir el fichero de entrada."
              << std::endl;
    return;
  }
  set_filename(input_file_name);
  std::string line;
  std::regex main_regex("int main\\(.*\\) \\{");
  std::regex variable_int_regex("int .*;");
  std::regex variable_double_regex("double .*");
  std::regex for_regex("for \\(.*\\)");
  std::regex while_regex("while \\(.*\\)");
  std::regex monoline_comment_regex("//.*");
  std::regex multiline_comment_start_regex("\\/\\*");
  std::regex multiline_comment_end_regex("\\*\\/");
  std::regex return_regex("return .*;");
  int line_number = 1;
  while (getline(input_file, line)) {
    if (std::regex_search(line, multiline_comment_start_regex)) {
      int start_line = line_number;
      int end_line = start_line;
      std::string comment{line + "\n"};
      while (getline(input_file, line)) {
        ++end_line;
        if (std::regex_search(line, multiline_comment_end_regex)) {
          comment += line;
          std::pair<int, int> lines(start_line, end_line);
          set_multiline_comment(lines, comment);
          break;
        }
        comment += line + "\n";
      }
    }
    if (std::regex_match(line, main_regex)) {
      set_main();
    }
    if (std::regex_search(line, while_regex)) {
      set_loop("while", line_number);
    }
    if (std::regex_search(line, for_regex)) {
      set_loop("for", line_number);
    } else if (std::regex_search(line, variable_int_regex)) {
      line = line.substr(line.find("int") + 4, line.size());
      set_variable_int(line_number, line);
    } else if (std::regex_search(line, variable_double_regex)) {
      line = line.substr(line.find("double") + 7, line.size());
      set_variable_double(line_number, line);
    }
    if (std::regex_search(line, monoline_comment_regex)) {
      set_monoline_comment(line_number, line);
    }
    if (std::regex_search(line, return_regex)) {
      line = line.substr(line.find("return") + 7, line.size());
      set_return(line_number, line);
    }
    line_number++;
  }
  input_file.close();
}

void CodeAnalyser::PrintAnalysis(std::ofstream &output_file) {
  output_file << "PROGRAM: " << get_filename() << std::endl;
  output_file << "DESCRIPTION:" << std::endl;
  if (get_multiline_comments().size() > 0) {
    output_file << get_multiline_comments().begin()->second << std::endl;
  }
  output_file << std::endl;
  output_file << "VARIABLES:" << std::endl;
  for (auto variable : get_variables_int()) {
    output_file << "[LINE " << variable.first << "] INT: " << variable.second
                << std::endl;
  }
  output_file << std::endl;
  for (auto variable : get_variables_double()) {
    output_file << "[LINE " << variable.first << "] DOUBLE: " << variable.second
                << std::endl;
  }
  output_file << std::endl;
  output_file << "STATEMENTS:" << std::endl;
  for (auto loop : get_loops()) {
    for (auto line : loop.second) {
      output_file << "[LINE " << line << "] LOOP: " << loop.first << std::endl;
    }
  }
  output_file << std::endl;
  output_file << "MAIN: " << std::endl;
  if (get_main()) {
    output_file << "True" << std::endl;
  } else {
    output_file << "False" << std::endl;
  }
  output_file << std::endl;
  output_file << "COMMENTS:" << std::endl;
  for (auto comment : get_multiline_comments()) {
    if (comment.first.first == 1) {
      output_file << "[LINES " << comment.first.first << " - "
                  << comment.first.second << "] COMMENT: DESCRIPTION"
                  << std::endl;
    } else {
      output_file << "[LINES " << comment.first.first << " - "
                  << comment.first.second << "] COMMENT: " << comment.second
                  << std::endl;
    }
  }
  output_file << std::endl;
  for (auto comment : get_monoline_comments()) {
    output_file << "[LINE " << comment.first << "] COMMENT: " << comment.second
                << std::endl;
  }
  output_file << std::endl;
  output_file << "RETURN STATEMENTS:" << std::endl;
  for (auto return_statement : get_return()) {
    output_file << "[LINE " << return_statement.first
                << "] RETURN: " << return_statement.second << std::endl;
  }
  output_file << std::endl;
}