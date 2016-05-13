#ifndef PERSO1_H_
#define PERSO1_H_
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 

SDL_Surface *anim_right(int *mouvement);
SDL_Surface *anim_left(int *mouvement);
SDL_Surface *anim_up(int *mouvement);
SDL_Surface *anim_down(int *mouvement);
void sauvegarde (int *save,SDL_Rect *bg); 
void Reunion();



#endif /* PERSO1_H_ */