#include "tokenizer.hpp"
#include <sstream>
#include <algorithm>
#include <iostream>

std::vector<Token> tokenize(const std::string& input) {
    std::vector<Token> tokens;
    std::istringstream iss(input);
    std::string word;

    while (iss >> word) {
        if (word == "add.slide.fr") tokens.push_back({ TokenType::ADD_SLIDE_FR, "" });
        else if (word == "add.slide.mid") tokens.push_back({ TokenType::ADD_SLIDE_MID, "" });
        else if (word == "add.slide.back") tokens.push_back({ TokenType::ADD_SLIDE_BACK, "" });
        else if (word == "del.slide") tokens.push_back({ TokenType::DEL_SLIDE, "" });
        else if (word == "fetch") tokens.push_back({ TokenType::FETCH, "" });
        else if (word == "sw") tokens.push_back({ TokenType::SWITCH, "" });
        else if (word == "reorder") tokens.push_back({ TokenType::REORDER, "" });

        else if (word == "add.txt") tokens.push_back({ TokenType::ADD_TEXT, "" });
        else if (word == "del.txt") tokens.push_back({ TokenType::DEL_TEXT, "" });
        else if (word == "font.txt") tokens.push_back({ TokenType::FONT_TEXT, "" });
        else if (word == "color.txt") tokens.push_back({ TokenType::COLOR_TEXT, "" });
        else if (word == "bg.txt") tokens.push_back({ TokenType::BG_TEXT, "" });
        else if (word == "size.txt") tokens.push_back({ TokenType::SIZE_TEXT, "" });

        else if (word == "add.img") tokens.push_back({ TokenType::ADD_IMAGE, "" });
        else if (word == "del.img") tokens.push_back({ TokenType::DEL_IMAGE, "" });
        else if (word == "add.shape") tokens.push_back({ TokenType::ADD_SHAPE, "" });
        else if (word == "del.shape") tokens.push_back({ TokenType::DEL_SHAPE, "" });
        else if (word == "color.shape") tokens.push_back({ TokenType::COLOR_SHAPE, "" });
        else if (word == "size.shape") tokens.push_back({ TokenType::SIZE_SHAPE, "" });

        else if (word == "add.trans") tokens.push_back({ TokenType::ADD_TRANS, "" });
        else if (word == "add.anim") tokens.push_back({ TokenType::ADD_ANIM, "" });

        else tokens.push_back({ TokenType::ARG, word });
    }

    return tokens;
}