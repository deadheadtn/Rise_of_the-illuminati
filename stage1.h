#ifndef STAGE1_H_
#define STAGE1_H_
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>

void afficherscore(int score, SDL_Surface *fenetre);
void pershud(int score, SDL_Surface *fenetre);
void mvt_clavier (int *reun,SDLKey bouton, SDL_Rect *bg, SDL_Surface *imageDeFondCollision, SDL_Rect *positionpers, int *mouvement, SDL_Rect *pospers, SDL_Surface **image, int *vit1, int *vit2, int *vit3, int *vit4, int *ok, SDL_Rect *positionennemi, int *dir, int *quit, int *save);
void vitesse (int ok, int *vit1, int *vit2, int *vit3, int *vit4);
void init_vitesse (int *v1, int *v2, int *v3, int *v4);
void afficherpin(SDL_Surface* destination);
void mouvement_souris (int X, int Y, SDL_Rect *pospers, SDL_Surface *imageDeFondCollision);
void pershud(int score, SDL_Surface *fenetre);
void afficherscore(int score, SDL_Surface *fenetre);
void sauvegarde (int *save,SDL_Rect *bg);
void Reunion();
int arduinoReadData(char *c);
int arduinoWriteData(int k);
void mvt_arduino (int *reun,SDL_Rect *bg, SDL_Surface *imageDeFondCollision, SDL_Rect *positionpers, int *mouvement, SDL_Rect *pospers, SDL_Surface **image);
void intro(SDL_Surface *fenetre);

#endif /* STAGE1_H_ */