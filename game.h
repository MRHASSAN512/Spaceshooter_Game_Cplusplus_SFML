#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "menu.h"
#include <time.h>
#include <iostream>
#include <cstdlib> 
#include <cmath>
#include "Enemy.h"
#include "Bomb.h"
#include "player.h"
#include "Invaders.h"
#include "Monster.h"
#include "Dragon.h"
#include "Alpha.h"
#include "Beta.h"
#include "Gamma.h"
const char title[]="Space Shooter || OOP-Project, Spring-2023";
using namespace sf;
using namespace std;
class Game
{
public:
Sprite background,ui,ui1,ui2,ui3,ui4; //Game background sprite
Texture bg_texture,ui_texture,ui1_texture,ui2_texture,ui3_texture,ui4_texture;
Player* p;
Bomb * bomb; 
Enemy **en;
Invaders ***I;
Menu menu;
int r,Height,s,check,count,a,b,senemy,score,startX,level,wave,lives,
startY,startXtriangle,startYtriangle,startXcross,sbomb,
startYcross,gap,gap1,gap2,centerx,centery,killcount,nocount,angle,angleinc,colcheck,menucount;
float radius,rad;
bool fire,flagdragon,flagmonster,bulletdel,endscreen,stopfucntionality,closewid,drawstop,stopenemy;
Game()
{
//------------------PlAYER-----------------
p=new Player("img/PNG/playerShip2_blue.png");
bg_texture.loadFromFile("img/background1.jpg");
background.setTexture(bg_texture);
//------------------UI-----------------
ui_texture.loadFromFile("img/ui.png");
ui.setTexture(ui_texture);
ui.setScale(0.95,0.95);
ui.setPosition(-175,5);
ui1_texture.loadFromFile("img/ui1.png");
ui1.setTexture(ui1_texture);
ui1.setScale(0.95,0.95);
ui1.setPosition(785,5);
ui2_texture.loadFromFile("img/ui2.png");
ui2.setTexture(ui2_texture);
ui2.setScale(1,1);
ui2.setPosition(300,5);
ui3_texture.loadFromFile("img/ui3.png");
ui3.setTexture(ui3_texture);
ui3.setScale(1,1);
ui3.setPosition(-170,780);
ui4_texture.loadFromFile("gameend.png");
ui4.setTexture(ui4_texture);
ui4.setScale(1,1);
ui4.setPosition(0,0);

r=0,Height=70,s=0;
check=0,count=0,a=0,b=0,senemy=2,score=0;
startX=210; 
startY=160;  
startXtriangle=570;
startYtriangle=160;
startXcross=260;
startYcross=100;
gap=0,gap1=70,gap2=70; 
centerx=565;
centery=370;
killcount=0,nocount=0;
angle=0;
angleinc=360/15;
radius=240,rad=3.142/180;
level=1;
wave=1;
lives=5;
fire=false;
flagdragon=1;
flagmonster=1;
colcheck=0;
bulletdel=1;
sbomb=0;
endscreen=false;
stopfucntionality=false;
menucount=0;
closewid=false;
drawstop=false;
stopenemy=false;
I=new Invaders**[4];
en=new Enemy*[senemy];
bomb=nullptr;
} 
int display_menu()
{
  ++menucount;
  int a=menu.displaymenu();
  if(a==1)
  {
   start_game();
  }
  else if(a==1 && menucount>=2)
  {
    stopfucntionality=false;
  }
  else if(a==2)
  {
   stopfucntionality=false;
  }
  else if(a==3)
  {
   closewid=true;
  }
  stopfucntionality=false;
}
void start_game()
{
    srand(time(0));
    RenderWindow window(VideoMode(1200,877), title);
    Clock clock;
    float timer=0;
    float newtimer=0;
    float timeforpower=0;
    float shoottime=0;
    float firedelay=0.4f;
    int shootimealpha=0;
    int shootimebeta=0;
    int shootimegamma=0;        
    int firedelayalpha=5000;
    int firedelaybeta=3000;
    int firedelaygamma=2000;
    //int shootimemonster=0;
    //int firedelaymonster=2.0f;
    int shootimeaddon=0;        
    int firedelayaddon=6000;
    float newtime=3;
    float newtime1=30;
    //||||||||||||+++++++++++++++++++++++++++ENEMY MAKING INVADER++++++++++++++++++++++||||||||||||||||||||||//
    //------------------Enemy------------------------////////////----------////////
        
	for(int i=0 ; i<4 ; i++)
	{
            I[i]=new Invaders*[5];
            for(int j=0 ; j<5 ; j++)
	    {
	      I[i][j]=nullptr;
	    }
	}
        en[0]=new Monster("img/monster1.png");
        en[1]=new Dragon("img/dragon.png");
    //--------------------------------Adding background music------------------------------------------------//
         
          sf::Music music;
	  if(!music.openFromFile("Brave Pilots (Menu Screen).ogg"))
	  {
              std::cout<<"Music not opened"<<std::endl;
	  }
            music.setPosition(0, 1, 30);
	    music.setVolume(100);
	    music.setLoop(true);
	    music.play();
	 

       
       
  //---------------- WHILE LOOP STARTING---------------------------------------//  
    while (window.isOpen())
    {
        bool collided=false;
        float time = clock.getElapsedTime().asSeconds();
        float time2 = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time; 
        newtimer+=time; 
        Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed || closewid==true)
                 {
                  closewid=false;
        
                  window.close(); //close the game 
                 }       	    
        }
       if(music.getStatus()!=sf::Music::Playing)
	 {
	    music.play();
	 }
	sf::Font font;
        font.loadFromFile("Montserrat/static/Montserrat-Bold.ttf");
        sf::Text text,text1,text2;

        //-----------score--------------//
        text.setFont(font);
        text.setString(to_string(score));
        text.setPosition(117,45);
        text.setCharacterSize(28);
        text.setFillColor(sf::Color::White);
        
      	   
        
        //-----------level--------------//
        text1.setFont(font);
        text1.setString(std::to_string(level));
        text1.setPosition(180,823);
        text1.setCharacterSize(30);
        text1.setFillColor(sf::Color::White);
        
        
       //-----------Lives---------------//
        text2.setFont(font);
        text2.setString(to_string(lives));
        text2.setPosition(1083,45);
        text2.setCharacterSize(30);
        text2.setFillColor(sf::Color::White);
        
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
        if (Keyboard::isKeyPressed(Keyboard::H)) // If H key is pressed
             {
              stopfucntionality=true;
              display_menu();
             }
            
       if(!stopfucntionality)
       {
        //-----------------------------------------PLAYER FIRE--------------------------------------//
        if(Keyboard::isKeyPressed(Keyboard::Space) && shoottime<=0.0f)      
        {   
             p->fire();
             shoottime=firedelay;   
        } 
        else
        {
             shoottime=shoottime-time;
        }  
       //-------------------------------------------Bullet deleting-------------------------//     
        if(p->s>=1 && p->b[p->s].sprite.getPosition().y<0 && !(p->sprite.getPosition().y<0))
  	 {
  	      p->delbullet();
  	 }
       //------------------------------------------Bullet MOVE-------------------------------------//
         for(int i=0 ; i<p->s; i++)
         {
           p->b[i].bulletmove();
         }
         //--------------------DIAGONAL MOVE----------------------------------//
        if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Up))
           {
             p->enemytiltright();
           }
         else if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up))
           {
             p->enemytiltleft();
           } 
           else
           {
             p->enemystraight();
           } 
         //----------------------------------ADDON--------------------------------------------//
        if(shootimeaddon<=0.0)
         { 
           p->addoncalling();
           shootimeaddon=firedelayaddon; 
         }
         else
         {
           shootimeaddon=shootimeaddon-time;
         }
         if(p->addon[p->randno]!=nullptr)
         {
         p->addon[p->randno]->addonmove();
         }
         colcheck=p->checkaddoncollision();
         if(colcheck==1)
         {
            lives++;
         }
         else if(colcheck==2)
         {
           lives--;
         }
         else if(colcheck==3)
         { timeforpower=timer;
           bulletdel=false;
         }
         if(bulletdel==false){
         if((timer-timeforpower)>5.0){
            timeforpower=timer;
         	bulletdel=true;
         }}
         if(newtimer>newtime)
         {
           stopenemy=true;
           flagmonster=false;
         }
         if((newtimer-newtime)>5)
           {
             stopenemy=false;
             flagmonster=true;
             score+=50;
           }
         if(newtimer>newtime1)
         {
           stopenemy=true;
           flagdragon=false;
         }
         if((newtimer-newtime1)>5)
           {
             stopenemy=false;
             flagdragon=true;
                          score+=50;
           }

           if(!stopenemy)
           {
            //--------------------------------------LEVEL ENEMY CALLING--------------------------------//  
	      if(killcount==nocount)
		{
		  killcount=0;
		  if(level==1 && wave<=3)
		  {
		    if(wave==1)
		    {
		       enemyform();
		       rectangle();
		       nocount=20;
		    } 	 
		    else if(wave==2)		
		    {
		        enemyform();
		        circle();
		        nocount=15;
		    }
		    else if(wave==3)
		    {
		        enemyform();	   
		        crosssign();
		        nocount=13; 
		        
		    }
		    wave++; 
			  
                 if(level==1 && wave>3)
			{
		          level++;
			  wave=1;
			}
                  
		}
	        
		else if(level==2 && wave<=3)
		{

		    if(wave==1)
		    {    
		        enemyform();   
                        triangle();
		        nocount=17; 
		    }
		    else if(wave==2)
		    {
		        enemyform();
		        diamond();
		        nocount=10; 
		    }
		    else if(wave==3)
		    { 
		        enemyform();       
		        heart();
		        nocount=14; 	 
		    }
		   wave++;
		}
	    }
//---------------------------------------------------EnemyFIRE---------------------------------------//
 
               for(int i=0 ;i<4 ; i++)
		{
		 for(int j=0 ; j<5  ;j++)
		   {
		    if(I[i][j]!=nullptr)
		    {
		    if(dynamic_cast<Alpha*>(I[i][j])!=nullptr)
		      {  
			if(shootimealpha<=0.0)
	                 {   
                            bombcalling(i,j);
                            I[i][j]->enemyfire(&bomb[sbomb-1]);
			    shootimealpha=firedelayalpha;
                         }
			 else
			 {
			  shootimealpha=shootimealpha-time2;
			 }
                       }
                       else if(dynamic_cast<Beta*>(I[i][j])!=nullptr)
		       {
		         if(shootimebeta<=0.0)
			 {
			    bombcalling(i,j);
                            I[i][j]->enemyfire(&bomb[sbomb-1]);
			    shootimebeta=firedelaybeta;
                         }
			 else
			 { 
			   shootimebeta=shootimebeta-time2;
			 }
		       }
		       else if(dynamic_cast<Gamma*>(I[i][j])!=nullptr)
		       {
			  if(shootimegamma<=0.0)
			 {
			    bombcalling(i,j);
                            I[i][j]->enemyfire(&bomb[sbomb-1]);
			    shootimegamma=firedelaygamma;
			    		       fire=true;
                         }
			 else
			 { 
			   shootimegamma=shootimegamma-time2;
			 }	        		        
		       }
		       }
                     }
                  }
                  for(int k=0 ; k<sbomb ; k++)
	          {
		    bomb[k].bombmove();			      
	          }
                 if(sbomb>0)
	          {
	          if(bomb[sbomb-1].sprite.getPosition().y>=900)
		           {	     
	                    sbomb--;
	                    Bomb* o = new Bomb[sbomb];
			    for (int i= 0; i<sbomb ; i++) 
			    {
			      o[i]=bomb[i];
			    }
                            delete [] bomb;
                            bomb=new Bomb[sbomb];
                            
                            for(int i=0 ; i<sbomb ;i++)
                            {
                             bomb[i]=o[i];
                            }    
                            
                            delete [] o;
                            o=nullptr;
		           }
		         } 
 //------------------------------Enemy+MOVE-------------------------------------//  
          for(int i=0 ;i<4 ; i++)
          {
	     for(int j=0 ; j<5  ;j++)
	      {
		if(I[i][j]==nullptr)
                 { 
                   continue;
                 }
                 else
                 {
                   I[i][j]->enemymove();
                 }
	      }
          } 
                 
	//-----------------------------------------Collision-----------------------------//
	if(p->s>0)
	{
	 for(int i=0 ;i<4 ; i++)
		{
		   for(int j=0 ; j<5  ;j++)
		   {
		    for(int k=0; k<p->s; k++)
		     {
                        if(I[i][j]!=nullptr && p->b[k].sprite.getPosition().x>=I[i][j]->sprite.getPosition().x && p->b[k].sprite.getPosition().x<=I[i][j]->sprite.getPosition().x+I[i][j]->sprite.getTexture()->getSize().x && p->b[k].sprite.getPosition().y+p->b[k].sprite.getTexture()->getSize().y>=I[i][j]->sprite.getPosition().y && p->b[k].sprite.getPosition().y<=I[i][j]->sprite.getPosition().y+I[i][j]->sprite.getTexture()->getSize().y )
			    { 
			        killcount++; 
			        
                                if(dynamic_cast<Alpha*>(I[i][j])!=nullptr)
                                {
                                   score+=10*level;
                                }
                                else if(dynamic_cast<Beta*>(I[i][j])!=nullptr)
                                {
                                   score+=20*level;
                                }
                                else if(dynamic_cast<Gamma*>(I[i][j])!=nullptr)
                                {
                                   score+=30*level;
                                }
                                if(I[i][j]!=nullptr)
                                {
                                 delete I[i][j];
                                 I[i][j]=nullptr;
                                }
                               
                                if(bulletdel==true)
                                {
                                 if(p->b!=nullptr)
                                 {
                                 p->b[k].sprite.setPosition(-1,-100);
                                 }
                                }
                                
			     }
			 }     
		     }
		 }
	    }
	 for(int i=0; i<4 ; i++)
		{
		   for(int j=0 ; j<5  ;j++)
		   {
	           	if(I[i][j]!=nullptr && p->sprite.getPosition().x<I[i][j]->sprite.getPosition().x+I[i][j]->sprite.getTexture()->getSize().x && p->sprite.getPosition().x+p->sprite.getTexture()->getSize().x>I[i][j]->sprite.getPosition().x && p->sprite.getPosition().y<I[i][j]->sprite.getPosition().y+I[i][j]->sprite.getTexture()->getSize().y && p->sprite.getPosition().y+p->sprite.getTexture()->getSize().y>I[i][j]->sprite.getPosition().y) 
		     {

		        killcount++; 
		        delete I[i][j];
                        I[i][j]=nullptr;
                       
                        lives--;
                        
                        
                        if(lives==0)      
                        {
                         p->sprite.setPosition(600,-10000);
                        } 
		     }
		   }
                 } 
          if(sbomb>0)
          {
           for(int k=0 ; k<sbomb ; k++)
                   {
                      if(p->sprite.getPosition().x<bomb[k].sprite.getPosition().x+bomb[k].sprite.getTexture()->getSize().x&&p->sprite.getPosition().x+p->sprite.getTexture()->getSize().x>bomb[k].sprite.getPosition().x&&p->sprite.getPosition().y< bomb[k].sprite.getPosition().y+bomb[k].sprite.getTexture()->getSize().y&&p->sprite.getPosition().y+p->sprite.getTexture()->getSize().y>bomb[k].sprite.getPosition().y) 
           {
            collided = true;
            bomb[k].sprite.setPosition(0,950);
            break;
           }
         }
	if(collided) 
	{
	    lives--;
	    collided=false;
	} 

	}  
	}   
         //------------------------------MONSTER---------------------------------------//
        else if(!flagmonster)
         {
           en[0]->sprite.setScale(0.5,0.5);
           en[0]->sprite.setPosition(440,155);
                          en[0]->sprite.move(0,1);
            bombcall();
            enemycollide();               
         }
         else if(!flagdragon)
         {
           en[1]->sprite.setScale(1.3,1.3);
           en[1]->sprite.setPosition(455,130);
             en[1]->enemymove();
             bombcall();
             enemycollide();
         }
         
	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
	for(int i=0 ;i<p->s ; i++)
	{
          window.draw(p->b[i].sprite);
	}
	if(!flagmonster)
	{
	  window.draw(en[0]->sprite);
	}
	if(!flagdragon)
	{
	  window.draw(en[1]->sprite);
	}
	if(p->addon[p->randno]!=nullptr)
        {
          window.draw(p->addon[p->randno]->sprite);
        }
	if(!stopenemy)
	{
	        for(int i=0 ;i<4 ; i++)
		{
		   for(int j=0 ; j<5  ;j++)
		   {
		     if(I[i][j]!=nullptr)
		     {
		      window.draw(I[i][j]->sprite); 
		     }
		   }
		}  
 
	 }
	 for(int i=0; i<sbomb; i++)
		{
		 window.draw(bomb[i].sprite);  
		}  
/*else if(flagdragon)
	{
          window.draw(dragon.sprite);
	}*/
	window.draw(p->sprite);
	window.draw(ui3); 	
        window.draw(ui2); 	
        window.draw(ui1); 
        window.draw(ui); 
	window.draw(text);
        window.draw(text1);
        window.draw(text2); 
        if(lives==0 || (level==2 && wave>3))
        {

          window.draw(ui4);
        }
	window.display();
	

    }
   }
    

}
void enemycollide()
{
   
   if(p->sprite.getPosition().x<bomb[0].sprite.getPosition().x+bomb[0].sprite.getTexture()->getSize().x&&p->sprite.getPosition().x+p->sprite.getTexture()->getSize().x>bomb[0].sprite.getPosition().x&&p->sprite.getPosition().y< bomb[0].sprite.getPosition().y+bomb[0].sprite.getTexture()->getSize().y&&p->sprite.getPosition().y+p->sprite.getTexture()->getSize().y>bomb[0].sprite.getPosition().y) 
           {
            p->sprite.setPosition(350,800);
	    lives-=2;
	    return;
           }
	
}
void bombcall()
{
          delete [] bomb;
	  bomb=nullptr;
	  sbomb=1;
          bomb = new Bomb[sbomb]; 
          bomb[sbomb-1].tex.loadFromFile("Laser1.png");
          bomb[sbomb-1].sprite.setTexture(bomb[0].tex);  
          bomb[sbomb-1].sprite.setPosition(en[0]->sprite.getPosition().x+140,en[0]->sprite.getPosition().y+255);
          bomb[sbomb-1].sprite.setScale(1,1);
}
void rectangle()
{
                 for(int j=0; j<5 ; j++)
			{
			   I[0][j]->sprite.setPosition(startX+gap,startY);
			   gap+=120;   
			}    
			I[1][0]->sprite.setPosition(startX+gap,startY); 
			gap+=120;
			I[1][1]->sprite.setPosition(startX+gap,startY); 
			//--------------------------------------Hollow----------------------------------------//
			I[1][2]->sprite.setPosition(startX,startY+Height);
			I[1][3]->sprite.setPosition(startX+720,startY+Height); 
			Height+=70;
			I[1][4]->sprite.setPosition(startX,startY+Height);
			I[2][0]->sprite.setPosition(startX+720,startY+Height); 
			Height+=70;
			I[2][1]->sprite.setPosition(startX,startY+Height);
			I[2][2]->sprite.setPosition(startX+720,startY+Height); 
			Height+=70;
			//-------------------------------------2nd Line--------------------------------------//
			I[2][3]->sprite.setPosition(startX,startY+Height);
			gap=120;
			I[2][4]->sprite.setPosition(startX+gap,startY+Height);
			gap+=120;
			for(int j=0; j<5 ; j++)
			{
			      I[3][j]->sprite.setPosition(startX+gap,startY+Height);
			      gap+=120;
			}
			    
}
void circle()
{
                   for(int i=0 ; i<3 ; i++)
			{
			  for(int j=0; j<5; j++)
			    {   
			       a=centerx+radius*cos(angle*rad);
			       b=centery+radius*sin(angle*rad);
			       I[i][j]->sprite.setPosition(a,b);
			       angle+=angleinc;
			    }
			 } 
		 
                     for(int j=0; j<5; j++)
	            {
	                if(I[3][j]!=nullptr)
	                {
	                delete I[3][j];
			I[3][j]=nullptr;
			}			     
		    }
}
void crosssign()
{
  //-----------------------------------------Cross Sign-----------------------------------------------------//     
            
                for(int j=0; j<5; j++)
			    {   
			        I[0][j]->sprite.setPosition(startXcross,startYcross);
			        startXcross+=1.5*gap2;
			        startYcross+=gap2;
                            }
                 for(int j=0; j<2; j++)
		 {   
		   I[1][j]->sprite.setPosition(startXcross,startYcross);
	           startXcross+=gap2;
		   startYcross+=1.3*gap2;
                 }
                  
                 startXcross=330+7.5*gap2;
                 startYcross=100;
                 for(int j=2; j<5; j++)
		 { 
		   I[1][j]->sprite.setPosition(startXcross,startYcross);
	           startXcross-=1.3*gap2;
		   startYcross+=gap2;
		 }
                 startXcross-=1.4*gap2;
		 startYcross+=1.3*gap2-25;
                 for(int j=0; j<3; j++)
			    {   
			       I[2][j]->sprite.setPosition(startXcross,startYcross);
			       startXcross-=1.5*gap2;
		               startYcross+=1.2*gap2;
                            }
                for(int j=3; j<5; j++)
		{  
		      if(I[2][j]!=nullptr)
		      {
		         I[2][j]=nullptr;
		      }     
                }    
                for(int j=0; j<5; j++)
		{  
                      if(I[3][j]!=nullptr)
		      {
		         I[3][j]=nullptr;
		      } 
                } 
}
void triangle()
{
    //-----------------------------------------Triangle-----------------------------------------------------//
                         for(int j=0; j<5; j++)
			    {   
			        I[0][j]->sprite.setPosition(startXtriangle,startYtriangle);
			        startXtriangle+=gap1;
			        startYtriangle+=gap1;
                            }
                         
                 startXtriangle=570-gap1;
		 startYtriangle=160+gap1;       
                 for(int j=0; j<5; j++)
			    {   
			        I[1][j]->sprite.setPosition(startXtriangle,startYtriangle);
			        startXtriangle-=gap1;
			        startYtriangle+=gap1;
                            }
                 startXtriangle+=2.3*gap1;
                 startYtriangle-=gap1;
                 for(int j=0; j<5; j++)
			    {   
			        I[2][j]->sprite.setPosition(startXtriangle,startYtriangle);
			        startXtriangle+=1.4*gap1;
                            }          
               	 I[3][0]->sprite.setPosition(startXtriangle,startYtriangle);
               	 			        startXtriangle+=1.4*gap1;
               	 I[3][1]->sprite.setPosition(startXtriangle,startYtriangle);
               	 
               	 
               	 for(int j=2 ; j<5 ; j++)
               	 {
               	     if(I[3][j]!=nullptr)
               	     {
               	     delete I[3][j];
               	     I[3][j]=nullptr;
               	     }
               	 }
}

void diamond()
{
   //=-=-=-=-=-=-=-=-=----------------Diamond-----------------------------------------------=-=-=-=-=-=-=-=-=//	 
    		 	startXtriangle=570;
    		 	startYtriangle=160;
                           for(int j=0; j<3; j++)
			    {   
			        I[0][j]->sprite.setPosition(startXtriangle,startYtriangle);
			        startXtriangle+=gap1;
			        startYtriangle+=gap1;
                            }
                         
                          startXtriangle=570-gap1;
		          startYtriangle=160+gap1;       
                         for(int j=3; j<5; j++)
			    {   
			        I[0][j]->sprite.setPosition(startXtriangle,startYtriangle);
			        startXtriangle-=gap1;
			        startYtriangle+=gap1;
                            }	
                          startXtriangle+=gap1; 
                         for(int j=0; j<3; j++)
			    {   
			        I[1][j]->sprite.setPosition(startXtriangle,startYtriangle);
			        startXtriangle+=gap1;
			        startYtriangle+=gap1;
                            }  
                          startXtriangle=640+gap1;
		          startYtriangle=300+gap1;   
                         for(int j=3; j<5; j++)
			    {   
			        I[1][j]->sprite.setPosition(startXtriangle,startYtriangle);
			        startXtriangle-=gap1;
			        startYtriangle+=gap1;
                            } 
                            
                            for(int i=2; i<4; i++)
                            {
                              for(int j=0; j<5; j++)
                              { if(I[i][j]!=nullptr)
                                {
                                delete I[i][j];
                                I[i][j]=nullptr;
                                }
                              }
                            }
}
void heart()
{
  //=-=-=-=-=-=-=-=-=----------------HEART--------------------------------------------=-=-=-=-=-=-=-=-=//	  	
               I[0][0]->sprite.setPosition(570,160);
               I[2][4]->sprite.setPosition(startXtriangle,startYtriangle);
                for(int j=1; j<3; j++)
		 {   
			I[0][j]->sprite.setPosition(startXcross,startYcross);
			startXcross+=2*gap2;
                 }
                 startXcross+=3*gap2;
                 for(int j=3; j<5; j++)
		 {   
			I[0][j]->sprite.setPosition(startXcross,startYcross);
			startXcross+=2*gap2;
                 }
                 I[1][0]->sprite.setPosition(startXcross-gap2,startYcross+gap2);
                 startXcross=260;
                 startYcross=100;
                 I[1][1]->sprite.setPosition(startXcross-gap2,startYcross+gap2);
                 startYcross+=140;
                 for(int j=2; j<5; j++)
			    {   
			        I[1][j]->sprite.setPosition(startXcross,startYcross);
			        startXcross+=1.2*gap2;
			        startYcross+=1.5*gap2;
                            }
                 startXcross=260+9*gap2;
                 startYcross=240;
                 for(int j=0; j<3; j++)
		 { 
		   I[2][j]->sprite.setPosition(startXcross,startYcross);
	           startXcross-=1.2*gap2;
		   startYcross+=1.5*gap2;
		 }    
		 I[2][3]->sprite.setPosition(startXtriangle,startYtriangle+400);   
               
		   for(int j=0; j<5; j++)
		 {
		     if(I[3][j]!=nullptr)
		     {
		     delete I[3][j];
		     I[3][j]=nullptr;
		     }
		 }
}
void enemyform()
{
     for (int i = 0; i < 4; i++) {
     for (int j = 0; j < 5; j++) {
         r = rand() % 16;

         if (check != r) {
             s = rand() % 3;
             if (s == 0)
                 I[i][j] = new Alpha("img/alpha.png");
             else if (s == 1)
                 I[i][j] = new Beta("img/beta.png");
             else
                 I[i][j] = new Gamma("img/gamma.png");

             check = r;
         } else {
             j--;
         }
     }
 }
}
void bombcalling(int a, int b)
{

int a1= sbomb;
sbomb++;
Bomb *o = new Bomb[sbomb];
for (int k = 0; k < a1; k++)
  {
    o[k] = bomb[k];
  }

o[sbomb - 1].tex.loadFromFile ("img/enemy_laser.png");
o[sbomb - 1].sprite.setTexture (o[sbomb - 1].tex);
o[sbomb - 1].sprite.setPosition (I[a][b]->sprite.getPosition ().x + 25,
				 I[a][b]->sprite.getPosition ().y + 42);
o[sbomb - 1].sprite.setScale (1, 1);

delete[]bomb;
bomb = new Bomb[sbomb];

for (int i = 0; i < sbomb; i++)
  {
    bomb[i] = o[i];
  }

			    //delete [] o;
o = nullptr;

}

~Game()
{
 for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(I[i][j]!=nullptr)
            {
            delete I[i][j];
            }
        }
        if(I[i]!=nullptr)
        {
        delete[] I[i];
        }
    }
    delete[] I;
   delete [] en;
  delete [] bomb;	
}	    

};
