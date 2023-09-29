#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include<string.h>
#include<cstdlib>
#include"Addon.h"
#include"Lives.h"
#include"Danger.h"
#include"Fire.h"
#include"Powerup.h"
#include"bullet.h"
using namespace sf;
class Player{
public:
Texture tex;
Sprite sprite;
float speed;
Bullet *b;
Addon **addon;
int x,y,s,s1,randno;
int count;
Player(std::string png_path)
{
srand(time(0));
tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=500;y=700;
sprite.setPosition(x,y);
sprite.setScale(1,1);
speed=30;
s=0,s1=4;
count=0;
b=nullptr;
addon=new Addon*[s1];
for(int i=0 ; i<s1 ; i++)
{
   addon[i]=nullptr;
}
}
void addoncalling()
{
  randno=rand()%4;
  addon[0]=new Lives("img/addon1.png"); 
  addon[1]=new Danger("img/addon2.png"); 
  addon[2]=new Fire("img/addon3.png"); 
  addon[3]=new Powerup("img/addon4.png");
 
}
void enemytiltright()
{
    tex.loadFromFile("img/2.png");
    sprite.setTexture(tex);
    sprite.setScale(1.20,1.20);
    speed=0.2;
    move("u");
    move("r");
    count=1;
} 
void enemytiltleft()
{
    tex.loadFromFile("img/1.png");
    sprite.setTexture(tex);
    sprite.setScale(1.20,1.20);
    speed=0.2;
    move("u");
    move("l");
    count=2;
} 
void enemystraight()
{
   tex.loadFromFile("img/PNG/playerShip2_blue.png");
   sprite.setTexture(tex);
   sprite.setScale(1,1);
   speed=0.6;
   count=0;
}
int checkaddoncollision()
{
     if(addon[randno]!=nullptr && sprite.getPosition().x<addon[randno]->sprite.getPosition().x+addon[randno]->sprite.getTexture()->getSize().x && sprite.getPosition().x+sprite.getTexture()->getSize().x>addon[randno]->sprite.getPosition().x && sprite.getPosition().y<addon[randno]->sprite.getPosition().y+addon[randno]->sprite.getTexture()->getSize().y && sprite.getPosition().y+sprite.getTexture()->getSize().y>addon[randno]->sprite.getPosition().y)
     {
          if(dynamic_cast<Lives*>(addon[randno])!=nullptr)
	  {
	    delete addon[randno];
	    addon[randno]=nullptr;
	    return 1;
	  }
	  else if(dynamic_cast<Danger*>(addon[randno])!=nullptr)
	  {
	    delete addon[randno];
	    addon[randno]=nullptr;
	    return 2;
	  }
	  else if(dynamic_cast<Fire*>(addon[randno])!=nullptr)
	  {
	    delete addon[randno];
	    addon[randno]=nullptr;
	    return 3;
	  }
	  else if(dynamic_cast<Powerup*>(addon[randno])!=nullptr)
	  {  
	    delete addon[randno];
	    addon[randno]=nullptr;
	    return 4;
	  }
     }
     return 0;
}
void fire()
{  

   int a=s;
   s++;
   
   Bullet *o=new Bullet[s];
   
   for(int i=0 ; i<a; i++)
   {
      o[i]=b[i];
   }

   if(count==1)
     {
        o[s-1].tex.loadFromFile("img/image(1).png");
        o[s-1].sprite.setTexture(o[s-1].tex);
        o[s-1].sprite.setPosition(sprite.getPosition().x+36,sprite.getPosition().y+20);
        o[s-1].sprite.setScale(0.75,0.75);
        o[s-1].count=1;
     } 
    else if(count==2)
      {
          o[s-1].tex.loadFromFile("img/image.png");
          o[s-1].sprite.setTexture(o[s-1].tex);
          o[s-1].sprite.setPosition(sprite.getPosition().x+36,sprite.getPosition().y-10);
          o[s-1].sprite.setScale(0.75,0.75);
          o[s-1].count=2;
      } 
   else if(count==0)
      {
          o[s-1].tex.loadFromFile("img/PNG/Lasers/laserBlue16.png");
          o[s-1].sprite.setTexture(o[s-1].tex);
          o[s-1].sprite.setPosition(sprite.getPosition().x+51,sprite.getPosition().y);
          o[s-1].sprite.setScale(0.75,0.75);
          o[s-1].count=0;
      }
   
   if(b!=nullptr)
   {
    delete [] b;
    b=nullptr;
   }
   b=new Bullet[s];
   
   
   for(int i=0; i<s; i++)
   {
      b[i]=o[i];
   }
   
     //delete [] o;
     o=nullptr;
     
}
void delbullet()
{
   if(s<=0)
   return;
      
   
    Bullet *o=new Bullet[s];
    for(int i=0 ; i<s; i++)
    {
      o[i]=b[i];
    }

   
    delete [] b;
    b=nullptr;
   
    b=o;
}
void move(std::string s)
{
float delta_x=0,delta_y=0;
if(s=="l")
	{delta_x=-1;
	if(anamolyl())
        sprite.setPosition(1200,sprite.getPosition().y);
        }
else if(s=="r")
	{delta_x=1;
	if(anamolyr())
        sprite.setPosition(-112,sprite.getPosition().y);}
if(s=="u")
	{delta_y=-1;
	/*if(anamolyu())
        sprite.setPosition(sprite.getPosition().x,0);*/}
else if(s=="d")
	{delta_y=1;
	if(anamolyd())
        sprite.setPosition(sprite.getPosition().x,800);}

 delta_x*=speed;
 delta_y*=speed;

    
sprite.move(delta_x, delta_y);

}

bool anamolyr()
{
   if(sprite.getPosition().x>1200) 
   {
       return 1;
   }
   else
   return 0;
   
}
bool anamolyl()
{
   if(sprite.getPosition().x<=-112  )
   {
       return 1;
   }
   else
   return 0;
   
}
bool anamolyd()
{
   if(sprite.getPosition().y>=800)
   {
       return 1;
   }
   else
   return 0;
   
}
/*bool anamolyu()
{
   if(sprite.getPosition().y<=0)
   {
       return 1;
   }
   else
   return 0;
   
}
*/
~Player()
{
  
  if(b!=nullptr)
  {
   delete [] b;
   b=nullptr;
  }
   for(int i=0; i<4; i++)
   {
    if(addon[i]!=nullptr)
    {
     delete addon[i];
    addon[i]=nullptr;
    }
    
   }
   
   delete [] addon;
   
}
};
#endif
