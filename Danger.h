#ifndef DANGER_H
#define DANGER_H
#include<SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Danger:public Addon{
public:
Danger(std::string png_path):Addon(png_path){}
virtual void addonmove()
{
  sprite.move(0,speed);
}
virtual ~Danger(){}
};
#endif
