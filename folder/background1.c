#include "background1.h"

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

void clean_up(SDL_Surface **background, SDL_Surface **texte, SDL_Surface **image )
{
    SDL_FreeSurface( *background );
    SDL_FreeSurface( *texte );
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