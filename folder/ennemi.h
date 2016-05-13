#ifndef ENNEMI_H_
#define ENNEMI_H_
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 

typedef enum STATE STATE;
enum STATE 
{WAITING, HAREB};

void afficher_ennemi ( SDL_Surface *car1, SDL_Surface *car2, SDL_Surface *fenetre, SDL_Rect t_ennemis[] );
void UpdateEnnemi(STATE S,SDL_Rect *positionennemi);

#endif /* ENNEMI_H_ */