#include "executor.hpp"
#include "presentation.hpp"
#include <iostream>
#include <algorithm>   
#include <cstdlib>     


void execute(const Command& cmd, Presentation& state) {
    if (cmd.name == "add_slide_front") {
        Slide s;
        s.title = "New Slide";
        state.slides.insert(state.slides.begin(), s);
        state.currentSlide = 0;
        std::cout << "Added slide at front. Total slides: " << state.slides.size() << "\n";
        return;
    }

    if (cmd.name == "add_slide_mid") {
        Slide s;
        s.title = "New Slide";
        size_t pos = state.slides.size() / 2;
        state.slides.insert(state.slides.begin() + pos, s);
        state.currentSlide = (int)pos;
        std::cout << "Added slide in the middle. Total slides: " << state.slides.size() << "\n";
        return;
    }

    if (cmd.name == "add_slide_back") {
        Slide s;
        s.title = "New Slide";
        state.slides.push_back(s);
        state.currentSlide = (int)state.slides.size() - 1;
        std::cout << "Added slide at back. Total slides: " << state.slides.size() << "\n";
        return;
    }

    if (cmd.name == "delete_slide") {
        if (cmd.args.empty()) { std::cout << "delete_slide: missing argument\n"; return; }
        int idx = std::atoi(cmd.args[0].c_str());
        state.slides.erase(state.slides.begin() + idx);
        if (state.slides.empty()) state.currentSlide = -1;
        else state.currentSlide = 0;
        std::cout << "Deleted slide " << idx << ". Remaining: " << state.slides.size() << "\n";
        return;
    }

    if (cmd.name == "switch_slide") {
        if (cmd.args.empty()) { std::cout << "switch_slide: missing argument\n"; return; }
        int idx = std::atoi(cmd.args[0].c_str());
        state.currentSlide = idx;
        std::cout << "Switched to slide " << idx << "\n";
        return;
    }

    if (cmd.name == "reorder_slides") {
        if (cmd.args.size() < 2) { std::cout << "reorder: missing arguments\n"; return; }
        int a = std::atoi(cmd.args[0].c_str());
        int b = std::atoi(cmd.args[1].c_str());
        std::swap(state.slides[a], state.slides[b]);
        std::cout << "Reordered slides " << a << " and " << b << "\n";
        return;
    }

    if (cmd.name == "add_text") {
        if (state.currentSlide < 0) { std::cout << "No slide selected\n"; return; }
        state.slides[state.currentSlide].textBlocks.push_back(cmd.args[0]);
        std::cout << "Added text to slide " << state.currentSlide << "\n";
        return;
    }

    if (cmd.name == "delete_text") {
        if (state.currentSlide < 0) { std::cout << "No slide selected\n"; return; }
        if (!state.slides[state.currentSlide].textBlocks.empty()) {
            state.slides[state.currentSlide].textBlocks.pop_back();
            std::cout << "Deleted last text block\n";
        }
        else {
            std::cout << "No text blocks to delete\n";
        }
        return;
    }

    if (cmd.name == "font_text") {
        if (state.currentSlide < 0) { std::cout << "No slide selected\n"; return; }
        state.slides[state.currentSlide].font = cmd.args[0];
        std::cout << "Set font on slide " << state.currentSlide << " to " << cmd.args[0] << "\n";
        return;
    }

    if (cmd.name == "add_image") {
        if (state.currentSlide < 0) { std::cout << "No slide selected\n"; return; }
        state.slides[state.currentSlide].images.push_back(cmd.args[0]);
        std::cout << "Added image to slide " << state.currentSlide << "\n";
        return;
    }

    if (cmd.name == "delete_image") {
        if (state.currentSlide < 0) { std::cout << "No slide selected\n"; return; }
        if (cmd.args.empty()) { std::cout << "delete.img: missing index\n"; return; }
        int idx = std::atoi(cmd.args[0].c_str());
        if (idx < 0 || idx >= (int)state.slides[state.currentSlide].images.size()) {
            std::cout << "delete.img: index out of range\n"; return;
        }
        state.slides[state.currentSlide].images.erase(state.slides[state.currentSlide].images.begin() + idx);
        std::cout << "Deleted image " << idx << " from slide " << state.currentSlide << "\n";
        return;
    }

    if (cmd.name == "add_shape") {
        if (state.currentSlide < 0) { std::cout << "No slide selected\n"; return; }
        state.slides[state.currentSlide].shapes.push_back(cmd.args[0]);
        std::cout << "Added shape to slide " << state.currentSlide << "\n";
        return;
    }

    if (cmd.name == "delete_shape") {
        if (state.currentSlide < 0) { std::cout << "No slide selected\n"; return; }
        if (cmd.args.empty()) { std::cout << "del.shape: missing index\n"; return; }
        int idx = std::atoi(cmd.args[0].c_str());
        if (idx < 0 || idx >= (int)state.slides[state.currentSlide].shapes.size()) {
            std::cout << "del.shape: index out of range\n"; return;
        }
        state.slides[state.currentSlide].shapes.erase(state.slides[state.currentSlide].shapes.begin() + idx);
        std::cout << "Deleted shape " << idx << " from slide " << state.currentSlide << "\n";
        return;
    }

    if (cmd.name == "add_transition") {
        if (state.currentSlide < 0) { std::cout << "No slide selected\n"; return; }
        state.slides[state.currentSlide].transition = cmd.args[0];
        std::cout << "Set transition on slide " << state.currentSlide << " to " << cmd.args[0] << "\n";
        return;
    }

    if (cmd.name == "add_animation") {
        if (state.currentSlide < 0) { std::cout << "No slide selected\n"; return; }
        state.slides[state.currentSlide].animation = cmd.args[0];
        std::cout << "Set animation on slide " << state.currentSlide << " to " << cmd.args[0] << "\n";
        return;
    }

    // fetch_state
    if (cmd.name == "fetch_state") {
        std::cout << "=== Presentation State ===\n";
        std::cout << "Slides: " << state.slides.size() << "\n";
        for (size_t i = 0; i < state.slides.size(); ++i) {
            auto& sl = state.slides[i];
            std::cout << "Slide " << i;
            if ((int)i == state.currentSlide) std::cout << " [current]";
            std::cout << ": " << sl.title << " (bg: " << sl.backgroundColor << ")\n";
            for (auto& t : sl.textBlocks) std::cout << "  Text: " << t << "\n";
            for (auto& im : sl.images) std::cout << "  Image: " << im << "\n";
            for (auto& sh : sl.shapes) std::cout << "  Shape: " << sh << "\n";
            if (sl.transition != "none") std::cout << "  Transition: " << sl.transition << "\n";
            if (sl.animation != "none") std::cout << "  Animation: " << sl.animation << "\n";
        }
        std::cout << "Default font: " << state.font << "\n";
        return;
    }

    std::cout << "Unknown command (executor): " << cmd.name << "\n";
}
