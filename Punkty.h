#pragma once

#include "Bazowa.h"


//Klasa pochodna. Wykorzystuję zmienne kalsy Bazowej, które zmieniane są w konstruktorze
//Posiada metode rysowania odwołująca się do przekazywania obiektu referencyjnie(Funkcja SFML)

class Punkty : public Bazowa {

public:
        //Konstrukotry i destruktor
        Punkty(int t_X, int t_Y, float _ballRadius);
        Punkty()=delete;
        ~Punkty()=default;

        //Metoda aktualizująca
        void update();

        //Metody niszczące obiekt
        bool isDestroyed();
        void destroy();
        bool destroyed{false};

private:
        
        
        void draw(RenderTarget& target, RenderStates state) const override; //rysowanie kulki

};