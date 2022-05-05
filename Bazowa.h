#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Bazowa{
    protected:
        CircleShape shape;
        float ballRadius{0.f}; //Stworzenie kulki
        float ballVelocity{0.f};//Prędkosć piłki

        Vector2f velocity{ballVelocity,ballVelocity}; //Piłka przemieszcza się w 
                                                      //obu płaszczyznach z  nadaną wartością


        void draw(RenderTarget& target, RenderStates state) const;

    public:
        Bazowa() = default;
        virtual ~Bazowa();

        virtual void update();

        virtual float left();
        virtual float right();
        virtual float top();
        virtual float bottom();


};