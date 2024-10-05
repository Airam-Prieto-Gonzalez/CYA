#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <regex>

#include "../lib/CodeAnalyser.h"

bool CodeAnalyser::get_main() const {
    return exist_main_;
}

std::map<int, std::string> CodeAnalyser::get_variables_int() const {
    return variables_int_;
}

std::map<int, std::string> CodeAnalyser::get_variables_double() const {
    return variables_double_;
}

std::map<std::string, std::set<int>> CodeAnalyser::get_loops() const {
    return loops_;
}

std::map<int, std::string> CodeAnalyser::get_monoline_comments() const {
    return monoline_comments_;
}

std::map<std::pair<int,int>, std::string> CodeAnalyser::get_multiline_comments() const {
    return multiline_comments_;
}

void CodeAnalyser::set_main() {
    exist_main_ = true;
}

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

void CodeAnalyser::set_multiline_comment(std::pair<int,int> lines, std::string comment) {
    multiline_comments_[lines] = comment;
}

void CodeAnalyser::AnalyseCode(std::ifstream &input_file) {
    std::string line;
    std::regex main_regex("int main\\(.*\\) \\{");
    std::regex variable_int_regex("int .*;");
    std::regex variable_double_regex("double .*");
    std::regex for_regex("for \\(.*\\)");
    std::regex while_regex("while \\(.*\\)");
    std::regex monoline_comment_regex("//.*");
    std::regex multiline_comment_start_regex("\\/\\*");
    std::regex multiline_comment_end_regex("\\*\\/");
    int line_number = 1;
    while(getline(input_file, line)) {
        if (std::regex_search(line, multiline_comment_start_regex)) {
            int start_line = line_number;
            int end_line = start_line;
            std::string comment{line + "\n"};
            while(getline(input_file, line)) {
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
        if(std::regex_match(line, main_regex)) {
            set_main();
        }
        if (std::regex_search(line, while_regex)) {
            set_loop("while", line_number);
        }
        if (std::regex_search(line, for_regex)) {
            set_loop("for", line_number);
        } else if(std::regex_search(line, variable_int_regex)) {
            set_variable_int(line_number, line);
        } else if(std::regex_search(line, variable_double_regex)) {
            set_variable_double(line_number, line);
        }
        if(std::regex_search(line, monoline_comment_regex)) {
            set_monoline_comment(line_number, line);
        }
        line_number++;
    }
}

void CodeAnalyser::PrintAnalysis(std::ofstream &output_file) {
    output_file << "Main: " << get_main() << std::endl;
    output_file << "Variables int: " << std::endl;
    for(auto &variable : get_variables_int()) {
        output_file << "Line: " << variable.first << " Variable: " << variable.second << std::endl;
    }
    output_file << "Variables double: " << std::endl;
    for(auto &variable : get_variables_double()) {
        output_file << "Line: " << variable.first << " Variable: " << variable.second << std::endl;
    }
    output_file << "Loops: " << std::endl;
    for(auto &loop : get_loops()) {
        output_file << "Loop: " << loop.first << " Lines: ";
        for(auto &line : loop.second) {
            output_file << line << " ";
        }
        output_file << std::endl;
    }
    output_file << "Monoline comments: " << std::endl;
    for(auto &comment : get_monoline_comments()) {
        output_file << "Line: " << comment.first << " Comment: " << comment.second << std::endl;
    }
    output_file << "Multiline comments: " << std::endl;
    for(auto &comment : get_multiline_comments()) {
        output_file << "Lines: " << comment.first.first << " - " << comment.first.second << " Comment: " << std::endl << std::endl << comment.second << std::endl;
    }
}