#include "Ofiara.h"




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

void Ofiara::update(){
    shape.move(this->velocity);//Metoda wbudowana w SFML do poruszania obiektów
    Bazowa::update();

    //Wykorzystanie klasy czasu, aby przeciwnicy zachowywali losowość na podstawie czasu.
   Time timeClock=clock.getElapsedTime();
   Time timeChange=seconds(2.3f);
   if(timeClock > timeChange)
   {
       srand(time(NULL));
       float _x=rand()%10-5,_y=rand()%10-5;

       velocity.x=velocity.x+_x;
       velocity.y=velocity.y+_y;
       clock.restart();
   }
   
}

bool Ofiara::isDestroyed()
{
    return this->destroyed;
}

void Ofiara::destroy()
{
    this->destroyed=true;
}

void Ofiara::draw(RenderTarget& target,RenderStates state) const
{
    target.draw(this->shape,state); //Metoda rysowania 
}