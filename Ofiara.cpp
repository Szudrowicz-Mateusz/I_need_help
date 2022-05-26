#include "Ofiara.h"



//Kostruktor
Ofiara::Ofiara(float t_X, float t_Y, float _ballRadius, float _ballVelocity)
{
    ballRadius=_ballRadius;
    ballVelocity=_ballVelocity;
    shape.setPosition(t_X,t_Y);
    shape.setRadius(this->ballRadius); //Ustawiamy radius
    shape.setFillColor(Color::Green); //Ustawiamy kolor
 

        velocity.x=ballVelocity;//Pozwalamy classie pochodnej zdobyć jej wektor
        velocity.y=ballVelocity;//Bez tego piłka nie ruszy się

    shape.setOrigin(this->ballRadius,this->ballRadius);//Ustawiamy pozycje na podstawie wczesniejszej funkjci
}

//Metoda porusza obiektem oraz zależnie od czasu realnego zmienia wektor jego poruszania losowo
void Ofiara::update(){
    shape.move(this->velocity);//Metoda wbudowana w SFML do poruszania obiektów
    Bazowa::update();

    //Wykorzystanie klasy czasu, aby przeciwnicy zachowywali losowość na podstawie czasu.
   Time timeClock=clock.getElapsedTime();
   Time timeChange=seconds(2.3f);
   srand(time(NULL));
   if(timeClock > timeChange)
   {
       float _x=rand()%10-5,_y=rand()%10-5;

       velocity.x=velocity.x+_x;
       velocity.y=velocity.y+_y;
       clock.restart();
   }
   
}

//Metoda zwraca fakt że obiekt jest zniszczony
bool Ofiara::isDestroyed()
{
    return this->destroyed;
}

//Metoda niszcząca obiekt
void Ofiara::destroy()
{
    this->destroyed=true;
}

//Metoda rysuje obiekt na podawie referencji
void Ofiara::draw(RenderTarget& target,RenderStates state) const
{
    target.draw(this->shape,state); //Metoda rysowania 
}