#include "perso1.h"


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
    {*mouvement=0;}
  return perso_right[*mouvement];
}