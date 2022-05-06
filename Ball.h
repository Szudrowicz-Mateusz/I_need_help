#pragma once

#include "Bazowa.h"




class Ball : public Bazowa {

public:
        Ball(float t_X, float t_Y, float _ballRadius, float _ballVelocity);

        Ball()=delete;
        ~Ball()=default;

        void update();




private:
        
        void draw(RenderTarget& target, RenderStates state) const override; //rysowanie kulki

};

