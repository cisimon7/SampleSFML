/*
 * Created by Simon Idoko on 18.02.2022.
 * */

#include "SFML/Graphics/Shape.hpp"
#include "SFML/Graphics/ConvexShape.hpp"

class Fly : public sf::Shape {
private:
    float lower_width, upper_width, height;
    sf::ConvexShape wing;

public:
    Fly(float lowerWidth, float upperWidth, float height) :
            lower_width(lowerWidth), upper_width(upperWidth), height(height) {
        wing.setPointCount(6);
        wing.setPoint(0, sf::Vector2f(0.f, 0.f));
        wing.setPoint(1, sf::Vector2f((upperWidth / 2), -(height / 3)));
        wing.setPoint(2, sf::Vector2f((lowerWidth / 2), (2 * height / 3)));
        wing.setPoint(3, sf::Vector2f(0.f, 15.f));
        wing.setPoint(4, sf::Vector2f(-(lowerWidth / 2), (2 * height / 3)));
        wing.setPoint(5, sf::Vector2f(-(upperWidth / 2), -(height / 3)));
        update();
    }

    size_t getPointCount() const override {
        return wing.getPointCount();
    }

    sf::Vector2f getPoint(std::size_t index) const override {
        return wing.getPoint(index);
    }
};

