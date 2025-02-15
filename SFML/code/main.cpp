#include <SFML/Graphics.hpp>
#include <iostream>

#include "Circle.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    Circle first(10.f);

    std::array<int, 3> color = {100, 250, 50};
    first.setColor(color);
    first.setPosition(0.f, 0.f);
    std::array<float, 2> velocity = {0.06f,0.06f};
    first.setVelocity(velocity);


    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        //Changing the direction of velocity x and y, when hits the border of the window
        if ( first.getPosition().x > (window.getSize().x - 2 * first.getRadius())){
            first.setVelocity({
                first.getVelocity()[0] * -1,
                first.getVelocity()[1]
            });
        }
        if ( first.getPosition().x < 0){
            first.setVelocity({
                first.getVelocity()[0] * -1,
                first.getVelocity()[1]
            });
        }
        if ( first.getPosition().y > (window.getSize().y - 2 * first.getRadius())){
            first.setVelocity({
                first.getVelocity()[0],
                first.getVelocity()[1] * -1
            });
        }
        if ( first.getPosition().y < 0){
            first.setVelocity({
                first.getVelocity()[0],
                first.getVelocity()[1] * -1
            });
        }

        first.setPosition(
            first.getPosition().x + first.getVelocity()[0],
            first.getPosition().y + first.getVelocity()[1]
        );
       
        
        window.draw(first);

        // end the current frame
        window.display();
    }
}