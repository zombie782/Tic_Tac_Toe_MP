#ifndef WALL_H
#define WALL_H
class Wall{
        sf::RectangleShape wall;
    public:
        Wall(double x,double y,const sf::Color &c=sf::Color::Black){
            wall.setSize(sf::Vector2f(x,y));
            wall.setFillColor(c);
        }
        Wall(double x,double y,double a,double b,const sf::Color &c=sf::Color::Black){
            wall.setSize(sf::Vector2f(x,y));
            wall.setPosition(a,b);
            wall.setFillColor(c);
        }
        sf::RectangleShape getRectangle(){
            return this->wall;
        }
};
#endif
