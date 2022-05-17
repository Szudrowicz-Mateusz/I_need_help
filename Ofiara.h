#pragma once

#include "Bazowa.h"


//Klasa pochodna. Wykorzystuję zmienne kalsy Bazowej, które zmieniane są w konstruktorze
//Posiada metode rysowania odwołująca się do przekazywania obiektu referencyjnie(Funkcja SFML)

class Ofiara : public Bazowa {

public:
        Ofiara(float t_X, float t_Y, float _ballRadius, float _ballVelocity);

        Ofiara()=delete;
        ~Ofiara()=default;

        void update();

        bool isDestroyed();
        void destroy();

        bool destroyed{false};



private:
        Clock clock;

        void draw(RenderTarget& target, RenderStates state) const override; //rysowanie kulki

};
