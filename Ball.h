

#include "Bazowa.h"



class Ball : public sf::Drawable , Bazowa {

public:
        Ball(float t_X, float t_Y);

        Ball()=delete;
        ~Ball(){};

        void update();

        float left();
        float right();
        float top();
        float bottom();


private:
        CircleShape shape;
        float ballRadius{10.f}; //Stworzenie kulki
        float ballVelocity{3.f};//Prędkosć piłki

        Vector2f velocity{ballVelocity,ballVelocity}; //Piłka przemieszcza się w 
                                                      //obu płaszczyznach z  nadaną wartością


        void draw(RenderTarget& target, RenderStates state) const override; //rysowanie kulki

};