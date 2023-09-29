#ifndef MONSTER_H
#define MONSTER_H
#include<SFML/Graphics.hpp>
#include<string.h>
#include"Enemy.h"
using namespace sf;
class Monster:public Enemy{
 public:
 Monster(std::string png_path):Enemy(png_path){}
 virtual void enemymove(){
 if(count==0)
    {
        sprite.move(speed,0);
        if(sprite.getPosition().x>=1103)
          {
            count=1; 
           }
    }
    else if(count==1)
    {
        sprite.move(-speed, 0);
        if(sprite.getPosition().x<=0)
        {
            count=0;
        }    
    } }
 virtual void enemyfire(Bomb * b1)
 { 
   b=b1;
 }
 virtual void enemyfiredel()
 { 
   b=nullptr;
 }
 virtual ~Monster(){}
};
#endif
