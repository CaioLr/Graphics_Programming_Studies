#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

class Circle : public sf::CircleShape{
public:
    std::array<float, 2> velocity;

    Circle(float radius) : sf::CircleShape(radius) {};  

    void setRadius(float x){
        sf::CircleShape::setRadius(x);
    };

    float getRadius(){
        return sf::CircleShape::getRadius();
    }

    void setPosition(float x, float y) {
        // Chama o método herdado para definir a posição.
        sf::CircleShape::setPosition({x, y});
    }

    sf::Vector2f getPostion(){
        sf::Vector2f output = sf::CircleShape::getPosition();
        return output;
    };

    void setColor( std::array<int, 3> color){
        sf::CircleShape::setFillColor(sf::Color(color[0], color[1], color[2]));
    };

    void setVelocity(std::array<float, 2> vel){
        velocity[0] = vel[0];
        velocity[1] = vel[1];
    };

    std::array<float, 2> getVelocity(){
        return velocity;
    };

};

#endif