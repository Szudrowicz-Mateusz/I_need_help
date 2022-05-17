#pragma once

#include "Bazowa.h"



//Klasa pochodna. Wykorzystuję zmienne kalsy Bazowej, które zmieniane są w konstruktorze
//Posiada metode rysowania odwołująca się do przekazywania obiektu referencyjnie(Funkcja SFML)

class Przeciwnik : public Bazowa {

public:
        Przeciwnik(float t_X, float t_Y, float _ballRadius, float _ballVelocity);

        Przeciwnik()=delete;
        ~Przeciwnik()=default;

        void update();




private:
        Clock clock;

        void draw(RenderTarget& target, RenderStates state) const override; //rysowanie kulki

};
