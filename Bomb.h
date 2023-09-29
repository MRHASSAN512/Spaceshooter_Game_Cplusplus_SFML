#ifndef BOMB_H
#define BOMB_H
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Bomb{
public:
Texture tex;
Sprite sprite;
float speed;
int x,y;
Bomb()
{
	x=0;
	y=0;
	speed=1;
}
Bomb(std::string png_path,int n1,int n2)
{
  tex.loadFromFile(png_path);
  sprite.setTexture(tex);
  x=n1;
  y=n2;
  sprite.setPosition(x,y);  
  sprite.setScale(1,1);
}
void bombmove()
{
   sprite.move(0,speed);
}
};
#endif
