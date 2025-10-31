#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <vector>

enum class TokenType {
    ADD_SLIDE_FR,
    ADD_SLIDE_MID,
    ADD_SLIDE_BACK,
    DEL_SLIDE,
    FETCH,
    SWITCH,
    REORDER,

    ADD_TEXT,
    DEL_TEXT,
    FONT_TEXT,
    COLOR_TEXT,
    BG_TEXT,
    SIZE_TEXT,

    ADD_IMAGE,
    DEL_IMAGE,
    ADD_SHAPE,
    DEL_SHAPE,
    COLOR_SHAPE,
    SIZE_SHAPE,

    ADD_TRANS,
    ADD_ANIM,

    ARG
};

struct Token {
    TokenType type;
    std::string value;
};

std::vector<Token> tokenize(const std::string& input);

#endif
