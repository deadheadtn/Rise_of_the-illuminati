#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "stdio.h"
#include <string.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

const int fenetre_WIDTH = 1300;
const int fenetre_HEIGHT = 700;
const int fenetre_BPP = 32;
const int FRAMES_PER_SECOND = 50;
SDL_Surface *background = NULL,*imageDeFondCollision=NULL;
SDL_Surface *fenetre = NULL;
SDL_Event event;
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
    {*mouvement=0;}
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
  if(strcmp(&a,"r")==0)
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


void mvt_clavier (SDLKey bouton, SDL_Rect *bg, SDL_Surface *imageDeFondCollision, SDL_Rect *positionpers, int *mouvement, SDL_Rect *pospers, SDL_Surface **image)
{
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
                        //entrer_reunion(*fenetre);
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
                  break;
                  case SDLK_LEFT:
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
                  break;
                  case SDLK_DOWN:
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
                  break;

                }
              // case SDL_MOUSEBUTTONUP :
              // X=event.button.x;
              // Y=event.button.y;
              // sprintf(ch,"%d %d",pospers.x,pospers.y);
              // texte = TTF_RenderText_Blended(police, ch, noir);
              //mouvement_souris(X,Y,&pospers,imageDeFondCollision);
             }

int main( int argc, char* args[] )
{
    int quit = 0,mouvement=0,m;
    SDL_Rect positionpers,positiontexte,pospers,bg;
    positionpers.x=638;
    positionpers.y=338;
    positiontexte.x=0;
    positiontexte.y=0;
    int score=300;
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
              mvt_clavier (event.key.keysym.sym, &bg,imageDeFondCollision,&positionpers,&mouvement,&pospers, &image);
              mvt_arduino (&bg,imageDeFondCollision,&positionpers,&mouvement,&pospers, &image);
        }
      }
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
    clean_up();
    return 0;
}
