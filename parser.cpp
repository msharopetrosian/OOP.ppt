#include "parser.hpp"
#include <stdexcept>
#include <cctype>

static bool isNumberString(const std::string& s) {
    if (s.empty()) return false;
    for (char c : s) if (!std::isdigit((unsigned char)c)) return false;
    return true;
}

Command parse(const std::vector<Token>& tokens) {
    Command cmd;
    if (tokens.empty()) {
        throw std::runtime_error("Empty token list");
    }


    TokenType t = tokens[0].type;

    switch (t) {
    case TokenType::ADD_SLIDE_FR:
        cmd.name = "add_slide_front";
        break;
    case TokenType::ADD_SLIDE_MID:
        cmd.name = "add_slide_mid";
        break;
    case TokenType::ADD_SLIDE_BACK:
        cmd.name = "add_slide_back";
        break;
    case TokenType::DEL_SLIDE:
        cmd.name = "delete_slide";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG) {
            cmd.args.push_back(tokens[1].value);
        }
        else {
            throw std::runtime_error("Syntax error: del.slide requires an index argument");
        }
        break;
    case TokenType::FETCH:
        cmd.name = "fetch_state";
        break;
    case TokenType::SWITCH:
        cmd.name = "switch_slide";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG) {
            cmd.args.push_back(tokens[1].value);
        }
        else {
            throw std::runtime_error("Syntax error: sw requires an index");
        }
        break;
    case TokenType::REORDER:
        cmd.name = "reorder_slides";
        if (tokens.size() > 2 && tokens[1].type == TokenType::ARG && tokens[2].type == TokenType::ARG) {
            cmd.args.push_back(tokens[1].value);
            cmd.args.push_back(tokens[2].value);
        }
        else {
            throw std::runtime_error("Syntax error: reorder requires two indices");
        }
        break;

    case TokenType::ADD_TEXT:
        cmd.name = "add_text";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG)
            cmd.args.push_back(tokens[1].value);
        else
            throw std::runtime_error("Syntax error: add.txt requires text argument (use quotes if needed)");
        break;
    case TokenType::DEL_TEXT:
        cmd.name = "delete_text";
        break;
    case TokenType::FONT_TEXT:
        cmd.name = "font_text";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG)
            cmd.args.push_back(tokens[1].value);
        else
            throw std::runtime_error("Syntax error: font.txt requires font name");
        break;
    case TokenType::COLOR_TEXT:
        cmd.name = "color_text";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG)
            cmd.args.push_back(tokens[1].value);
        else
            throw std::runtime_error("Syntax error: color.txt requires color name");
        break;
    case TokenType::BG_TEXT:
        cmd.name = "bg_text";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG)
            cmd.args.push_back(tokens[1].value);
        else
            throw std::runtime_error("Syntax error: bg.txt requires color name");
        break;
    case TokenType::SIZE_TEXT:
        cmd.name = "size_text";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG && isNumberString(tokens[1].value))
            cmd.args.push_back(tokens[1].value);
        else
            throw std::runtime_error("Syntax error: size.txt requires numeric size");
        break;

    case TokenType::ADD_IMAGE:
        cmd.name = "add_image";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG)
            cmd.args.push_back(tokens[1].value);
        else
            throw std::runtime_error("Syntax error: add.img requires file path");
        break;
    case TokenType::DEL_IMAGE:
        cmd.name = "delete_image";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG && isNumberString(tokens[1].value))
            cmd.args.push_back(tokens[1].value);
        else
            throw std::runtime_error("Syntax error: del.img requires numeric index");
        break;
    case TokenType::ADD_SHAPE:
        cmd.name = "add_shape";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG)
            cmd.args.push_back(tokens[1].value);
        else
            throw std::runtime_error("Syntax error: add.shape requires shape name");
        break;
    case TokenType::DEL_SHAPE:
        cmd.name = "delete_shape";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG && isNumberString(tokens[1].value))
            cmd.args.push_back(tokens[1].value);
        else
            throw std::runtime_error("Syntax error: del.shape requires numeric index");
        break;
    case TokenType::COLOR_SHAPE:
        cmd.name = "color_shape";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG)
            cmd.args.push_back(tokens[1].value);
        else
            throw std::runtime_error("Syntax error: color.shape requires color");
        break;
    case TokenType::SIZE_SHAPE:
        cmd.name = "size_shape";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG && isNumberString(tokens[1].value))
            cmd.args.push_back(tokens[1].value);
        else
            throw std::runtime_error("Syntax error: size.shape requires numeric size");
        break;

    case TokenType::ADD_TRANS:
        cmd.name = "add_transition";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG)
            cmd.args.push_back(tokens[1].value);
        else
            throw std::runtime_error("Syntax error: add.trans requires type");
        break;
    case TokenType::ADD_ANIM:
        cmd.name = "add_animation";
        if (tokens.size() > 1 && tokens[1].type == TokenType::ARG)
            cmd.args.push_back(tokens[1].value);
        else
            throw std::runtime_error("Syntax error: add.anim requires type");
        break;

    default:
        throw std::runtime_error("Unknown command in parser");
    }

    return cmd;
}
