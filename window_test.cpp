#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Trajectory");
window.setFramerateLimit(30);
    double x, y, vx, vy;
    double gravity = -9.8;
    double drag = 0.99;
    double scale = 10.0;

    auto reset = [&]() {
        x = 0.0;
        y = 0.0;
        vx = 15.0;
        vy = 40.0;
    };
    reset();

    sf::CircleShape ball(10.0f, 3);
    ball.setFillColor(sf::Color::Blue);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        vy = vy + gravity * 0.016;
vx = vx * drag;
vy = vy * drag;
x = x + vx * 0.016;
y = y + vy * 0.016;

        float screenX = static_cast<float>(x * scale);
        float screenY = 600 - static_cast<float>(y * scale);
        ball.setPosition(screenX, screenY);

        if (screenY > 600) {
            reset();
        }

        window.clear(sf::Color::Black);
        window.draw(ball);
        window.display();

    }

    return 0;
}
