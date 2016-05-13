#include "ennemi.h"
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

void UpdateEnnemi(STATE S,SDL_Rect *positionennemi)
{
	int i;
   switch (S)
   {
     case WAITING :
              //AnnimateEnnemi(E,0,e);
              break;
     case HAREB : 
                  //AnnimateEnnemi(E,0,e);
                   for (i=0; i<10; i++)
                   {positionennemi->x -= 3;
                   positionennemi->y +=(-1/9)*positionennemi->x+2;}
                  break;
   }

}