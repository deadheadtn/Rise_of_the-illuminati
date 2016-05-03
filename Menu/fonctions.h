#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
void pause_fenetre();
void FPS_Fn();
void FPS_Initial();
void credit(SDL_Surface *fenetre);
void loadgame();
void option(SDL_Surface *fenetre);

#endif /* FONCTIONS_H_ */
