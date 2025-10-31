#include <iostream>
#include <string>
#include "tokenizer.hpp"
#include "parser.hpp"
#include "semantic.hpp"
#include "executor.hpp"
#include "presentation.hpp"

int main() {
    Presentation pres;
    std::string line;

    std::cout << "PPT-CLI (basic). Type commands or 'quit' to exit.\n";
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) break;
        if (line == "quit" || line == "exit") break;
        if (line.empty()) continue;

        try {
            auto tokens = tokenize(line);
            Command cmd = parse(tokens);
            if (!checkSemantics(cmd, pres)) continue;
            execute(cmd, pres);
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    std::cout << "Program exitted.\n";
    return 0;
}
