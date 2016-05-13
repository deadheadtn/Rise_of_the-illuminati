#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "stdio.h"
#include <string.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <math.h>
#include "background1.h"
#include "main.h"
#include "menu.h"
#include "perso1.h"
#include "stage1.h"
#include "ennemi.h"

int main( int argc, char* args[] )
{
    int quit = 0,mouvement=0,m;
    SDL_Rect positionpers,positiontexte,pospers,bg, positionennemi;
    positionpers.x=638;
    positionpers.y=338;
    positionennemi.x=700;
    positionennemi.y=338;
    positiontexte.x=0;
    positiontexte.y=0;
    int score=300, vit1=1, vit2=1,vit3=1,vit4=1,ok=1;
    int bgX = -2500, bgY = -3350;
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
    SDL_Surface *background = NULL,*imageDeFondCollision=NULL, *fenetre = NULL, *ennemi = NULL;
    double d;
    STATE S=WAITING;
    ennemi = IMG_Load( "entities/car_right.png" );
    if( init(&fenetre) == 0 )
    {
        return 1;
    }
    if( load_files(&background,&imageDeFondCollision) == 0 )
    {
        return 1;
    }
    SDL_EnableKeyRepeat(50,50);
    while( quit == 0 )
    {
     while (SDL_PollEvent(&event))
       { switch (event.type)
        {
                      
            case SDL_QUIT : 
               quit=1; break;
             case SDL_KEYDOWN :
             {
              mvt_clavier (event.key.keysym.sym, &bg,imageDeFondCollision,&positionpers,&mouvement,&pospers, &image, &vit1, &vit2, &vit3, &vit4,&ok,&positionennemi);
              //mvt_arduino (&bg,imageDeFondCollision,&positionpers,&mouvement,&pospers, &image);
        }
      }
  }

     d= abs(positionpers.x-positionennemi.x);
     printf("%f\n",d );      
            if (S== WAITING && d>=50)
            {
              S = WAITING;
              UpdateEnnemi(S,&positionennemi);
            }
            else if (S== WAITING && d<50)
            {
              S = HAREB;
              UpdateEnnemi(S,&positionennemi);
            }
            else if (S== HAREB && d>=50)
            {
              S = WAITING;
              UpdateEnnemi(S,&positionennemi);
            }
            else if (S== HAREB && d<50)
            {
              S = HAREB;
              UpdateEnnemi(S,&positionennemi);
            }
            else if (S== WAITING && d>=50)
            {
              S = WAITING;
              UpdateEnnemi(S,&positionennemi);
            }
             printf("ennemi %d\n",positionennemi.x);
             printf("bg%d\n",bg.x);
        apply_surface( bg.x, bg.y, background, fenetre );
        apply_surface( positionpers.x, positionpers.y, image, fenetre );
        SDL_BlitSurface(texte, NULL, fenetre, &positiontexte);
        SDL_BlitSurface(ennemi, NULL, fenetre, &positionennemi);
        pershud(score,fenetre);
        //afficherpin(fenetre);
       // afficherscore(score);
        if( SDL_Flip( fenetre ) == -1 )
            return 1;
        SDL_FillRect(fenetre,NULL,0);
    }
    clean_up(background,image,texte);
    SDL_FreeSurface( background );
    SDL_FreeSurface( texte );
    SDL_FreeSurface( image );
    SDL_FreeSurface(ennemi);
    return 0;
}
