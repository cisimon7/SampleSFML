#include <iostream>
#include <SFML/Graphics.hpp>
#include "Fly.cpp"

int main() {
    sf::RenderWindow window(
            sf::VideoMode(640, 480),
            "SFML Application",
            sf::Style::Close
    );

    Fly fly(12.f, 25.f, 30.f);
    fly.setFillColor(sf::Color::White);
    fly.setPosition({120.f, 120.f});

    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen()) {
        sf::Event event{};

        // check all the window's events that were triggered since the last iteration of the loop
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time elapsedTime = clock.getElapsedTime();

        window.clear();

        //TODO(Wing motion should depend on speed of fly)
        fly.setScale({0.2f + std::cos(3 * elapsedTime.asSeconds()), 1});
        window.draw(fly);
        window.display();
    }
}
