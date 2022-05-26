#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



using namespace sf;

//Klasa Bazowa w której są zmeinne odnoszące się do 
//kształtu,wielkości,prędkości oraz wektoru skierowania
//Posiada metody spradzające czy obiekt nie wychodzi poza ekran oraz wprawiające w ruch

class Bazowa: public sf::Drawable{
    protected:
        CircleShape shape;
        float ballRadius{0.f}; //Stworzenie kulki
        float ballVelocity{0.f};//Prędkosć piłki

        Vector2f velocity{ballVelocity,ballVelocity}; //Piłka przemieszcza się w 
                                                      //obu płaszczyznach z  nadaną wartością



    public:
    //Konstruktory i desktrukotr
        Bazowa() = default;
        ~Bazowa();

        //Sprawdza czy piłka znajduję się na ekranie
        void update();

        //Metody zwracająca pozycje piłki
        float left();
        float right();
        float top();
        float bottom();

};
