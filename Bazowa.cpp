#include "Bazowa.h"

        Bazowa::~Bazowa(){
            //nic
        }

//Metoda sprawdza pozycję obiektu i zmienia wektor poruszania zależenie od dotkniętej ściany
void Bazowa::update()
{

    if(this->left()<0)
    {
        velocity.x=ballVelocity;
    }

    else if(this->right()>1024)
    {
        velocity.x=-ballVelocity;
    }

    else if(this->top()<0)
    {
        velocity.y=ballVelocity;
    }

    else if(this->bottom()>768)
    {
        velocity.y=-ballVelocity;
    }

}

        //Metody zwracające pozycję obiektu
        float Bazowa::left()
        {
            return this->shape.getPosition().x-shape.getRadius();
        }
        float Bazowa::right()
        {
            return this->shape.getPosition().x+shape.getRadius();
        }
        float Bazowa::top()
        {
            return this->shape.getPosition().y-shape.getRadius();
        }
        float Bazowa::bottom()
        {
            return this->shape.getPosition().y+shape.getRadius();
        }