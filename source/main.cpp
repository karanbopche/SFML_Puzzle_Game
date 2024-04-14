#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cards Game");
    sf::Texture background;
    if (!background.loadFromFile("assets/images/puzzle_Image_1.jpg"))
    {
        return -1;
    }
    sf::Sprite bgSprite(background);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(bgSprite);
        window.display();
        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}