#ifndef BACKGROUND1_H_
#define BACKGROUND1_H_
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination);
int init();
SDL_Surface *load_image(char *nom);
int load_files();
void clean_up();
SDL_Rect limit(int x, int y);
SDL_Color GetPixel (SDL_Surface* pSurface, int x, int y);
int detecter_collision_background (SDL_Surface *image, SDL_Rect position);
int detecter_Pin (SDL_Surface *image, SDL_Rect position);
void option();
int Pmenu(int *action);
void Smain (int *cond);


#endif /* BACKGROUND1_H_ */