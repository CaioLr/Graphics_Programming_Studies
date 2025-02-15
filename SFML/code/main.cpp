#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
    // define an circle
    float circleSize = 10.f;
    sf::CircleShape circle(circleSize);

    // set the shape color to green
    circle.setFillColor(sf::Color(100, 250, 50));
    circle.setPosition({0.f, 0.f}); //start position

    sf::Vector2f output = circle.getPosition();
    
    float vel_x = 0.06f;
    float vel_y = 0.06f;

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
        if ( output.x > (window.getSize().x - 2*circleSize)){
            vel_x = vel_x * -1;
        }
        if ( output.x < 0){
            vel_x = vel_x * -1;
        }
        if ( output.y > (window.getSize().y - 2*circleSize)){
            vel_y = vel_y * -1;
        }
        if ( output.y < 0){
            vel_y = vel_y * -1;
        }

        output.x = output.x + vel_x;
        output.y = output.y + vel_y;
        circle.setPosition({output.x, output.y});
        // std::cout << output.x << "," << output.y << std::endl;
        
        window.draw(circle);
        window.draw(circle);

        // end the current frame
        window.display();
    }
}