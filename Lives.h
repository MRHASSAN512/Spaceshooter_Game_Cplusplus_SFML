#ifndef LIVES_H
#define LIVES_H
#include<SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Lives:public Addon{
public:
Lives(std::string png_path):Addon(png_path){}
virtual void addonmove()
{ 
 sprite.move(0,speed);
}
virtual ~Lives(){}
};
#endif
