#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include<string.h>
#include"Bomb.h"
using namespace sf;
class Enemy{
 public:
 Texture tex;
 Sprite sprite;
 Bomb *b;
 int count,s;
 float speed;
 int x,y;
 Enemy(std::string png_path)
 {
    tex.loadFromFile(png_path);
    sprite.setTexture(tex);
    sprite.setScale(0.8,0.8);
    count=0,s=0;
    speed=1;
    x=0,y=0;
 }
 virtual void enemyfire(Bomb * b1)=0;
 virtual void enemymove()=0;
 virtual void enemyfiredel()=0;
 virtual ~Enemy(){
 };
};
#endif
