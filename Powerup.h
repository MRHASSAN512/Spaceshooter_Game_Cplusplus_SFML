#ifndef POWERUP_H
#define POWERUP_H
#include<SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Powerup:public Addon{
public:
Powerup(std::string png_path):Addon(png_path){}
virtual void addonmove()
{
  sprite.move(0,speed);
}
virtual ~Powerup(){}
};
#endif
