#ifndef PRESENTATION_HPP
#define PRESENTATION_HPP

#include <string>
#include <vector>

struct Slide {
    std::string title = "Untitled Slide";
    std::vector<std::string> textBlocks;
    std::vector<std::string> images;
    std::vector<std::string> shapes;
    std::string backgroundColor = "white";
    std::string font = "Default";
    std::string transition = "none";
    std::string animation = "none";
};

struct Presentation {
    std::vector<Slide> slides;
    int currentSlide = -1;
    std::string font = "Default";
    std::string name = "Untitled";
};

#endif
