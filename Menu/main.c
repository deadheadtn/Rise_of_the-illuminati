#include "fonctions.h"
 
int main()
{
    SDL_Surface *fenetre = NULL,*bouton555=NULL,*bouton444=NULL,*bouton333=NULL,*bouton222=NULL,*bouton111=NULL, *imageDeFond = NULL, *bouton1 = NULL, *bouton2 = NULL, *bouton3 = NULL, *bouton4 = NULL, *bouton5 = NULL, *bouton11 = NULL, *bouton22 = NULL, *bouton33 = NULL, *bouton44 = NULL, *bouton55 = NULL, *texte = NULL;
    SDL_Rect positionFond, positionBouton1, positionBouton2, positionBouton3, positionBouton4, positionBouton5, positionTexte;
    Mix_Chunk *son_bouton, *son_fond;
    int ok = 1, buttonpos=0, nb_press_b1=0, nb_press_b2=0, nb_press_b3=0, nb_press_b4=0, nb_press_b5=0;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color noir = {0, 0, 0};
    positionFond.x = 0;
    positionFond.y = 0;
    positionBouton1.x = 15;
    positionBouton1.y = 20;
    positionBouton2.x = 15;
    positionBouton2.y = 100;
    positionBouton3.x = 15;
    positionBouton3.y = 180;
    positionBouton4.x = 15;
    positionBouton4.y = 260;
    positionBouton5.x = 15;
    positionBouton5.y = 340;
    positionTexte.x= 500;
    positionTexte.y= 200;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_EnableKeyRepeat (300,300);
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    FPS_Initial();
    FPS_Fn();
    fenetre = SDL_SetVideoMode(1200, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    police = TTF_OpenFont("Font/western.ttf", 32);
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
    texte = TTF_RenderText_Blended(police, "", noir);
    Mix_AllocateChannels(2);
    Mix_Volume(0, MIX_MAX_VOLUME);
    son_bouton = Mix_LoadWAV("Son/button.wav");
    son_fond = Mix_LoadWAV("Son/fond.wav");
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
                         { texte = TTF_RenderText_Blended(police, "Vous avez clique sur le bouton 1", noir);
                            Mix_PlayChannel(1, son_bouton, 0);
                         }
                      if(buttonpos==2)
                          { texte = TTF_RenderText_Blended(police, "Vous avez clique sur le bouton 2", noir);
                           Mix_PlayChannel(1, son_bouton, 0);
                         }
                      if(buttonpos==3)
                          { option(fenetre);
                           Mix_PlayChannel(1, son_bouton, 0);
                         }
                      if(buttonpos==4)
                          { credit(fenetre);
                           Mix_PlayChannel(1, son_bouton, 0);

                         }
                      if(buttonpos==5)
                          { ok=0;
                           Mix_PlayChannel(1, son_bouton, 0);
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
                          { texte = TTF_RenderText_Blended(police, "Vous avez clique sur le bouton 1", noir);


                           Mix_PlayChannel(1, son_bouton, 0);
                         }
                 
                         else if (positionBouton2.x <= event.button.x && event.button.x <= positionBouton2.x +bouton222 ->w && positionBouton2.y <= event.button.y && event.button.y <= positionBouton2.y +bouton222 ->h) 
                          { texte = TTF_RenderText_Blended(police, "Vous avez clique sur le bouton 2", noir);
                           Mix_PlayChannel(1, son_bouton, 0);
                           
                         }
                 
                        else if (positionBouton3.x <= event.button.x && event.button.x <= positionBouton3.x + bouton333->w && positionBouton3.y <= event.button.y && event.button.y <= positionBouton3.y + bouton333->h) 
                          { option(fenetre);
                           Mix_PlayChannel(1, son_bouton, 0);
                         }
                   
                        else if (positionBouton4.x <= event.button.x && event.button.x <= positionBouton4.x + bouton444->w && positionBouton4.y <= event.button.y && event.button.y <= positionBouton4.y + bouton444->h) 
                         { credit(fenetre);
                           Mix_PlayChannel(1, son_bouton, 0);
                         }
                
                        else if (positionBouton5.x <= event.button.x && event.button.x <= positionBouton5.x + bouton555->w && positionBouton5.y <= event.button.y && event.button.y <= positionBouton5.y + bouton555->h) 
                         { ok=0;
                           Mix_PlayChannel(1, son_bouton, 0);
                         }
                        else 
                          texte = TTF_RenderText_Blended(police, "", noir);
                      }
                      buttonpos=0, nb_press_b1=0, nb_press_b2=0, nb_press_b3=0, nb_press_b4=0, nb_press_b5=0;
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
    TTF_CloseFont(police);
    TTF_Quit();
    Mix_FreeChunk(son_bouton);
    Mix_FreeChunk(son_fond);
    Mix_CloseAudio();
    SDL_Quit();
 
    return 0;
}

