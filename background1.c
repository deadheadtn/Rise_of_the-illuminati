#include "background1.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, NULL, destination, &offset );
}

int init(SDL_Surface **fenetre )
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 0;
    }
    *fenetre = SDL_SetVideoMode( 1300, 700, 32, SDL_SWSURFACE );
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
int load_files(SDL_Surface **background, SDL_Surface **imageDeFondCollision)
{
    *background = load_image( "map/map1.jpg" );
    *imageDeFondCollision = load_image("map/mapCollisionBackGround.jpg");
    if( *background == NULL )
    {
        return 0;
    }
    return 1;
}

void clean_up(SDL_Surface **background, SDL_Surface **image )
{
    SDL_FreeSurface( *background );
    SDL_FreeSurface( *image );
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

// int detecter_collision_trigonometric(SDL_Surface *imageA, SDL_Surface *imageB, SDL_Rect objetA, SDL_Rect objetB)
// {
//     int adj,hyp,opp;
//     adj=abs(objetA.y-objet.B.y);
//     opp=abs(objetA.x-objet.B-x);
//     hyp=sqrt(sqr(opp,2))+sqrt(sqr(adj,2));
//     if(hyp==0)
//       return 1;
//     else
//       return 0;
//   }

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

      fenetre = SDL_SetVideoMode(1300, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
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


 SDL_Event event;
 SDL_Surface *fenetre1 = NULL, *imageDeFond = NULL, *bouton1 = NULL, *bouton2 = NULL, *bouton3 = NULL;
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
    fenetre1 = SDL_SetVideoMode(1300,700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    imageDeFond = IMG_Load("Menu/menu_pause/fond.png");
    bouton1 = IMG_Load("Menu/menu_pause/bouton1.png");
    bouton2 = IMG_Load("Menu/menu_pause/bouton2.png");
    bouton3 = IMG_Load("Menu/menu_pause/bouton5.png");

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
                          bouton1 = IMG_Load("Menu/menu_pause/bouton11.png");
                        }
                        else
                          bouton1 = IMG_Load("Menu/menu_pause/bouton1.png");
                        if(buttonpos==2)
                          {
                            bouton2 = IMG_Load("Menu/menu_pause/bouton22.png");
                          }
                        else
                          bouton2 = IMG_Load("Menu/menu_pause/bouton2.png");
                        if(buttonpos==3)
                          {
                          bouton3 = IMG_Load("Menu/menu_pause/bouton55.png");
                          
                          }
                        else
                          bouton3 = IMG_Load("Menu/menu_pause/bouton5.png");
                        
                        break;

                    case SDLK_UP:
                      buttonpos-=1;
                      if(buttonpos<1)
                          buttonpos=3;
                         if(buttonpos==1)
                         {
                          bouton1 = IMG_Load("Menu/menu_pause/bouton11.png");
                         } 
                        else
                          bouton1 = IMG_Load("Menu/menu_pause/bouton1.png");
                        if(buttonpos==2)
                          {
                            bouton2 = IMG_Load("Menu/menu_pause/bouton22.png"); 
                          }                           
                        else
                          bouton2 = IMG_Load("Menu/menu_pause/bouton2.png");
                        if(buttonpos==3)
                          {
                          bouton3 = IMG_Load("Menu/menu_pause/bouton55.png");
                        }
                        else
                          bouton3 = IMG_Load("Menu/menu_pause/bouton5.png");
                        break;

                    case SDLK_RETURN :
                    
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
                     break;}
               
      case SDL_MOUSEMOTION :
                 {
                 if (positionBouton1.x <= event.motion.x && event.motion.x <= positionBouton1.x + bouton1->w && positionBouton1.y <= event.motion.y && event.motion.y <= positionBouton1.y + bouton1->h) 
                      {
                          bouton1 = IMG_Load("Menu/menu_pause/bouton11.png");
                          if (nb_press_b1 ==0)
                          {
                          
                            nb_press_b1++;
                          }
                        }
                        else
                          {
                            bouton1 = IMG_Load("Menu/menu_pause/bouton1.png");
                            nb_press_b1=0;
                          }
                 
                  if (positionBouton2.x <= event.motion.x && event.motion.x <= positionBouton2.x + bouton2->w && positionBouton2.y <= event.motion.y && event.motion.y <= positionBouton2.y + bouton2->h) 
                      {
                            bouton2 = IMG_Load("Menu/menu_pause/bouton22.png");
                         if (nb_press_b2 ==0)
                          {
                            
                            nb_press_b2++;
                          }
                          }
                        else
                        {
                          bouton2 = IMG_Load("Menu/menu_pause/bouton2.png");
                          nb_press_b2=0;
                        }
                  if (positionBouton3.x <= event.motion.x && event.motion.x <= positionBouton3.x + bouton3->w && positionBouton3.y <= event.motion.y && event.motion.y <= positionBouton3.y + bouton3->h) 
                      {  
                          bouton3 = IMG_Load("Menu/menu_pause/bouton55.png");
                          if (nb_press_b3 ==0)
                          {
                            
                            nb_press_b3++;
                          }
                          }
                        else
                         {
                          bouton3 = IMG_Load("Menu/menu_pause/bouton5.png");
                          nb_press_b3=0;
                         }
                  }       
                break;
        case SDL_MOUSEBUTTONUP :
            
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
              
                 break;

    } 
    //mta3 l' event
     SDL_BlitSurface(imageDeFond, NULL, fenetre1, &positionFond);
     SDL_BlitSurface(bouton1, NULL, fenetre1, &positionBouton1);
     SDL_BlitSurface(bouton2, NULL, fenetre1, &positionBouton2);
     SDL_BlitSurface(bouton3, NULL, fenetre1, &positionBouton3);
     SDL_Flip(fenetre1);

    }//mta3 el while lekbira
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(bouton1);
    SDL_FreeSurface(bouton2);
    SDL_FreeSurface(bouton3);
    SDL_FillRect(fenetre1,NULL,0);
   // SDL_Quit() ;
    
}//mteehom kol

