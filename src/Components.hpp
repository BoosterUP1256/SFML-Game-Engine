#pragma once
#include <SFML/Graphics.hpp>

struct Component {
    bool has = true;
};

struct CTest : public Component {
    int number = 5;
};

struct CShape : public Component {
    sf::CircleShape circle;

    CShape() 
        : circle(20, 20) {}

    CShape(float radius, int points, const sf::Color& fill, const sf::Color& outline, float thickness)
        : circle(radius, points) {
        circle.setFillColor(fill);
        circle.setOutlineColor(outline);
        circle.setOutlineThickness(thickness);
        circle.setOrigin(radius, radius);
    }
};
