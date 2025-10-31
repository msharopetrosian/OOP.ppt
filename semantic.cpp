#include "semantic.hpp"
#include <iostream>
#include <cstdlib>

static bool isNumber(const std::string& s) {
    if (s.empty()) return false;
    for (char c : s) if (!std::isdigit((unsigned char)c)) return false;
    return true;
}

bool checkSemantics(const Command& cmd, const Presentation& state) {
    auto needsSlide = [&](const std::string& name) {
        return name != "add_slide_front" && name != "add_slide_mid" && name != "add_slide_back" && name != "fetch_state";
        };

    if (needsSlide(cmd.name) && state.slides.empty()) {
        std::cerr << "Semantic error: no slides exist. Add a slide first.\n";
        return false;
    }

    if (cmd.name == "delete_slide") {
        if (cmd.args.empty() || !isNumber(cmd.args[0])) {
            std::cerr << "Semantic error: delete_slide needs a numeric index.\n";
            return false;
        }
        int idx = std::atoi(cmd.args[0].c_str());
        if (idx < 0 || idx >= (int)state.slides.size()) {
            std::cerr << "Semantic error: slide " << idx << " does not exist.\n";
            return false;
        }
    }

    if (cmd.name == "switch_slide") {
        if (cmd.args.empty() || !isNumber(cmd.args[0])) {
            std::cerr << "Semantic error: switch requires numeric index.\n";
            return false;
        }
        int idx = std::atoi(cmd.args[0].c_str());
        if (idx < 0 || idx >= (int)state.slides.size()) {
            std::cerr << "Semantic error: slide " << idx << " does not exist.\n";
            return false;
        }
    }

    if (cmd.name == "reorder_slides") {
        if (cmd.args.size() < 2 || !isNumber(cmd.args[0]) || !isNumber(cmd.args[1])) {
            std::cerr << "Semantic error: reorder requires two numeric indices.\n";
            return false;
        }
        int a = std::atoi(cmd.args[0].c_str());
        int b = std::atoi(cmd.args[1].c_str());
        if (a < 0 || a >= (int)state.slides.size() || b < 0 || b >= (int)state.slides.size()) {
            std::cerr << "Semantic error: reorder indices out of range.\n";
            return false;
        }
    }

    if (cmd.name == "add_text") {
        if (cmd.args.empty()) {
            std::cerr << "Semantic error: add.txt requires text argument.\n";
            return false;
        }
    }

    if (cmd.name == "add_image") {
        if (cmd.args.empty()) {
            std::cerr << "Semantic error: add.img requires path argument.\n";
            return false;
        }
    }


    return true;
}
