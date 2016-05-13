#include "stage1.h"

void afficherscore(int score, SDL_Surface *fenetre)
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

void pershud(int score, SDL_Surface *fenetre)
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




void init_vitesse (int *v1, int *v2, int *v3, int *v4)
{
  *v4=1;
  *v3=1;
  *v2=1;
  *v1=1;
}

void vitesse (int ok, int *vit1, int *vit2, int *vit3, int *vit4)
{
  if (ok)
  *vit1= *vit1 +1;
  *vit2=1;
  *vit3=1;
  *vit4=1; 

}

void mvt_clavier (SDLKey bouton, SDL_Rect *bg, SDL_Surface *imageDeFondCollision, SDL_Rect *positionpers, int *mouvement, SDL_Rect *pospers, SDL_Surface **image, int *vit1, int *vit2, int *vit3, int *vit4, int *ok, SDL_Rect *positionennemi, int *dir, int *quit, int *save)
{
  int i,cond;
   switch(bouton)
                {
                  case SDLK_RETURN :
                  if(detecter_Pin(imageDeFondCollision, *pospers))
                      {
                        Reunion();
                        printf("1");
                      }
                      break;
                  case SDLK_RIGHT:
                  { *dir=1;
                    init_vitesse (vit1,vit2,vit3,vit4);
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                    *image=anim_right(mouvement);
                    (*mouvement)++;
                    bg->x -= 3;
                    bg->y +=(-1/9)*bg->x+2;
                    positionennemi->x = positionennemi->x - 3;
                    positionennemi->y +=(-1/9)*positionennemi->x+2;
                    SDL_Delay(40);
                    
                  }
                    else
                    {
                      while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x+=25;
                      bg->y-=25;
                      positionennemi->x+=25;
                      positionennemi->y-=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }  
                    }
                    if(bg->x <-7000)
                      bg->x+=2;
                    
                  }
                  break;
                  case SDLK_LEFT:
                  { *dir=2;
                    init_vitesse (vit1,vit2,vit3,vit4);
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                    *image=anim_left(mouvement);
                    (*mouvement)++;
                    bg->x += 3;
                    bg->y -=(-1/9)*bg->x+2;
                    positionennemi->x += 3;
                    positionennemi->y -=(-1/9)*positionennemi->x+2;
                    SDL_Delay(40);
                    }
                    else
                    {
                      while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x-=25;
                      bg->y+=25;
                      positionennemi->x-=25;
                      positionennemi->y+=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }
                    }
                    if(bg->x>0)
                      bg->x-=2;
                    break;
                  }
                  case SDLK_UP:
                  { *dir=3;
                    init_vitesse (vit1,vit2,vit3,vit4);
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                    *image=anim_up(mouvement);
                    (*mouvement)++;
                    bg->x += 3;
                    bg->y +=(-1/9)*bg->x+2;
                    positionennemi->x += 3;
                    positionennemi->y +=(-1/9)*positionennemi->x+2;
                    SDL_Delay(40);
                  }
                    else
                    {
                      while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x-=25;
                      bg->y-=25;
                      positionennemi->x-=25;
                      positionennemi->y-=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }
                    }
                    if(bg->y>0)
                      bg->y-=2;
                  
                  }
                  break;
                  case SDLK_DOWN:
                  { *dir=4;
                    init_vitesse (vit1,vit2,vit3,vit4);
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                    *image=anim_down(mouvement);
                    (*mouvement)++;
                    bg->x -= 3;
                    bg->y -=(-1/9)*bg->x+2;
                    positionennemi->x -= 3;
                    positionennemi->y -=(-1/9)*positionennemi->x+2;
                       SDL_Delay(40);
                  }
                    else
                    {
                      while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x+=25;
                      bg->y+=25;
                      positionennemi->x+=25;
                      positionennemi->y+=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }
                    }
                    if(bg->y<-5000)
                      bg->y+=2;
                  }
                  break;

                  case SDLK_KP6 :
                    *dir=1;
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                    *image=anim_right(mouvement);
                    (*mouvement)++;
                    *ok=-(*ok);
                    vitesse(*ok, vit1,vit2,vit3,vit4);
                    for (i=0; i<*vit1; i++)
                    {
                      bg->x -= 3;
                    bg->y +=(-1/9)*bg->x+2;
                    positionennemi->x -= 3;
                    positionennemi->y +=(-1/9)*positionennemi->x+2;
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (detecter_collision_background (imageDeFondCollision, *pospers))
                     break;
                     }
                    SDL_Delay(40);
                    break ;
                  }
                  else
                    {
                       while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x+=25;
                      bg->y-=25;
                      positionennemi->x+=25;
                      positionennemi->y-=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }
                    }
                    if(bg->x <-7000)
                      bg->x+=2;
                    
                  break;
                    
                    case SDLK_KP4 :
                    *dir=2;
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                    *image=anim_left(mouvement);
                    (*mouvement)++;
                    *ok=-(*ok);
                    vitesse(*ok, vit2,vit1,vit3,vit4);
                    for (i=0; i<*vit2; i++)
                    {
                      bg->x += 3;
                    bg->y -=(-1/9)*bg->x+2;
                    positionennemi->x += 3;
                    positionennemi->y -=(-1/9)*positionennemi->x+2;
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (detecter_collision_background (imageDeFondCollision, *pospers))
                     break;
                     }
                    SDL_Delay(40);
                    break ;
                  }
                    else
                    {
                       while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x-=25;
                      bg->y+=25;
                      positionennemi->x-=25;
                      positionennemi->y+=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }
                    }
                    if(bg->x>0)
                      bg->x-=2;
                    
                  break;

                  case SDLK_KP8 :
                    *dir=3;
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                    *image=anim_up(mouvement);
                    (*mouvement)++;
                    *ok=-(*ok);
                    vitesse(*ok, vit3,vit2,vit1,vit4);
                    for (i=0; i<*vit3; i++)
                    {
                      bg->x += 3;
                    bg->y +=(-1/9)*bg->x+2;
                    positionennemi->x += 3;
                    positionennemi->y +=(-1/9)*positionennemi->x+2;
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (detecter_collision_background (imageDeFondCollision, *pospers))
                     break;
                     }
                    SDL_Delay(40);
                    break ;
                  }
                    else
                    {
                       while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x-=25;
                      bg->y-=25;
                      positionennemi->x-=25;
                      positionennemi->y-=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }
                    }
                    if(bg->y>0)
                      bg->y-=2;
                  break;

                  case SDLK_KP2 :
                    *dir=4;
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (!detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                    *image=anim_down(mouvement);
                    (*mouvement)++;
                    *ok=-(*ok);
                    vitesse(*ok, vit4,vit2,vit3,vit1);
                    
                    for (i=0; i<*vit4; i++)
                    {
                      bg->x -= 3;
                    bg->y -=(-1/9)*bg->x+2;
                    positionennemi->x -= 3;
                    positionennemi->y -=(-1/9)*positionennemi->x+2;
                    pospers->x=-bg->x+positionpers->x;
                    pospers->y=-bg->y+positionpers->y;
                    if (detecter_collision_background (imageDeFondCollision, *pospers))
                     break;
                     }
                    SDL_Delay(40);
                    break ;
                  }
                    else
                    {
                       while (detecter_collision_background (imageDeFondCollision, *pospers))
                    {
                      bg->x+=25;
                      bg->y+=25;
                      positionennemi->x+=25;
                      positionennemi->y+=25;
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                     }
                    }
                    if(bg->y>0)
                      bg->y-=2;
                  break;
                  case SDLK_ESCAPE:
                    {

                      Smain(&cond);
                        
                      if (cond==1)
                      {
                        break;
                      }
                    if (cond==2)
                      {
                      *save=1;
                      *quit=1;
                      }
                    if (cond==3)
                      {
                        *quit=1;
                      }
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

void sauvegarde (int *save,SDL_Rect *bg)
  {
  FILE *f=fopen("chemin","w");
    fprintf (f," %d %d",bg->x,bg->y);
  fclose(f);
  }

  void Reunion()
  {
    SDL_Surface *texte[]={NULL,NULL,NULL,NULL,NULL,NULL}, *fenetre=NULL;
    TTF_Font *police = NULL;
    SDL_Color noir = {0, 0, 0};
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    fenetre = SDL_SetVideoMode(1300, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    police = TTF_OpenFont("western.ttf", 32);
    SDL_Event event1;
    SDL_Surface *restaurant,*question;
    int compteur=1,R=0,Question=0,check=0;
    SDL_Rect posquestion,posrestaurant,posq1uestion,posq1,posq2,posq3;
    SDL_Rect posperso;
    posquestion.x=450;
    posquestion.y=200;
    posrestaurant.x=200;
    posrestaurant.y=-100;
    posq1uestion.x=400;
    posq1uestion.y=0;
    posq1.x=450;
    posq1.y=250;
    posq2.x=450;
    posq2.y=350;
    posq3.x=450;
    posq3.y=450;
    restaurant=IMG_Load("map/kojina.png");
    question= IMG_Load("entities/liste.png");
    texte[0] = TTF_RenderText_Blended(police, "question ?", noir);
    texte[1] = TTF_RenderText_Blended(police, "question1 ?", noir);
    texte[2] = TTF_RenderText_Blended(police, "question2 ?", noir);
    texte[3] = TTF_RenderText_Blended(police, "question3 ?", noir);
    texte[4] = TTF_RenderText_Blended(police, "question4 ?", noir);
    while(compteur != 0) 
    {
      SDL_WaitEvent(&event1);
      if(event1.key.keysym.sym == SDLK_ESCAPE) 
        compteur =0;
      switch (event1.type) 
      {
         case SDL_MOUSEBUTTONUP :
           if (event1.button.button == SDL_BUTTON_LEFT)
           {
             if(check==0) 
              if (posq1.x <= event1.button.x && event1.button.x <= posq1.x + texte[1]->w && posq1.y <= event1.button.y && event1.button.y <= posq1.y + texte[1]->h)
             {
              texte[1] = TTF_RenderText_Blended(police, "question ?X", noir);
              R=1;
              check=1;
             }
             if(check==0)
              if (posq2.x <= event1.button.x && event1.button.x <= posq2.x + texte[2]->w && posq2.y <= event1.button.y && event1.button.y <= posq2.y + texte[2]->h)
             {
              texte[2] = TTF_RenderText_Blended(police, "question ?X", noir);
              R=2;
              check=1;
             }
              if(check==0)
             if (posq3.x <= event1.button.x && event1.button.x <= posq3.x + texte[3]->w && posq3.y <= event1.button.y && event1.button.y <= posq3.y + texte[3]->h)
             {
              texte[3] = TTF_RenderText_Blended(police, "question ?X", noir);
              R=3;
              check=1;
             }
           }
      }
    SDL_BlitSurface(restaurant,NULL, fenetre, &posrestaurant);
    SDL_BlitSurface(question,NULL, fenetre, &posq1uestion);
    SDL_BlitSurface(texte[0], NULL, fenetre, &posq1);
    SDL_BlitSurface(texte[1], NULL, fenetre, &posq2);
    SDL_BlitSurface(texte[2], NULL, fenetre, &posq3);
    SDL_BlitSurface(texte[3], NULL,fenetre, &posquestion);
    SDL_Flip(fenetre);
    }
    if(R==1 && Question==1)
    {
      printf("1");
    }
    else if(R==2 && Question==1)
    {
      printf("3");
    }
    else if(R==3 && Question==1)
    {
      printf("4");
    }
    else if(R==1 && Question==2)
    {
      printf("5");
    }
    else if(R==2 && Question==2)
    {
      printf("6");
    }
    else if(R==3 && Question==2)
    {
      printf("7");
    }
    else if(R==1 && Question==3)
    {
      printf("8");
    }
    else if(R==2 && Question==3)
    {
      printf("9");
    }
    else if(R==3 && Question==3)
    {
      printf("10");
    }
    TTF_CloseFont(police);
    TTF_Quit();
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
      ("%c",a);
    if(strcmp(&a,"r")==0)
                    { 
                      pospers->x=-bg->x+positionpers->x;
                      pospers->y=-bg->y+positionpers->y;
                      if (!detecter_collision_background (imageDeFondCollision, *pospers))
                      {
                        if(detecter_Pin(imageDeFondCollision, *pospers))
                        {
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
                          Reunion();
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
                          Reunion();
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
                          Reunion();
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

  void intro(SDL_Surface *fenetre)
{
  SDL_Rect posintro;
  posintro.x=200;
  posintro.y=0;
  SDL_Surface *introduction=IMG_Load("entities/intro_level1.png");
  SDL_BlitSurface(introduction,NULL,fenetre,&posintro);
  SDL_Flip(fenetre);
  SDL_Delay(20000);
}