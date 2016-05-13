#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "stdio.h"
#include <string.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <math.h>
#include "background1.h"
#include "main.h"
#include "perso1.h"
#include "stage1.h"
#include "ennemi.h"

int main( int argc, char* args[] )
{
    int quit = 0,mouvement=0,m,nbreunion=0,save=0;
    int reun=0,n,intr=0;
    SDL_Rect positionpers,positiontexte,pospers,bg, positionennemi;
    SDL_Surface *background = NULL,*imageDeFondCollision=NULL, *fenetre = NULL, *ennemi = NULL;
    positionpers.x=638;
    positionpers.y=338;
    positionennemi.x=700;
    positionennemi.y=338;
    positiontexte.x=0;
    positiontexte.y=0;
    int score=0, vit1=1, vit2=1,vit3=1,vit4=1,ok=1,dir,menup,action,int reun=0;
    menup=Pmenu(&action) ;
    int bgX, bgY;
    if (action==1)
      {
        FILE *f=fopen("chemin","w");
        bgX = -2500;
        bgY = -3350;
        fprintf(f,"%d %d %d",score,bgX,bgY);
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
    bg.y=bgY;
    SDL_Event event;
    SDL_Surface *image=NULL;
    TTF_Font *police = NULL;
    SDL_Color noir = {0, 0, 0};
    /*TTF_Init();
    police = TTF_OpenFont("western.ttf", 32);
    texte = TTF_RenderText_Blended(police, "", noir);*/
    char ch[10];
    double d,d1;
    STATE S=WAITING;
    ennemi = IMG_Load( "dos.png" );
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
              mvt_clavier (&reun,event.key.keysym.sym, &bg,imageDeFondCollision,&positionpers,&mouvement,&pospers, &image, &vit1, &vit2, &vit3, &vit4,&ok,&positionennemi,&dir,&quit,&save);
              //mvt_arduino (&reun,&bg,imageDeFondCollision,&positionpers,&mouvement,&pospers, &image);
        }
      }
  }

     d= abs(positionpers.x-positionennemi.x);
     d1= abs(positionpers.y-positionennemi.y);   
            if (S== WAITING && (d>=50 && d1>=50))
            {
              S = WAITING;
              UpdateEnnemi(S,&positionennemi,dir);
            }
            else if (S== WAITING && (d<50 && d1<50))
            {
              S = HAREB;
              UpdateEnnemi(S,&positionennemi,dir);
            }
            else if (S== HAREB && (d>=50 && d1>=50))
            {
              S = WAITING;
              UpdateEnnemi(S,&positionennemi,dir);
            }
            else if (S== HAREB && (d<50 & d1<50))
            {
              S = HAREB;
              UpdateEnnemi(S,&positionennemi,dir);
            }
            else if (S== WAITING && (d>=50 && d1>=50))
            {
              S = WAITING;
              UpdateEnnemi(S,&positionennemi,dir);
            }
        if(reun==0)
        {
        apply_surface( bg.x, bg.y, background, fenetre );
        apply_surface( positionpers.x, positionpers.y, image, fenetre );
        //SDL_BlitSurface(texte, NULL, fenetre, &positiontexte);
        SDL_BlitSurface(ennemi, NULL, fenetre, &positionennemi);
        pershud(score,fenetre);
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
  else if (save==0)
  {
FILE *f=fopen("chemin","w");
        bgX = -2500;
        bgY = -3350;
        fprintf(f,"%d %d %d",score,bgX,bgY);
    
  }
    clean_up(&background,&image);
    //SDL_FreeSurface( background );
    //SDL_FreeSurface( texte );
    //SDL_FreeSurface( image );
    SDL_FreeSurface(ennemi);
    //return 0;
}
