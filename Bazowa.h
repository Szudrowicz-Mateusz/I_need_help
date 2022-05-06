#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using namespace sf;

class Bazowa: public sf::Drawable{
    public:
        CircleShape shape;
        float ballRadius{0.f}; //Stworzenie kulki
        float ballVelocity{1.f};//Prędkosć piłki

        Vector2f velocity{ballVelocity,ballVelocity}; //Piłka przemieszcza się w 
                                                      //obu płaszczyznach z  nadaną wartością




    
        Bazowa() = default;
        ~Bazowa();

        void update();

        float left();
        float right();
        float top();
        float bottom();

};
