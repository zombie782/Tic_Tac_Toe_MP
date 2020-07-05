#ifndef PIECE_H
#define PIECE_H
class Piece{
        sf::RectangleShape p1,p2;
        sf::CircleShape c1,c2;
        sf::Vector2i pos;
        double xcor,ycor;
        bool type,is_disabled=false;
        pair<sf::RectangleShape,sf::RectangleShape> draw_x(){
            pair<sf::RectangleShape,sf::RectangleShape> piece(p1,p2);
            return piece;
        }
        pair<sf::CircleShape,sf::CircleShape> draw_o(){
            pair<sf::CircleShape,sf::CircleShape> piece(c1,c2);
            return piece;
        }
    public:
        Piece(bool t,double a,double b):
        xcor(a),ycor(b),type(t){
            if(this->type){
                p1.setSize(sf::Vector2f(100,20));
                p2.setSize(sf::Vector2f(20,100));
                p1.setPosition(xcor,(ycor+40));
                p2.setPosition((xcor+40),ycor);
                p1.setFillColor(sf::Color::Yellow);
                p2.setFillColor(sf::Color::Yellow);
            }else{
                c1.setRadius(50);
                c2.setRadius(30);
                c1.setPosition(xcor,ycor);
                c2.setPosition(xcor+20,ycor+20);
                c1.setFillColor(sf::Color::Yellow);
                c2.setFillColor(sf::Color::White);
            }
        }
        bool hover(sf::RenderWindow &window){
            bool is_hover=false;
            if(is_disabled==false){
                pos=sf::Mouse::getPosition(window);
                if(pos.x>xcor && pos.x<(xcor+100) && pos.y>ycor && pos.y<(ycor+100)){
                    if(type==true){
                        window.draw(draw_x().first);
                        window.draw(draw_x().second);
                    }else{
                        window.draw(draw_o().first);
                        window.draw(draw_o().second);
                    }
                    is_hover=true;
                }
            }
            return is_hover;
        }
        void draw_piece(sf::RenderWindow &window){
            if(is_disabled==false){
                if(type){
                    p1.setFillColor(sf::Color::Red);
                    p2.setFillColor(sf::Color::Red);
                    window.draw(draw_x().first);
                    window.draw(draw_x().second);
                }else{
                    c1.setFillColor(sf::Color::Blue);
                    window.draw(draw_o().first);
                    window.draw(draw_o().second);
                }
                is_played=true;
            }
        }
        void disable(){
            this->is_disabled=true;
        }
        bool is_played=false;
};


#endif
