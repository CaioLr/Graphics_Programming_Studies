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

    void borderHit(Circle first,sf::Vector2u window){
        //Changing the direction of velocity x and y, when hits the border of the window
       if ( sf::CircleShape::getPosition().x > (window.x - 2 * sf::CircleShape::getRadius())){
           sf::CircleShape::setVelocity({
               sf::CircleShape::getVelocity()[0] * -1,
               sf::CircleShape::getVelocity()[1]
           });
       }
       if ( sf::CircleShape::getPosition().x < 0){
           sf::CircleShape::setVelocity({
               sf::CircleShape::getVelocity()[0] * -1,
               sf::CircleShape::getVelocity()[1]
           });
       }
       if ( sf::CircleShape::getPosition().y > (window.y - 2 * sf::CircleShape::getRadius())){
           sf::CircleShape::setVelocity({
               sf::CircleShape::getVelocity()[0],
               sf::CircleShape::getVelocity()[1] * -1
           });
       }
       if ( sf::CircleShape::getPosition().y < 0){
           sf::CircleShape::setVelocity({
               sf::CircleShape::getVelocity()[0],
               sf::CircleShape::getVelocity()[1] * -1
           });
       }
    
    };

};

#endif 