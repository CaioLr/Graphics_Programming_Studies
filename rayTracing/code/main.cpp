#include <SFML/Graphics.hpp>
#include <iostream>
#include "Circle.h"


void border(Circle first,sf::Vector2u window){


    //Changing the direction of velocity x and y, when hits the border of the window
   if ( first.getPosition().x > (window.x - 2 * first.getRadius())){
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
   if ( first.getPosition().y > (window.y - 2 * first.getRadius())){
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

};

int main()
{
    sf::RenderWindow window(sf::VideoMode({1600, 800}), "SFML works!");
    
    sf::Vector2u windowSize = window.getSize();
    Circle circle(40.f);


    circle.setColor({100, 250, 50});
    circle.setPosition(400.f, 300.f);
    circle.setVelocity({0.06f,0.06f});


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        //Changing the direction of velocity x and y, when hits the border of the window
        if (circle.getPosition().x > (window.getSize().x - 2 *circle.getRadius())){
           circle.setVelocity({
               circle.getVelocity()[0] * -1,
               circle.getVelocity()[1]
            });
        }
        if (circle.getPosition().x < 0){
           circle.setVelocity({
               circle.getVelocity()[0] * -1,
               circle.getVelocity()[1]
            });
        }
        if (circle.getPosition().y > (window.getSize().y - 2 *circle.getRadius())){
           circle.setVelocity({
               circle.getVelocity()[0],
               circle.getVelocity()[1] * -1
            });
        }
        if (circle.getPosition().y < 0){
           circle.setVelocity({
               circle.getVelocity()[0],
               circle.getVelocity()[1] * -1
            });
        }

        //Updating position
        circle.setPosition(
            circle.getPosition().x + circle.getVelocity()[0],
            circle.getPosition().y + circle.getVelocity()[1]
        );



        window.draw(circle);
        window.display();
    }
}


