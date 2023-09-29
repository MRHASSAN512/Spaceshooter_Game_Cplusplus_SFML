#include <SFML/Graphics.hpp>
//#include "game.h"
using namespace sf;
using namespace std;
const char menutitle[]="Space Shooter Menu || OOP-Project, Spring-2023";
class Menu{
public:
Sprite background,ui,ui_1,ui_2,ui_3,ui_4,ui_5,ui2; //Game background sprite
Texture tx,ui_texture,ui_1_texture,ui_2_texture,ui_3_texture,ui_4_texture,ui_5_texture,ui2_texture;
//Game g;
int x,y;
bool inst,closewid;
Menu()
{
tx.loadFromFile("Start game.png");
background.setTexture(tx);
//background.setScale(5,5);
ui2_texture.loadFromFile("img/ui2.png");
ui2.setTexture(ui2_texture);
ui2.setScale(1,1);
ui2.setPosition(300,5);
ui_texture.loadFromFile("ui.png");
ui.setTexture(ui_texture);
ui.setScale(0.75,0.75);
ui.setPosition(370,250);
ui_1_texture.loadFromFile("ui_1.png");
ui_1.setTexture(ui_1_texture);
ui_1.setScale(0.75,0.75);
ui_1.setPosition(370,350);
ui_2_texture.loadFromFile("ui_2.png");
ui_2.setTexture(ui_2_texture);
ui_2.setScale(0.75,0.75);
ui_2.setPosition(370,450);
ui_3_texture.loadFromFile("ui_3.png");
ui_3.setTexture(ui_3_texture);
ui_3.setScale(0.75,0.75);
ui_3.setPosition(370,550);
ui_4_texture.loadFromFile("instructions.png");
ui_4.setTexture(ui_4_texture);
ui_4.setScale(1,1);
ui_4.setPosition(0,0);

x=y=0;
inst=false;
closewid=false;
}
int displaymenu()
{
     RenderWindow window(VideoMode(1200,877), menutitle);
     while(window.isOpen())
    { 
       Event e;
       while (window.pollEvent(e))
       {  
            if (e.type==Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape) || closewid==true)
                 {
                  closewid=false;
                  window.close(); //close the game            
                 }  
                      	    
        }
        if(e.type==sf::Event::MouseButtonPressed && e.mouseButton.button==sf::Mouse::Left)
        {
            x=e.mouseButton.x;
            y=e.mouseButton.y;
            
           if(inst==false)
           {
            sf::FloatRect imageBounds=ui.getGlobalBounds();
            if(imageBounds.contains(x,y))
            {
              return 1;
            }
            sf::FloatRect imageBounds1=ui_1.getGlobalBounds();
            if(imageBounds1.contains(x,y))
            {
              return 2;
            }
            sf::FloatRect imageBounds2=ui_2.getGlobalBounds();
            if(imageBounds2.contains(x,y))
            {
               inst=true;
            }
            sf::FloatRect imageBounds3=ui_3.getGlobalBounds();
            if(imageBounds3.contains(x,y))
            { 
                closewid=true;
                return 3;
            }
           } 
           
        }
        if(Keyboard::isKeyPressed(Keyboard::Backspace))
            {
               inst=false;
            }
        
      
      window.clear(Color::Black); 
      window.draw(background);
      window.draw(ui);
      window.draw(ui_1);
      window.draw(ui_2);
      window.draw(ui_3);
      window.draw(ui2);
      if(inst==true)
      {
       window.draw(ui_4);
      }
      window.display();
    }

     // add functionality of all the menu options here
 
     //if Start game option is chosen 
    
   // g.start_game();



}
~Menu(){}

};
