#ifndef FIRE_H
#define FIRE_H
#include<SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Fire:public Addon{
public:
Fire(std::string png_path):Addon(png_path){}
virtual void addonmove()
{
  sprite.move(0,speed);
}
virtual ~Fire(){}
};
#endif
