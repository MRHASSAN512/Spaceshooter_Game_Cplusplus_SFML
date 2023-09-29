#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Bullet{
public:
Texture tex;
Sprite sprite;
int x,y;
float speed=7;
int count=0;
Bullet(){
	x=0;
	y=0;
}
Bullet(std::string png_path,int n1,int n2)
{
  tex.loadFromFile(png_path);
  sprite.setTexture(tex);
  x=n1;
  y=n2;
  sprite.setPosition(x,y);

}
void bulletmove()
{ 
  if(count==1)
  sprite.move(speed,-speed);
  else if(count==2)
  sprite.move(-speed,-speed);
  else if(count==0)
  sprite.move(0,-speed);
  
}

};
#endif
