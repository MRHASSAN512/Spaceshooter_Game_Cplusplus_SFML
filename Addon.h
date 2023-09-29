#ifndef ADDON_H
#define ADDON_H
#include<SFML/Graphics.hpp>
#include<string.h>
#include <cstdlib>
using namespace sf;
class Addon{
public:
Texture tex;
Sprite sprite;
int count;
int x,y;
float speed;
Addon(std::string png_path)
{
 srand(time(0));
 tex.loadFromFile(png_path);
 sprite.setTexture(tex);
 sprite.setScale(2,2);
 x=rand()%1001+100;
 y=0;
 speed=0.5;
 sprite.setPosition(x,y);
}
virtual void addonmove()=0;
virtual ~Addon() {}
};
#endif
