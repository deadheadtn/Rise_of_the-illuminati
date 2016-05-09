#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "stdio.h"
#include <string.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <SDL/SDL_mixer.h>


const int fenetre_WIDTH = 1300;
const int fenetre_HEIGHT = 700;
const int fenetre_BPP = 32;
const int FRAMES_PER_SECOND = 50;
SDL_Surface *background = NULL,*imageDeFondCollision=NULL;
SDL_Surface *fenetre = NULL;
SDL_Event event;

void option()
{
    SDL_Surface *imageDeFond =NULL,*imageoption=NULL,*texte = NULL,*texte1 = NULL,*texte2 = NULL, *fenetre=NULL;
    SDL_Rect pos,option,positiononoff,positionres1,positionres2;
    SDL_Event e; 
    SDL_Init(SDL_INIT_VIDEO);
    fenetre = SDL_SetVideoMode(1300, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    int a=0,b=0,c=0;
    SDL_Event event;
    TTF_Font *police = NULL;
    TTF_Init();
    police = TTF_OpenFont("western.ttf", 32);
    SDL_Color noir = {0, 0, 0};
    int compteur = 1; 
    imageDeFond = IMG_Load("Menu/fond.bmp");
    imageoption = IMG_Load("Menu/option.jpg");
    positiononoff.x= 620;
    positiononoff.y= 240;
    positionres1.x=620;
    positionres1.y=280;
    positionres2.x=620;
    positionres2.y=320;
    // positionres3.x=;
    // positionres3.y=;
    // positionres4.x=;
    // positionres4.y=;
    pos.x =0; 
    pos.y =0;
    option.x=380;
    option.y=100;

    SDL_Event event1;
    texte = TTF_RenderText_Blended(police, "On", noir);
    texte1 = TTF_RenderText_Blended(police, "1200x700", noir);
    texte2 = TTF_RenderText_Blended(police, "Window Mode", noir);
    while(compteur != 0) 
    {
        SDL_WaitEvent(&event1);
        if(event1.key.keysym.sym == SDLK_ESCAPE) 
            compteur =0;
    switch (event1.type) 
    {
            case SDL_MOUSEBUTTONUP :
                 if (event1.button.button == SDL_BUTTON_LEFT)
                      {
                        if (positiononoff.x <= event1.button.x && event1.button.x <= positiononoff.x + texte->w && positiononoff.y <= event1.button.y && event1.button.y <= positiononoff.y + texte->h)
                        {
                            if(a==0){
                            texte = TTF_RenderText_Blended(police, "OFF", noir);
                            Mix_Volume(0,0);
                            a++;
                            }
                            else if (a==1)
                            {
                                texte = TTF_RenderText_Blended(police, "On", noir);
                                Mix_Volume(0,MIX_MAX_VOLUME/2);
                                a=0;
                            }
                        }
                        else if (positionres1.x <= event1.button.x && event1.button.x <= positionres1.x + texte1->w && positionres1.y <= event1.button.y && event1.button.y <= positionres1.y + texte1->h)
                        {
                            if(b==0){
                                texte1 = TTF_RenderText_Blended(police, "800x600", noir);
                                fenetre = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                                b++;
                            }
                            else if (b==1)
                            {
                                texte1 = TTF_RenderText_Blended(police, "1200x700", noir);
                                fenetre = SDL_SetVideoMode(1200, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                                b=0;
                            }
                        }
                        else if (positionres2.x <= event1.button.x && event1.button.x <= positionres2.x + texte2->w && positionres2.y <= event1.button.y && event1.button.y <= positionres2.y + texte2->h)
                        {
                            if(c==0){
                                texte2 = TTF_RenderText_Blended(police, "Full Screen", noir);
                                fenetre = SDL_SetVideoMode(1200, 700, 32, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF);
                                c++;
                            }
                            else if (c==1)
                            {
                                texte2 = TTF_RenderText_Blended(police, "Window Mode", noir);
                                fenetre = SDL_SetVideoMode(1200, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                                c=0;
                            }
                        }
                    }
    }  
    SDL_BlitSurface(imageDeFond, NULL, fenetre, &pos);
    SDL_BlitSurface(imageoption, NULL, fenetre, &option);
    SDL_BlitSurface(texte, NULL, fenetre, &positiononoff);
    SDL_BlitSurface(texte1, NULL, fenetre, &positionres1);
    SDL_BlitSurface(texte2, NULL, fenetre, &positionres2);
    SDL_Flip(fenetre);
    }       
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(imageDeFond);
}


int Pmenu(int *action)
{
    SDL_Surface *fenetre = NULL,*bouton11 = NULL, *bouton22 = NULL, *bouton33 = NULL, *bouton44 = NULL, *bouton55 = NULL,*bouton555=NULL,*bouton444=NULL,*bouton333=NULL,*bouton222=NULL,*bouton111=NULL, *imageDeFond = NULL, *bouton1 = NULL, *bouton2 = NULL, *bouton3 = NULL, *bouton4 = NULL, *bouton5 = NULL, *texte = NULL;
    SDL_Rect positionFond, positionBouton1, positionBouton2, positionBouton3, positionBouton4, positionBouton5, positionTexte;
    Mix_Chunk *son_bouton, *son_fond;
    int ok = 1, buttonpos=0, nb_press_b1=0, nb_press_b2=0, nb_press_b3=0, nb_press_b4=0, nb_press_b5=0;
    SDL_Event event;
    //TTF_Font *police = NULL;
    SDL_Color noir = {0, 0, 0};
    positionFond.x = 0;
    positionFond.y = 0;
    positionBouton1.x = 15;
    positionBouton1.y = 50;
    positionBouton2.x = 15;
    positionBouton2.y = 200;
    positionBouton3.x = 15;
    positionBouton3.y = 350;
    positionBouton4.x = 15;
    positionBouton4.y = 500;
    positionBouton5.x = 15;
    positionBouton5.y = 650;
    positionTexte.x= 350;
    positionTexte.y= 100;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_EnableKeyRepeat (300,300);
    //TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    //FPS_Initial();
    //FPS_Fn();

    fenetre = SDL_SetVideoMode(1300, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
 
    //police = TTF_OpenFont("Font/western.ttf", 32);
    imageDeFond = IMG_Load("Menu/fond.bmp");
    bouton1 = IMG_Load("Menu/bouton1.png");
    bouton2 = IMG_Load("Menu/bouton2.png");
    bouton3 = IMG_Load("Menu/bouton3.png");
    bouton4 = IMG_Load("Menu/bouton4.png");
    bouton5 = IMG_Load("Menu/bouton5.png");
    bouton11 = IMG_Load("Menu/bouton11.png");
    bouton22 = IMG_Load("Menu/bouton22.png");
    bouton33 = IMG_Load("Menu/bouton33.png");
    bouton44 = IMG_Load("Menu/bouton44.png");
    bouton55 = IMG_Load("Menu/bouton55.png");
    bouton111=bouton1;
    bouton222=bouton2;
    bouton333=bouton3;
    bouton444=bouton4;
    bouton555=bouton5;
    //texte = TTF_RenderText_Blended(police, "", noir);
    Mix_AllocateChannels(2);
    Mix_Volume(0, MIX_MAX_VOLUME);
    son_bouton = Mix_LoadWAV("Menu/Son/button.wav");
    son_fond = Mix_LoadWAV("Menu/Son/fond.wav");
    Mix_VolumeChunk(son_bouton, MIX_MAX_VOLUME);
    Mix_VolumeChunk(son_fond, MIX_MAX_VOLUME/2);
    Mix_PlayChannel(0, son_fond, -1);
    while (ok)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT : 
                 ok=0 ;
                 break;
            case SDL_KEYDOWN:
            {
              switch(event.key.keysym.sym)
                {
                    case SDLK_DOWN:
                      buttonpos+=1;
                      if(buttonpos>5)
                        buttonpos=1;
                        if(buttonpos==1)
                        {
                          bouton111 = bouton11;
                          Mix_PlayChannel(1, son_bouton, 0);
                        }
                        else
                          bouton111 = bouton1;
                        if(buttonpos==2)
                          {
                           bouton222 = bouton22;
                            Mix_PlayChannel(1, son_bouton, 0);
                          }
                        else
                          bouton222 = bouton2;
                        if(buttonpos==3)
                          {
                          bouton333 = bouton33;
                          Mix_PlayChannel(1, son_bouton, 0);
                          }
                        else
                          bouton333 = bouton3;
                        if(buttonpos==4)
                         {
                          bouton444 = bouton44;
                          Mix_PlayChannel(1, son_bouton, 0);
                         }
                        else
                          bouton444 = bouton4;
                        if(buttonpos==5)
                          {
                          bouton555 = bouton55;
                          Mix_PlayChannel(1, son_bouton, 0);
                          }
                        else
                          bouton555 = bouton5;
                        break;
                    case SDLK_UP:
                      buttonpos-=1;
                      if(buttonpos<1)
                          buttonpos=5;
                         if(buttonpos==1)
                        {
                          bouton111 = bouton11;
                          Mix_PlayChannel(1, son_bouton, 0);
                        }
                        else
                          bouton111 = bouton1;
                        if(buttonpos==2)
                          {
                           bouton222  = bouton22;
                            Mix_PlayChannel(1, son_bouton, 0);
                          }
                        else
                         bouton222  = bouton2;
                        if(buttonpos==3)
                          {
                          bouton333 = bouton33;
                          Mix_PlayChannel(1, son_bouton, 0);
                          }
                        else
                          bouton333 = bouton3;
                        if(buttonpos==4)
                         {
                          bouton444 = bouton44;
                          Mix_PlayChannel(1, son_bouton, 0);
                         }
                        else
                          bouton444 = bouton4;
                        if(buttonpos==5)
                          {
                          bouton555 = bouton55;
                          Mix_PlayChannel(1, son_bouton, 0);
                          }
                        else
                          bouton555 = bouton5;
                        if(buttonpos>5)
                          buttonpos=5;
                        break;
                    case SDLK_RETURN :
                      if(buttonpos==1)
                         { //texte = TTF_RenderText_Blended(police, "Vous avez clique sur le bouton 1", noir);
                           Mix_PlayChannel(1, son_bouton, 0);
                           ok=0;
                           *action=1;
                         }
                      if(buttonpos==2)
                          { //texte = TTF_RenderText_Blended(police, "Vous avez clique sur le bouton 2", noir);
                           Mix_PlayChannel(1, son_bouton, 0);
                           *action=2;
                           ok=0;
                         }
                      if(buttonpos==3)
                          { //texte = TTF_RenderText_Blended(police, "Vous avez clique sur le bouton 3", noir);
                           Mix_PlayChannel(1, son_bouton, 0);
                           *action=3;
                           ok=0;
                         }
                      if(buttonpos==4)
                          { //texte = TTF_RenderText_Blended(police, "Vous avez clique sur le bouton 4", noir);
                           Mix_PlayChannel(1, son_bouton, 0);
                          *action=4;
                         }
                      if(buttonpos==5)
                          { //texte = TTF_RenderText_Blended(police, "Vous avez clique sur le bouton 5", noir);
                           Mix_PlayChannel(1, son_bouton, 0);
                           *action=5;
                           ok=0;
                         }
                    
                }
                break;
             }
            case SDL_MOUSEMOTION :
                 if (positionBouton1.x <= event.motion.x && event.motion.x <= positionBouton1.x + bouton1->w && positionBouton1.y <= event.motion.y && event.motion.y <= positionBouton1.y + bouton1->h) 
                      {
                          bouton111 = bouton11;
                          if (nb_press_b1 ==0)
                          {
                            Mix_PlayChannel(1, son_bouton, 0);
                            nb_press_b1++;
                          }
                        }
                        else
                          {
                            bouton111 = bouton1;
                            nb_press_b1=0;
                          }
                 
                  if (positionBouton2.x <= event.motion.x && event.motion.x <= positionBouton2.x + bouton2->w && positionBouton2.y <= event.motion.y && event.motion.y <= positionBouton2.y + bouton2->h) 
                      {
                           bouton222  = bouton22;
                         if (nb_press_b2 ==0)
                          {
                            Mix_PlayChannel(1, son_bouton, 0);
                            nb_press_b2++;
                          }
                          }
                        else
                        {
                         bouton222 = bouton2;
                          nb_press_b2=0;
                        }
                  if (positionBouton3.x <= event.motion.x && event.motion.x <= positionBouton3.x + bouton3->w && positionBouton3.y <= event.motion.y && event.motion.y <= positionBouton3.y + bouton3->h) 
                      {
                          bouton333 = bouton33;
                          if (nb_press_b3 ==0)
                          {
                            Mix_PlayChannel(1, son_bouton, 0);
                            nb_press_b3++;
                          }
                          }
                        else
                         {
                          bouton333 = bouton3;
                          nb_press_b3=0;
                         }
                  if (positionBouton4.x <= event.motion.x && event.motion.x <= positionBouton4.x + bouton4->w && positionBouton4.y <= event.motion.y && event.motion.y <= positionBouton4.y + bouton4->h) 
                      {
                          bouton444 = bouton44;
                          if (nb_press_b4 ==0)
                          {
                            Mix_PlayChannel(1, son_bouton, 0);
                            nb_press_b4++;
                          }
                         }
                        else
                        {
                          bouton444 = bouton4;
                          nb_press_b4=0;
                        }
                  if (positionBouton5.x <= event.motion.x && event.motion.x <= positionBouton5.x + bouton5->w && positionBouton5.y <= event.motion.y && event.motion.y <= positionBouton5.y + bouton5->h) 
                      {
                          bouton555 = bouton55;
                          if (nb_press_b5 ==0)
                          {
                            Mix_PlayChannel(1, son_bouton, 0);
                            nb_press_b5++;
                          }
                          }
                        else
                         {
                          bouton555 = bouton5;
                          nb_press_b5=0;
                        }
                break;
            case SDL_MOUSEBUTTONUP :
                      if (event.button.button == SDL_BUTTON_LEFT)
                      {
                       
                        if (positionBouton1.x <= event.button.x && event.button.x <= positionBouton1.x + bouton1->w && positionBouton1.y <= event.button.y && event.button.y <= positionBouton1.y + bouton1->h) 
                          { //texte = TTF_RenderText_Blended(police, "Vous avez clique sur le bouton 1", noir);
                           Mix_PlayChannel(1, son_bouton, 0);
                           *action=1;
                           ok=0;
                         }
                 
                         else if (positionBouton2.x <= event.button.x && event.button.x <= positionBouton2.x + bouton2->w && positionBouton2.y <= event.button.y && event.button.y <= positionBouton2.y + bouton2->h) 
                          { //texte = TTF_RenderText_Blended(police, "Vous avez clique sur le bouton 2", noir);
                           Mix_PlayChannel(1, son_bouton, 0);
                           *action=2;
                           ok=0;
                         }
                 
                        else if (positionBouton3.x <= event.button.x && event.button.x <= positionBouton3.x + bouton3->w && positionBouton3.y <= event.button.y && event.button.y <= positionBouton3.y + bouton3->h) 
                          { //texte = TTF_RenderText_Blended(police, "Vous avez clique sur le bouton 3", noir);
                           Mix_PlayChannel(1, son_bouton, 0);
                           *action=3;
                         }
                   
                        else if (positionBouton4.x <= event.button.x && event.button.x <= positionBouton4.x + bouton4->w && positionBouton4.y <= event.button.y && event.button.y <= positionBouton4.y + bouton4->h) 
                         { //texte = TTF_RenderText_Blended(police, "Vous avez clique sur le bouton 4", noir);
                           Mix_PlayChannel(1, son_bouton, 0);
                         }
                
                        else if (positionBouton5.x <= event.button.x && event.button.x <= positionBouton5.x + bouton5->w && positionBouton5.y <= event.button.y && event.button.y <= positionBouton5.y + bouton5->h) 
                         { //texte = TTF_RenderText_Blended(police, "Vous avez clique sur le bouton 5", noir);
                           Mix_PlayChannel(1, son_bouton, 0);
                           *action=5;
                           ok=0;
                         }
                        //else 
                          //texte = TTF_RenderText_Blended(police, "", noir);
                      }
                 break;
        }
    
    
     SDL_BlitSurface(imageDeFond, NULL, fenetre, &positionFond);
     SDL_BlitSurface(bouton111, NULL, fenetre, &positionBouton1);
     SDL_BlitSurface(bouton222, NULL, fenetre, &positionBouton2);
     SDL_BlitSurface(bouton333, NULL, fenetre, &positionBouton3);
     SDL_BlitSurface(bouton444, NULL, fenetre, &positionBouton4);
     SDL_BlitSurface(bouton555, NULL, fenetre, &positionBouton5);
     SDL_BlitSurface(texte, NULL, fenetre, &positionTexte);
     SDL_Flip(fenetre);
    }
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(bouton111);
    SDL_FreeSurface(bouton222);
    SDL_FreeSurface(bouton333);
    SDL_FreeSurface(bouton444);
    SDL_FreeSurface(bouton555);
    //TTF_CloseFont(police);
    //TTF_Quit();
    Mix_FreeChunk(son_bouton);
    Mix_FreeChunk(son_fond);
    Mix_CloseAudio();
    SDL_Quit();
 
    return 0;
}





void Smain (int *cond)
{ 

 int ok = 1,buttonpos=0,nb_press_b1=0, nb_press_b2=0, nb_press_b3=0;


 
 SDL_Surface *fenetre = NULL, *imageDeFond = NULL, *bouton1 = NULL, *bouton2 = NULL, *bouton3 = NULL;
 SDL_Rect positionFond, positionBouton1, positionBouton2, positionBouton3, positionTexte;
 positionFond.x = 0;
    positionFond.y = 0;
    positionBouton1.x = 530;
    positionBouton1.y = 400;
    positionBouton2.x = 530;
    positionBouton2.y = 500;
    positionBouton3.x = 530;
    positionBouton3.y = 600;
    positionTexte.x= 500;
    positionTexte.y= 300;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_EnableKeyRepeat (300,300);
    fenetre = SDL_SetVideoMode(1300,700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    imageDeFond = IMG_Load("Menu/Menu/fond.bmp");
    bouton1 = IMG_Load("Menu/Menu/bouton1.png");
    bouton2 = IMG_Load("Menu/Menu/bouton2.png");
    bouton3 = IMG_Load("Menu/Menu/bouton5.png");

 while (ok)
    { SDL_WaitEvent(&event);
        switch (event.type)
        {
          case SDL_QUIT : 
              {    ok=0;
               break;
               }
        case SDL_KEYDOWN:
            {
              switch(event.key.keysym.sym)
                {
                    case SDLK_DOWN:
                      buttonpos+=1;
                      if(buttonpos>3)
                        buttonpos=1;
                        if(buttonpos==1)
                        {
                          bouton1 = IMG_Load("Menu/Menu/bouton11.png");
                        }
                        else
                          bouton1 = IMG_Load("Menu/Menu/bouton1.png");
                        if(buttonpos==2)
                          {
                            bouton2 = IMG_Load("Menu/Menu/bouton22.png");
                          }
                        else
                          bouton2 = IMG_Load("Menu/Menu/bouton2.png");
                        if(buttonpos==3)
                          {
                          bouton3 = IMG_Load("Menu/Menu/bouton55.png");
                          
                          }
                        else
                          bouton3 = IMG_Load("Menu/Menu/bouton5.png");
                        
                        break;
                    case SDLK_UP:
                      buttonpos-=1;
                      if(buttonpos<1)
                          buttonpos=3;
                         if(buttonpos==1)
                          bouton1 = IMG_Load("Menu/Menu/bouton11.png"); 
                        else
                          bouton1 = IMG_Load("Menu/Menu/bouton1.png");
                        if(buttonpos==2)
                          bouton2 = IMG_Load("Menu/Menu/bouton22.png");                            
                        else
                          bouton2 = IMG_Load("Menu/Menu/bouton2.png");
                        if(buttonpos==3)
                          bouton3 = IMG_Load("Menu/Menu/bouton55.png");
                        else
                          bouton3 = IMG_Load("Menu/Menu/bouton5.png");
                        break;
                    case SDLK_RETURN :
                    {
                      if(buttonpos==1)
                         { 
                          *cond=1;
                         ok=0;
                         }
                      if(buttonpos==2)
                          { 
                           *cond=2;
                           ok=0;
                         }
                      if(buttonpos==3)
                          { 
                         *cond=3;
                         ok=0;
                         }
                     }
                     break;
                }
             }
      case SDL_MOUSEMOTION :
                 {
                 if (positionBouton1.x <= event.motion.x && event.motion.x <= positionBouton1.x + bouton1->w && positionBouton1.y <= event.motion.y && event.motion.y <= positionBouton1.y + bouton1->h) 
                      {
                          bouton1 = IMG_Load("Menu/Menu/bouton11.png");
                          if (nb_press_b1 ==0)
                          {
                          
                            nb_press_b1++;
                          }
                        }
                        else
                          {
                            bouton1 = IMG_Load("Menu/Menu/bouton1.png");
                            nb_press_b1=0;
                          }
                 
                  if (positionBouton2.x <= event.motion.x && event.motion.x <= positionBouton2.x + bouton2->w && positionBouton2.y <= event.motion.y && event.motion.y <= positionBouton2.y + bouton2->h) 
                      {
                            bouton2 = IMG_Load("Menu/Menu/bouton22.png");
                         if (nb_press_b2 ==0)
                          {
                            
                            nb_press_b2++;
                          }
                          }
                        else
                        {
                          bouton2 = IMG_Load("Menu/Menu/bouton2.png");
                          nb_press_b2=0;
                        }
                  if (positionBouton3.x <= event.motion.x && event.motion.x <= positionBouton3.x + bouton3->w && positionBouton3.y <= event.motion.y && event.motion.y <= positionBouton3.y + bouton3->h) 
                      {  
                          bouton3 = IMG_Load("Menu/Menu/bouton55.png");
                          if (nb_press_b3 ==0)
                          {
                            
                            nb_press_b3++;
                          }
                          }
                        else
                         {
                          bouton3 = IMG_Load("Menu/Menu/bouton5.png");
                          nb_press_b3=0;
                         }
                  }       
                break;
        case SDL_MOUSEBUTTONUP :
            {
                      if (event.button.button == SDL_BUTTON_LEFT)
                      {
                       
                        if (positionBouton1.x <= event.button.x && event.button.x <= positionBouton1.x + bouton1->w && positionBouton1.y <= event.button.y && event.button.y <= positionBouton1.y + bouton1->h) 
                          { 
                       *cond=1;   
                       ok=0;
                           }
                 
                         else if (positionBouton2.x <= event.button.x && event.button.x <= positionBouton2.x + bouton2->w && positionBouton2.y <= event.button.y && event.button.y <= positionBouton2.y + bouton2->h) 
                          { 
                         
                               *cond=2;
                                ok=0;
                          }
                 
                        else if (positionBouton3.x <= event.button.x && event.button.x <= positionBouton3.x + bouton3->w && positionBouton3.y <= event.button.y && event.button.y <= positionBouton3.y + bouton3->h) 
                          { 
                          *cond=3;
                          ok=0;
                          }  
                      }
              }
                 break;
    }//mta3 l'event
     SDL_BlitSurface(imageDeFond, NULL, fenetre, &positionFond);
     SDL_BlitSurface(bouton1, NULL, fenetre, &positionBouton1);
     SDL_BlitSurface(bouton2, NULL, fenetre, &positionBouton2);
     SDL_BlitSurface(bouton3, NULL, fenetre, &positionBouton3);
     SDL_Flip(fenetre);

    }//mta3 el while lekbira
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(bouton1);
    SDL_FreeSurface(bouton2);
    SDL_FreeSurface(bouton3);
    SDL_FillRect(fenetre,NULL,0);
    
}//mteehom kol



void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, NULL, destination, &offset );
}

 int init()
 {
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 0;
    }
    fenetre = SDL_SetVideoMode( fenetre_WIDTH, fenetre_HEIGHT, fenetre_BPP, SDL_SWSURFACE );
    return 1;
 }
 SDL_Surface *load_image(char *nom)
 {
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load(nom);
    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );
        if( optimizedImage != NULL )
        {
            SDL_SetColorKey( optimizedImage, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }
    return optimizedImage;
 }
 int load_files()
  {
    background = load_image( "map/map1.jpg" );
    imageDeFondCollision = load_image("map/mapCollisionBackGround.jpg");
    if( background == NULL )
    {
        return 0;
    }
    return 1;
 }

 void clean_up()
 {
    SDL_FreeSurface( background );
    SDL_Quit();
 }
 SDL_Rect limit(int x, int y)
 {
  SDL_Rect offset;
  if(x<-7000)
    x+=2;
  if(x>0)
    x-=2;
  if(y>0)
    y-=2;
  if(y<-5000)
    y+=2;
  offset.x = x;
  offset.y = y;
  return offset;
 }
 SDL_Surface *anim_right(int *mouvement)
 {
  SDL_Surface *perso_right[]={NULL,NULL,NULL,NULL};
  perso_right[0]= IMG_Load("perso/right1.png");
  perso_right[1]= IMG_Load("perso/right2.png");
  perso_right[2]= IMG_Load("perso/right1.png");
  perso_right[3]= IMG_Load("perso/right3.png");
  if(*mouvement>3)
    {*mouvement=0;}
  return perso_right[*mouvement];
 }

 SDL_Surface *anim_left(int *mouvement)
 {
  SDL_Surface *perso_right[]={NULL,NULL,NULL,NULL};
  perso_right[0]= IMG_Load("perso/left1.png");
  perso_right[1]= IMG_Load("perso/left2.png");
  perso_right[2]= IMG_Load("perso/left1.png");
  perso_right[3]= IMG_Load("perso/left3.png");
  if(*mouvement>3)
    {*mouvement=0;}
  return perso_right[*mouvement];
 }
 SDL_Surface *anim_up(int *mouvement)
 {
  SDL_Surface *perso_right[]={NULL,NULL,NULL,NULL};
  perso_right[0]= IMG_Load("perso/up1.png");
  perso_right[1]= IMG_Load("perso/up2.png");
  perso_right[2]= IMG_Load("perso/up1.png");
  perso_right[3]= IMG_Load("perso/up3.png");
  if(*mouvement>3)
    {*mouvement=0;}
  return perso_right[*mouvement];
}
SDL_Surface *anim_down(int *mouvement)
{
  SDL_Surface *perso_right[]={NULL,NULL,NULL,NULL};
  perso_right[0]= IMG_Load("perso/down1.png");
  perso_right[1]= IMG_Load("perso/down2.png");
  perso_right[2]= IMG_Load("perso/down1.png");
  perso_right[3]= IMG_Load("perso/down3.png");
  if(*mouvement>3)
    *mouvement=0;
  return perso_right[*mouvement];
}
//
SDL_Color GetPixel (SDL_Surface* pSurface, int x, int y)
{

  SDL_Color color;
  Uint32 col = 0;
  char *pPosition = (char*) pSurface -> pixels;
  pPosition += (pSurface -> pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy (&col, pPosition, pSurface->format->BytesPerPixel);
  SDL_GetRGB (col, pSurface->format, &color.r, &color.g, &color.b);
  return (color);
}

int detecter_collision_background (SDL_Surface *image, SDL_Rect position)
{
  SDL_Color color;
  color = GetPixel (image, position.x, position.y+27/2);
  if (color.r==255 && color.g==255 && color.b==255) return 1;
  return 0;
}
int detecter_Pin (SDL_Surface *image, SDL_Rect position)
{
  SDL_Color color;
  color = GetPixel (image, position.x, position.y+27/2);
  if (color.r==0 && color.g==0 && color.b==0) return 1;
  return 0;
}
int detecter_collision_restaurant (SDL_Surface *image, SDL_Rect position)
{
  SDL_Color color;
  color = GetPixel (image, position.x, position.y+27/2);
  if (color.r==0 && color.g==0 && color.b==0) return 1;
  return 0;
}

void sauvegarde (int *save,SDL_Rect *bg)
{
FILE *f=fopen("chemin","w");
  fprintf (f," %d %d",bg->x,bg->y);
fclose(f);
}
// int detecter_collision_trigonometric(SDL_Surface *imageA, SDL_Surface *imageB, SDL_Rect objetA, SDL_Rect objetB)
// {
//     int adj,hyp,opp;
//     adj=abs(objetA.y-objet.B.y);
//     opp=abs(objetA.x-objet.B-x);
//     hyp=sqrt(pow(opp,2))+pow(sqr(adj,2));
//     if(hyp==0)
//       return 1;
//     else
//       return 0;
//   }

void Score(int vie,int t_ennemis[],SDL_Rect *pospers)
{
  //if(collisionAB(t_ennemis,*pospers))
  {
    vie-=1;
  }
}
void Reunion()
{
  SDL_Surface *texte[]={NULL,NULL,NULL,NULL,NULL,NULL},*A=NULL,*B=NULL,*C=NULL,*A1=NULL,*B1=NULL,*C1=NULL,*S=NULL, *fenetre=NULL;
  TTF_Font *police = NULL;
  SDL_Color noir = {0, 0, 0};
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  fenetre = SDL_SetVideoMode(1300, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  police = TTF_OpenFont("western.ttf", 32);
  SDL_Event event1;
  SDL_Surface *restaurant,*question;
  int compteur=1,R=0,Question=0;
  SDL_Rect posquestion,posrestaurant,posq1uestion,posq1,posq2,posq3;
  SDL_Rect posperso;
  posquestion.x=450;
  posquestion.y=200;
  posrestaurant.x=200;
  posrestaurant.y=-100;
  posq1uestion.x=400;
  posq1uestion.y=0;
  posq1.x=450;
  posq1.y=250;
  posq2.x=450;
  posq2.y=350;
  posq3.x=450;
  posq3.y=450;
  restaurant=IMG_Load("map/kojina.png");
  question= IMG_Load("entities/liste.png");
  A=IMG_Load("entities/pins/pin1.png");
  S=IMG_Load("entities/star1.png");
  texte[0] = TTF_RenderText_Blended(police, "question ?", noir);
  texte[1] = TTF_RenderText_Blended(police, "question1 ?", noir);
  texte[2] = TTF_RenderText_Blended(police, "question2 ?", noir);
  texte[3] = TTF_RenderText_Blended(police, "question3 ?", noir);
  texte[4] = TTF_RenderText_Blended(police, "question4 ?", noir);
  B=A;
  C=A;
  while(compteur != 0) 
  {
    SDL_WaitEvent(&event1);
    if(event1.key.keysym.sym == SDLK_ESCAPE) 
      compteur =0;
    switch (event1.type) 
    {
       case SDL_MOUSEBUTTONUP :
         if (event1.button.button == SDL_BUTTON_LEFT)
         {
           if (posq1.x <= event1.button.x && event1.button.x <= posq1.x + A->w && posq1.y <= event1.button.y && event1.button.y <= posq1.y + A->h)
           {
            A=S;
            R=1;
           }
           if (posq2.x <= event1.button.x && event1.button.x <= posq2.x + B->w && posq2.y <= event1.button.y && event1.button.y <= posq2.y + B->h)
           {
            B=S;
            R=2;
           }
           if (posq3.x <= event1.button.x && event1.button.x <= posq3.x + C->w && posq3.y <= event1.button.y && event1.button.y <= posq3.y + C->h)
           {
            C=S;
            R=3;
           }
         }
    }
  SDL_BlitSurface(restaurant,NULL, fenetre, &posrestaurant);
  SDL_BlitSurface(question,NULL, fenetre, &posq1uestion);
  SDL_BlitSurface(A, NULL, fenetre, &posq1);
  SDL_BlitSurface(B, NULL, fenetre, &posq2);
  SDL_BlitSurface(C, NULL, fenetre, &posq3);
  SDL_BlitSurface(texte[0], NULL,fenetre, &posquestion);
  SDL_Flip(fenetre);
  if(R==1 && Question==1)
  {

  }
  else if(R==2 && Question==1)
  {
    
  }
  if(R==3 && Question==1)
  {

  }
  else if(R==1 && Question==2)
  {
    
  }
  if(R==2 && Question==2)
  {

  }
  else if(R==3 && Question==2)
  {
    
  }
  if(R==1 && Question==3)
  {

  }
  else if(R==2 && Question==3)
  {
    
  }
  else if(R==3 && Question==3)
  {
    
  }  
  }
  TTF_CloseFont(police);
  TTF_Quit();
  SDL_Quit();
}
void afficherscore(int score)
{
  char ch[10];
  SDL_Rect poscore;
  SDL_Surface *scoring;
  poscore.x=600;
  poscore.y=600;
  TTF_Font *police = NULL;
  SDL_Color noir = {0, 0, 0};
  police = TTF_OpenFont("western.ttf", 32);
  sprintf(ch,"%d",score);
  scoring=TTF_RenderText_Blended(police, ch, noir);
  SDL_BlitSurface(scoring, NULL, fenetre,&poscore);
}

void pershud(int score)
{
  SDL_Rect posstar;
  posstar.x=638;
  posstar.y=322;
  SDL_Surface *star[]={NULL,NULL,NULL};
  star[0]=IMG_Load("entities/star1.png");
  star[1]=IMG_Load("entities/star2.png");
  star[2]=IMG_Load("entities/star3.png");
  if(score>=0 && score<=100)
    SDL_BlitSurface(star[0], NULL, fenetre,&posstar);
  if(score>100 && score<=200)
    SDL_BlitSurface(star[1], NULL, fenetre,&posstar);
  if(score>200 && score<=300)
    SDL_BlitSurface(star[2], NULL, fenetre,&posstar);
}



void afficherpin(SDL_Surface* destination)
{
  SDL_Surface *pin;
  SDL_Rect pospin;
  pin=IMG_Load("entities/pins/pin1.png"); 
  pospin.x= -3091;
  pospin.y= -3597;
  SDL_BlitSurface(pin, NULL, destination, &pospin);
}


void afficher_ennemi ( SDL_Surface *car1, SDL_Surface *car2, SDL_Surface *fenetre, SDL_Rect t_ennemis[] )
{
     SDL_BlitSurface(car1, NULL, fenetre, &t_ennemis[0]);
     SDL_BlitSurface(car1, NULL, fenetre, &t_ennemis[1]);
     SDL_BlitSurface(car1, NULL, fenetre, &t_ennemis[2]);
     SDL_BlitSurface(car1, NULL, fenetre, &t_ennemis[3]);
     SDL_BlitSurface(car1, NULL, fenetre, &t_ennemis[4]);
     SDL_BlitSurface(car2, NULL, fenetre, &t_ennemis[5]);
     SDL_BlitSurface(car2, NULL, fenetre, &t_ennemis[6]);
}
int arduinoReadData(char *c)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;
    f=fopen(chemin,"r");
    if(f == NULL)
        return(-1);
    else
        fscanf(f,"%c",c);
    
    fclose(f);
    return(0);
}
int arduinoWriteData(int k)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d\n",k);
    fclose(f);

    return(0);
}
void mvt_arduino (SDL_Rect *bg, SDL_Surface *imageDeFondCollision, SDL_Rect *positionpers, int *mouvement, SDL_Rect *pospers, SDL_Surface **image)
{
  char a;
  arduinoReadData(&a);
    ("%c",a);
  if(strcmp(&a,"r")==0)
                  { 
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                        printf("1");
                      }
                    *image=anim_right(mouvement);
                    (*mouvement)++;
                    bg->x -= 3;
                    bg->y +=(-1/9)*bg->x+2;
                    SDL_Delay(40);
                    
                  }
                    else
                    {
                      bg->x+=15;
                      bg->y-=15;
                    }
                    if(bg->x <-7000)
                      bg->x+=2;
                    
                  }
                  if(strcmp(&a,"l")==0)
                  { 
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                        //entrer_reunion(*fenetre);
                        printf("1");
                      }
                    *image=anim_left(mouvement);
                    (*mouvement)++;
                    bg->x += 3;
                    bg->y -=(-1/9)*bg->x+2;
                    SDL_Delay(40);
                    }
                    else
                    {
                      bg->x-=15;
                      bg->y+=15;
                    }
                    if(bg->x>0)
                      bg->x-=2;
                  }
                  if(strcmp(&a,"u")==0)
                  { 
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                        //entrer_reunion(*fenetre);
                        printf("1");
                      }
                    *image=anim_up(mouvement);
                    (*mouvement)++;
                    bg->x += 3;
                    bg->y +=(-1/9)*bg->x+2;
                    SDL_Delay(40);
                  }
                    else
                    {
                      bg->x-=15;
                      bg->y-=15;
                    }
                    if(bg->y>0)
                      bg->y-=2;
                  
                  }
                  if(strcmp(&a,"d")==0)
                  { 
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                        //entrer_reunion(*fenetre);
                        printf("1");
                      }
                    *image=anim_down(mouvement);
                    (*mouvement)++;
                    bg->x -= 3;
                    bg->y -=(-1/9)*bg->x+2;
                       SDL_Delay(40);
                  }
                    else
                    {
                      bg->x+=15;
                      bg->y+=15;
                    }
                    if(bg->y<-5000)
                      bg->y+=2;
                  }

}


void mvt_clavier (int *reun,SDL_Surface *fenetre, SDLKey bouton, SDL_Rect *bg, SDL_Surface *imageDeFondCollision, SDL_Rect *positionpers, int *mouvement, SDL_Rect *pospers, SDL_Surface **image,int *ok,int *save)
{
  SDL_Event e;
  int compteur=1;
  int cond;
   switch(bouton)
                {
                  case SDLK_RIGHT:
                  { 
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                          SDL_WaitEvent(&e);
                          if(e.key.keysym.sym == SDLK_RETURN)
                          {
                            *reun=1;
                            Reunion();
                          }
                          else if(*reun=0)
                            compteur=0;
                      }
                    *image=anim_right(mouvement);
                    (*mouvement)++;
                    bg->x -= 3;
                    bg->y +=(-1/9)*bg->x+2;
                    SDL_Delay(40);
                  }
                    else
                    {
                      bg->x+=15;
                      bg->y-=15;
                    }
                    if(bg->x <-7000)
                      bg->x+=2;
                    
                  }
                  break;
                  case SDLK_LEFT:
                  { 
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                          SDL_WaitEvent(&e);
                          if(e.key.keysym.sym == SDLK_ESCAPE)
                          {
                            *reun=1;
                            Reunion();
                          }
                          else if(*reun==0)
                            compteur=0;
                      }

                    *image=anim_left(mouvement);
                    (*mouvement)++;
                    bg->x += 3;
                    bg->y -=(-1/9)*bg->x+2;
                    SDL_Delay(40);
                    }
                    else
                    {
                      bg->x-=15;
                      bg->y+=15;
                    }
                    if(bg->x>0)
                      bg->x-=2;
                    break;
                  }
                  case SDLK_UP:
                  { 
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                          SDL_WaitEvent(&e);
                          if(e.key.keysym.sym == SDLK_RETURN)
                          {
                            *reun=1;
                            Reunion();
                          }
                          else if(*reun=0)
                            compteur=0;
                      }

                    *image=anim_up(mouvement);
                    (*mouvement)++;
                    bg->x += 3;
                    bg->y +=(-1/9)*bg->x+2;
                    SDL_Delay(40);
                  }
                    else
                    {
                      bg->x-=15;
                      bg->y-=15;
                    }
                    if(bg->y>0)
                      bg->y-=2;
                  
                  }
                  break;
                  case SDLK_DOWN:
                  { 
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                          SDL_WaitEvent(&e);
                          if(e.key.keysym.sym == SDLK_RETURN)
                          {
                            *reun=1;
                            Reunion();
                          }
                          else if(*reun=0)
                            compteur=0;
                      }
                    *image=anim_down(mouvement);
                    (*mouvement)++;
                    bg->x -= 3;
                    bg->y -=(-1/9)*bg->x+2;
                       SDL_Delay(40);
                  }
                    else
                    {
                      bg->x+=15;
                      bg->y+=15;
                    }
                    if(bg->y<-5000)
                      bg->y+=2;
                  }
                  break;
                  case SDLK_ESCAPE:
                  {

                    Smain(&cond);
                      
                    if (cond==1)
                    {
                      break;
                    }
                  if (cond==2)
                    {
                    *save=1;
                    *ok=1;
                    }
                  if (cond==3)
                    {
                      *ok=1;
                      SDL_QUIT;
                    }
                  }
                break;
                }
     }


int main( int argc, char* args[] )
{
    int quit = 0,mouvement=0,m;
    SDL_Rect positionpers,positiontexte,pospers,bg;
    int save=0;
    positionpers.x=638;
    positionpers.y=338;
    positiontexte.x=0;
    positiontexte.y=0;
    int score=0;
    int bgX , bgY ;
    int menup;
    int action;
    menup=Pmenu(&action) ;
    if (action==1)
    {
      FILE *f=fopen("chemin","w");
      bgX = -2600;
      bgY = -3400;
    }
    else if (action==2)
    {
      FILE *f=fopen("chemin","r");
     if (fgetc(f)!=EOF)
      fscanf (f," %d %d",&bgX,&bgY);   
    }
    if(action==3)
      option(fenetre);
    else if (action==5)
      quit=1;
    
    bg.x=bgX;
    bg.x=bgX;
    bg.y=bgY;


    SDL_Event event;
    SDL_Surface *image=NULL,*texte=NULL;
    TTF_Font *police = NULL;
    SDL_Color noir = {0, 0, 0};
    TTF_Init();
    police = TTF_OpenFont("western.ttf", 32);
    texte = TTF_RenderText_Blended(police, "", noir);
    char ch[10];
    int reun=0;
    if( init() == 0 )
    {
        return 1;
    }
    if( load_files() == 0 )
    {
        return 1;
    }
    SDL_EnableKeyRepeat(50,50);
    while( quit == 0 )
    {
     SDL_PollEvent(&event);
        switch (event.type)
        {         
            case SDL_QUIT : 
               quit=1; break;
             case SDL_KEYDOWN :
             {
              mvt_clavier (&reun,fenetre,event.key.keysym.sym, &bg,imageDeFondCollision,&positionpers,&mouvement,&pospers, &image,&quit,&save);
              mvt_arduino (&bg,imageDeFondCollision,&positionpers,&mouvement,&pospers, &image);
        }
      }
      if(reun==0)
      {
        apply_surface( bg.x, bg.y, background, fenetre );
        apply_surface( positionpers.x, positionpers.y, image, fenetre );
        SDL_BlitSurface(texte, NULL, fenetre, &positiontexte);
        pershud(score);
        //afficherpin(fenetre);
       // afficherscore(score);
        if( SDL_Flip( fenetre ) == -1 )
            return 1;
        SDL_FillRect(fenetre,NULL,0);
      }
    }
      if (save==1)
{

sauvegarde (&save,&bg);

}

    clean_up();
}
