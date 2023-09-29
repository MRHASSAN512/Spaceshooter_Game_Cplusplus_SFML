#ifndef INVADERS_H
#define INVADERS_H
#include <SFML/Graphics.hpp>
#include<string.h>
#include "Enemy.h"
using namespace sf;
class Invaders:public Enemy{
 public:
  Invaders(std::string png_path):Enemy(png_path){}
  virtual void enemyfire(Bomb*b1)=0;
  virtual void enemymove()=0;
  virtual void enemyfiredel()=0;
  virtual ~Invaders(){};
};
#endif
