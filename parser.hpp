#ifndef PARSER_HPP
#define PARSER_HPP

#include "tokenizer.hpp"
#include <string>
#include <vector>

struct Command {
    std::string name;              // internal command name, e.g. "add_slide_front"
    std::vector<std::string> args; 
};

Command parse(const std::vector<Token>& tokens);

#endif 
