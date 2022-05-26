#pragma once

#include "Bazowa.h"


//Klasa pochodna. Wykorzystuję zmienne kalsy Bazowej, które zmieniane są w konstruktorze
//Posiada metode rysowania odwołująca się do przekazywania obiektu referencyjnie(Funkcja SFML)

class Ball : public Bazowa {

public:
        //Kontruktory i Destruktory
        Ball(float t_X, float t_Y, float _ballRadius, float _ballVelocity);
        Ball()=delete;
        ~Ball()=default;

        //Metody odnoszące się do stanu gry
        void update();
        void kill(int i);

        //Metoda odnosząca się do ustawiania tekstów w grze
        void setMyText();



        //Zmienne
        unsigned int score{100};
        Font font;
        Text gameLose;
        Text gameWin;
        Text scoreTxt;


private:
        
        void draw(RenderTarget& target, RenderStates state) const override; //rysowanie kulki

};

