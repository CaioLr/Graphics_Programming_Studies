#include <SFML/Graphics.hpp>
#include <iostream>

#include "Circle.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    Circle first(40.f);
    Circle second(10.f);

    first.setColor({100, 250, 50});
    first.setPosition(400.f, 300.f);
    first.setVelocity({0.0f,0.0f});

    second.setColor({250, 100, 50});
    second.setPosition(160.f, 150.f);
    second.setVelocity({0.1f,0.1f});


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

        //Changing the direction of velocity x and y, when hits the border of the window
        if ( second.getPosition().x > (window.getSize().x - 2 * second.getRadius())){
            second.setVelocity({
                second.getVelocity()[0] * -1,
                second.getVelocity()[1]
            });
        }
        if ( second.getPosition().x < 0){
            second.setVelocity({
                second.getVelocity()[0] * -1,
                second.getVelocity()[1]
            });
        }
        if ( second.getPosition().y > (window.getSize().y - 2 * second.getRadius())){
            second.setVelocity({
                second.getVelocity()[0],
                second.getVelocity()[1] * -1
            });
        }
        if ( second.getPosition().y < 0){
            second.setVelocity({
                second.getVelocity()[0],
                second.getVelocity()[1] * -1
            });
        }


        //Updating position
        first.setPosition(
            first.getPosition().x + first.getVelocity()[0],
            first.getPosition().y + first.getVelocity()[1]
        );

        second.setPosition(
            second.getPosition().x + second.getVelocity()[0],
            second.getPosition().y + second.getVelocity()[1]
        );


        //Calculating distance
        float distance_x = first.getPosition().x - second.getPosition().x;
        float distance_y = first.getPosition().y - second.getPosition().y;
        if (distance_x < 0){
            distance_x = distance_x * -1;
        };
        if (distance_y < 0){
            distance_y = distance_y * -1;
        };
        float distance = distance_x + distance_y;

        // Detecting collision
        if(
            (distance < first.getRadius() + second.getRadius())
        ){
            second.setVelocity({
                second.getVelocity()[0] * -1,
                second.getVelocity()[1]
            });

            first.setVelocity({
                first.getVelocity()[0] * -1,
                first.getVelocity()[1]
            });

            second.setVelocity({
                second.getVelocity()[0],
                second.getVelocity()[1] * -1
            });

            first.setVelocity({
                first.getVelocity()[0],
                first.getVelocity()[1] * -1
            });
        };


        // float dx,dy;
        // if(
        //     distance < first.getRadius()*2
        // ){

        //     dx = first.getPosition().x - second.getPosition().x;
        //     dy = first.getPosition().y - second.getPosition().y;

        //     if(dx > 0){
        //         second.setPosition(
        //             second.getPosition().x + 0.03f,
        //             second.getPosition().y 
        //         );
        //     }
        //     if(dx < 0){
        //         second.setPosition(
        //             second.getPosition().x - 0.03f,
        //             second.getPosition().y 
        //         );
        //     }
        //     if(dy > 0){
        //         second.setPosition(
        //             second.getPosition().x,
        //             second.getPosition().y + 0.03f 
        //         );
        //     }
        //     if(dy < 0){
        //         second.setPosition(
        //             second.getPosition().x,
        //             second.getPosition().y  - 0.03f 
        //         );
        //     }
        // };
       
        
        window.draw(first);
        window.draw(second);

        // end the current frame
        window.display();
    }
}
