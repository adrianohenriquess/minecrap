#include <SFML/Graphics.hpp>
//#include <memory>
//#include <iostream>
#include <experimental/random>

int main() {
    std::srand(std::time(nullptr));
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Minecrap - 0.1");
    //ponteiro inteligente
    //auto object = std::make_shared<sf::RectangleShape>();

    sf::RectangleShape object;    
    object.setSize(sf::Vector2f(100.f, 100.f));
    object.setFillColor(sf::Color(0,255,0));

    float x = static_cast<float>(std::experimental::randint(10, (int)(window.getSize().x - object.getSize().x - 10)));
    object.setPosition(sf::Vector2f(x, 10.f));

    while (window.isOpen()) {
    	sf::Event event;
        while (window.pollEvent(event)) {
              if (event.type == sf::Event::Closed)
                  window.close();
        }

        if (object.getPosition().y > window.getSize().y) {
            //std::cout << "A posição é: " << object.getPosition().y << '\n';
            x = static_cast<float>(std::experimental::randint(10, (int)(window.getSize().x - object.getSize().x - 10)));
            object.setPosition(x, 10.f);
        }
	    object.move(0.f, 0.9f);

        window.clear();
        window.draw(object);
        window.display();
    }

    //delete object;
    //object = nullptr;

    return EXIT_SUCCESS;
}
