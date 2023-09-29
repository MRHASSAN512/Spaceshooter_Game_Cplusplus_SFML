#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Level{
public:
int level;
int wave;
Level()
{
  level=0;
  wave=0;
}
Level(int a,int b)
{
  level=a;
  wave=b;
}
void Level1()
{
  if(wave==1)
  {
    //-----------------------------------------RECTANGLE-------------------------------//
			//------------------1st Line-------------------------------------------------------//
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
  else if(wave==2)
  {
   //-----------------------------------------CIRCLE-----------------------------------------------------//
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
			I[3][j]=nullptr;			     
		    }
  }
  else if(wave==3)
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
		         I[2][j]=nullptr;   
                }    
                for(int j=0; j<5; j++)
		{  
		         I[3][j]=nullptr;   
                }  
  }
}
void Level2()
{
  if(wave==1 && level==2)
   {//-----------------------------------------Triangle-----------------------------------------------------//
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
               	     I[3][j]=nullptr;
               	 }
    }
    if(wave==2 && level==2)
   {
    //=-=-=-=-=-=-=-=-=----------------Diamond-----------------------------------------------=-=-=-=-=-=-=-=-=//	 
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
                              { 
                                I[i][j]=nullptr;
                              }
                            }
      }
     if(wave==3 && level==2)
    {                      
     //=-=-=-=-=-=-=-=-=----------------HEART--------------------------------------------=-=-=-=-=-=-=-=-=//	  	
               I[0][0]->sprite.setPosition(startXtriangle,startYtriangle);
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
                 cout<<startYcross;
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
		 I[2][4]=nullptr; 
               
		   for(int j=0; j<5; j++)
		 {
		     I[3][j]=nullptr;
		 }
		 }
}
};
#endif

