#pragma once

#include "Bazowa.h"


//Klasa pochodna. Wykorzystuję zmienne kalsy Bazowej, które zmieniane są w konstruktorze
//Posiada metode rysowania odwołująca się do przekazywania obiektu referencyjnie(Funkcja SFML)

class Punkty : public Bazowa {

public:
        Punkty(int t_X, int t_Y, float _ballRadius); //Zmniejszam wykoszrystywana pamięć
//Punkty nie poruszają się a więc ich pozycja może być skrócona do liczb całkowitych
        Punkty()=delete;
        ~Punkty()=default;

        void update();

        bool isDestroyed();
        void destroy();

       



 bool destroyed{false};

private:
        
        
        void draw(RenderTarget& target, RenderStates state) const override; //rysowanie kulki

};