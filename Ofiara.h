#pragma once

#include "Bazowa.h"


//Klasa pochodna. Wykorzystuję zmienne kalsy Bazowej, które zmieniane są w konstruktorze
//Posiada metode rysowania odwołująca się do przekazywania obiektu referencyjnie(Funkcja SFML)

class Ofiara : public Bazowa {

public:
        //Konstruktory i destrukory
        Ofiara(float t_X, float t_Y, float _ballRadius, float _ballVelocity);
        Ofiara()=delete;
        ~Ofiara()=default;

        //Metoda aktualizująca obiekt
        void update();

        //Metody niszczące obiekt
        bool isDestroyed();
        void destroy();
        bool destroyed{false};



private:
        //Zmiennaa odwołująca się do realnego czasu
        Clock clock;

        void draw(RenderTarget& target, RenderStates state) const override; //rysowanie kulki

};
