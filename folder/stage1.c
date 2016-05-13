#include "stage1.h"

void afficherscore(int score, SDL_Surface *fenetre)
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

void pershud(int score, SDL_Surface *fenetre)
{
  SDL_Rect posstar;
  posstar.x=638;
  posstar.y=322;
  SDL_Surface *star[]={NULL,NULL,NULL};
  star[0]=IMG_Load("entities/star1.png");
  star[1]=IMG_Load("entities/star2.png");
  star[2]=IMG_Load("entities/star3.png");
  if(score>0 && score<=100)
    SDL_BlitSurface(star[0], NULL, fenetre,&posstar);
  if(score>100 && score<=200)
    SDL_BlitSurface(star[1], NULL, fenetre,&posstar);
  if(score>200 && score<=300)
    SDL_BlitSurface(star[2], NULL, fenetre,&posstar);
}

void mouvement_souris (int X, int Y, SDL_Rect *pospers, SDL_Surface *imageDeFondCollision)
{ 
int i ;
//if (!detecter_collision_background (imageDeFondCollision, *positionpers))
  // {
if (pospers->x < X)
     {for (i=pospers->x;i<=X;i++)
      {pospers->x=pospers->x+1;
      pospers->y=(-1/9)*pospers->x+2;
      }
     }
   if (pospers->x > X)
     {for (i=pospers->x;i>=X;i=i--)
      {pospers->x=pospers->x-1;
      pospers->y=(-1/9)*pospers->x+2;
      }
     }
 //}
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




void init_vitesse (int *v1, int *v2, int *v3, int *v4)
{
  *v4=1;
  *v3=1;
  *v2=1;
  *v1=1;
}

void vitesse (int ok, int *vit1, int *vit2, int *vit3, int *vit4)
{
  if (ok)
  *vit1= *vit1 +1;
  *vit2=1;
  *vit3=1;
  *vit4=1; 

}

void mvt_clavier (SDLKey bouton, SDL_Rect *bg, SDL_Surface *imageDeFondCollision, SDL_Rect *positionpers, int *mouvement, SDL_Rect *pospers, SDL_Surface **image, int *vit1, int *vit2, int *vit3, int *vit4, int *ok, SDL_Rect *positionennemi)
{
  int i;
   switch(bouton)
                {
                  case SDLK_RIGHT:
                  { 
                    init_vitesse (vit1,vit2,vit3,vit4);
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                        //entrer_reunion(*fenetre);
                        printf("1");
                      }
                    *image=anim_right(*mouvement);
                    (*mouvement)++;
                    bg->x -= 3;
                    bg->y +=(-1/9)*bg->x+2;
                    positionennemi->x = positionennemi->x - 3;
                    positionennemi->y +=(-1/9)*positionennemi->x+2;
                    SDL_Delay(40);
                    
                  }
                    else
                    {
                      while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x+=25;
                      bg->y-=25;
                      positionennemi->x+=25;
                      positionennemi->y-=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }  
                    }
                    if(bg->x <-7000)
                      bg->x+=2;
                    
                  }
                  break;
                  case SDLK_LEFT:
                  { 
                    init_vitesse (vit1,vit2,vit3,vit4);
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                        //entrer_reunion(*fenetre);
                        printf("1");
                      }
                    *image=anim_left(*mouvement);
                    (*mouvement)++;
                    bg->x += 3;
                    bg->y -=(-1/9)*bg->x+2;
                    positionennemi->x += 3;
                    positionennemi->y -=(-1/9)*positionennemi->x+2;
                    SDL_Delay(40);
                    }
                    else
                    {
                      while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x-=25;
                      bg->y+=25;
                      positionennemi->x-=25;
                      positionennemi->y+=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }
                    }
                    if(bg->x>0)
                      bg->x-=2;
                    break;
                  }
                  case SDLK_UP:
                  { 
                    init_vitesse (vit1,vit2,vit3,vit4);
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                        //entrer_reunion(*fenetre);
                        printf("1");
                      }
                    *image=anim_up(*mouvement);
                    (*mouvement)++;
                    bg->x += 3;
                    bg->y +=(-1/9)*bg->x+2;
                    positionennemi->x += 3;
                    positionennemi->y +=(-1/9)*positionennemi->x+2;
                    SDL_Delay(40);
                  }
                    else
                    {
                      while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x-=25;
                      bg->y-=25;
                      positionennemi->x-=25;
                      positionennemi->y-=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }
                    }
                    if(bg->y>0)
                      bg->y-=2;
                  
                  }
                  break;
                  case SDLK_DOWN:
                  { 
                    init_vitesse (vit1,vit2,vit3,vit4);
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                        //entrer_reunion(*fenetre);
                        printf("1");
                      }
                    *image=anim_down(*mouvement);
                    (*mouvement)++;
                    bg->x -= 3;
                    bg->y -=(-1/9)*bg->x+2;
                    positionennemi->x -= 3;
                    positionennemi->y -=(-1/9)*positionennemi->x+2;
                       SDL_Delay(40);
                  }
                    else
                    {
                      while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x+=25;
                      bg->y+=25;
                      positionennemi->x+=25;
                      positionennemi->y+=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }
                    }
                    if(bg->y<-5000)
                      bg->y+=2;
                  }
                  break;

                  case SDLK_KP6 :
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                        //entrer_reunion(*fenetre);
                        printf("1");
                      }
                    *image=anim_right(*mouvement);
                    (*mouvement)++;
                    *ok=-(*ok);
                    vitesse(*ok, vit1,vit2,vit3,vit4);
                    for (i=0; i<*vit1; i++)
                    {
                      bg->x -= 3;
                    bg->y +=(-1/9)*bg->x+2;
                    positionennemi->x -= 3;
                    positionennemi->y +=(-1/9)*positionennemi->x+2;
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (detecter_collision_background (imageDeFondCollision, *pospers))
                     break;
                     }
                    SDL_Delay(40);
                    break ;
                  }
                  else
                    {
                       while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x+=25;
                      bg->y-=25;
                      positionennemi->x+=25;
                      positionennemi->y-=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }
                    }
                    if(bg->x <-7000)
                      bg->x+=2;
                    
                  break;
                    
                    case SDLK_KP4 :
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                        //entrer_reunion(*fenetre);
                        printf("1");
                      }
                    *image=anim_left(*mouvement);
                    (*mouvement)++;
                    *ok=-(*ok);
                    vitesse(*ok, vit2,vit1,vit3,vit4);
                    for (i=0; i<*vit2; i++)
                    {
                      bg->x += 3;
                    bg->y -=(-1/9)*bg->x+2;
                    positionennemi->x += 3;
                    positionennemi->y -=(-1/9)*positionennemi->x+2;
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (detecter_collision_background (imageDeFondCollision, *pospers))
                     break;
                     }
                    SDL_Delay(40);
                    break ;
                  }
                    else
                    {
                       while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x-=25;
                      bg->y+=25;
                      positionennemi->x-=25;
                      positionennemi->y+=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }
                    }
                    if(bg->x>0)
                      bg->x-=2;
                    
                  break;

                  case SDLK_KP8 :
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                        //entrer_reunion(*fenetre);
                        printf("1");
                      }
                    *image=anim_up(*mouvement);
                    (*mouvement)++;
                    *ok=-(*ok);
                    vitesse(*ok, vit3,vit2,vit1,vit4);
                    for (i=0; i<*vit3; i++)
                    {
                      bg->x += 3;
                    bg->y +=(-1/9)*bg->x+2;
                    positionennemi->x += 3;
                    positionennemi->y +=(-1/9)*positionennemi->x+2;
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (detecter_collision_background (imageDeFondCollision, *pospers))
                     break;
                     }
                    SDL_Delay(40);
                    break ;
                  }
                    else
                    {
                       while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x-=25;
                      bg->y-=25;
                      positionennemi->x-=25;
                      positionennemi->y-=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }
                    }
                    if(bg->y>0)
                      bg->y-=2;
                  break;

                  case SDLK_KP2 :
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                        //entrer_reunion(*fenetre);
                        printf("1");
                      }
                    *image=anim_down(*mouvement);
                    (*mouvement)++;
                    *ok=-(*ok);
                    vitesse(*ok, vit4,vit2,vit3,vit1);
                    
                    for (i=0; i<*vit4; i++)
                    {
                      bg->x -= 3;
                    bg->y -=(-1/9)*bg->x+2;
                    positionennemi->x -= 3;
                    positionennemi->y -=(-1/9)*positionennemi->x+2;
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (detecter_collision_background (imageDeFondCollision, *pospers))
                     break;
                     }
                    SDL_Delay(40);
                    break ;
                  }
                    else
                    {
                       while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x+=25;
                      bg->y+=25;
                      positionennemi->x+=25;
                      positionennemi->y+=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }
                    }
                    if(bg->y>0)
                      bg->y-=2;
                  break;

                }
              
              // case SDL_MOUSEBUTTONUP :
              // X=event.button.x;
              // Y=event.button.y;
              // sprintf(ch,"%d %d",pospers.x,pospers.y);
              // texte = TTF_RenderText_Blended(police, ch, noir);
              //mouvement_souris(X,Y,&pospers,imageDeFondCollision);
}