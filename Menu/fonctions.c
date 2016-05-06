#include "fonctions.h"
void pause_fenetre()
{
    int ok = 1;
    SDL_Event event;
    
    while (ok)
    {
        SDL_WaitEvent(&event);
        if (event.type==SDL_QUIT || event.key.keysym.sym==SDLK_ESCAPE)  
                ok=0;
    }
}
void FPS_Fn() 
{
    int NextTick , interval ;
    if ( NextTick > SDL_GetTicks( ) )
    SDL_Delay( NextTick - SDL_GetTicks( ) );
    NextTick = SDL_GetTicks( ) + interval ;
    return;
}
void FPS_Initial() {
    int FPS = 1000000;
    int NextTick , interval ;
    NextTick = 0 ;
    interval = 1 * 1000 / FPS ;
    return;
}
void credit(SDL_Surface *fenetre)
{
    SDL_Surface *imageDeFond =NULL,*imagecredit=NULL;
    SDL_Rect pos,credit;
    SDL_Event e; 
    int compteur = 1; 
    imageDeFond = IMG_Load("Menu/fond.bmp");
    imagecredit = IMG_Load("Menu/credit.png");
    pos.x =0; 
    pos.y =0;
    credit.x=320;
    credit.y=100;

    SDL_BlitSurface(imageDeFond, NULL, fenetre, &pos);
    SDL_BlitSurface(imagecredit, NULL, fenetre, &credit);
    SDL_Flip(imagecredit);
    SDL_Flip(fenetre);
    while(compteur != 0) 
    {
        SDL_WaitEvent(&e);
        if(e.key.keysym.sym == SDLK_ESCAPE) 
            compteur =0;
    } 
    SDL_FreeSurface(imageDeFond);
}
void option(SDL_Surface *fenetre)
{
    SDL_Surface *imageDeFond =NULL,*imageoption=NULL,*texte = NULL,*texte1 = NULL,*texte2 = NULL;
    SDL_Rect pos,option,positiononoff,positionres1,positionres2;
    SDL_Event e; 
    int a=0,b=0,c=0;
    SDL_Event event;
    TTF_Font *police = NULL;
    TTF_Init();
    police = TTF_OpenFont("Font/western.ttf", 32);
    SDL_Color noir = {0, 0, 0};
    int compteur = 1; 
    imageDeFond = IMG_Load("Menu/fond.bmp");
    imageoption = IMG_Load("Menu/option.jpg");
    positiononoff.x= 620;
    positiononoff.y= 240;
    positionres1.x=620;
    positionres1.y=280;
    positionres2.x=620;
    positionres2.y=320;
    // positionres3.x=;
    // positionres3.y=;
    // positionres4.x=;
    // positionres4.y=;
    pos.x =0; 
    pos.y =0;
    option.x=380;
    option.y=100;

    SDL_Event event1;
    texte = TTF_RenderText_Blended(police, "On", noir);
    texte1 = TTF_RenderText_Blended(police, "1200x700", noir);
    texte2 = TTF_RenderText_Blended(police, "Window Mode", noir);
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
                        if (positiononoff.x <= event1.button.x && event1.button.x <= positiononoff.x + texte->w && positiononoff.y <= event1.button.y && event1.button.y <= positiononoff.y + texte->h)
                        {
                            printf("%d",a);
                            if(a==0){
                            texte = TTF_RenderText_Blended(police, "OFF", noir);
                            Mix_Volume(0,0);
                            a++;
                            }
                            else if (a==1)
                            {
                                texte = TTF_RenderText_Blended(police, "On", noir);
                                Mix_Volume(0,MIX_MAX_VOLUME/2);
                                a=0;
                            }
                        }
                        else if (positionres1.x <= event1.button.x && event1.button.x <= positionres1.x + texte1->w && positionres1.y <= event1.button.y && event1.button.y <= positionres1.y + texte1->h)
                        {
                            printf("%d",b);
                            if(b==0){
                                texte1 = TTF_RenderText_Blended(police, "800x600", noir);
                                fenetre = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                                b++;
                            }
                            else if (b==1)
                            {
                                texte1 = TTF_RenderText_Blended(police, "1200x700", noir);
                                fenetre = SDL_SetVideoMode(1200, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                                b=0;
                            }
                        }
                        else if (positionres2.x <= event1.button.x && event1.button.x <= positionres2.x + texte2->w && positionres2.y <= event1.button.y && event1.button.y <= positionres2.y + texte2->h)
                        {
                            printf("%d",c);
                            if(c==0){
                                texte2 = TTF_RenderText_Blended(police, "Full Screen", noir);
                                fenetre = SDL_SetVideoMode(1200, 700, 32, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF);
                                c++;
                            }
                            else if (c==1)
                            {
                                texte2 = TTF_RenderText_Blended(police, "Window Mode", noir);
                                fenetre = SDL_SetVideoMode(1200, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                                c=0;
                            }
                        }
                    }
    }  
    SDL_BlitSurface(imageDeFond, NULL, fenetre, &pos);
    SDL_BlitSurface(imageoption, NULL, fenetre, &option);
    SDL_BlitSurface(texte, NULL, fenetre, &positiononoff);
    SDL_BlitSurface(texte1, NULL, fenetre, &positionres1);
    SDL_BlitSurface(texte2, NULL, fenetre, &positionres2);
    SDL_Flip(imageoption);
    SDL_Flip(fenetre);
    }       
    SDL_FreeSurface(imageDeFond);
}

void loadgame()
{
    char ch[15];
    FILE *file=fopen("savedchgames/save.txt", "r");
    while(!feof(file))
    {
        fscanf(file,"%s",ch);
        printf("%s",ch);
    }
}
// int UpdateScroll(Map* m)
// {
//     int cxperso,cyperso,xlimmin,xlimmax,ylimmin,ylimmax;
//     if (m->tofocus==NULL)
//         return -1;
//     cxperso = m->tofocus->x + m->tofocus->w/2;
//     cyperso = m->tofocus->y + m->tofocus->h/2;
//     xlimmin = m->xscroll + m->rectlimitscroll.x;
//     ylimmin = m->yscroll + m->rectlimitscroll.y;
//     xlimmax = xlimmin + m->rectlimitscroll.w;
//     ylimmax = ylimmin + m->rectlimitscroll.h;
//     if (cxperso<xlimmin)
//         m->xscroll -= (xlimmin-cxperso);
//     if (cyperso<ylimmin)
//         m->yscroll -= (ylimmin-cyperso);
//     if (cxperso>xlimmax)
//         m->xscroll += (cxperso-xlimmax);
//     if (cyperso>ylimmax)
//         m->yscroll += (cyperso-ylimmax);
//     ClampScroll(m);
//     return 0;
// }

// void deplacementennemie()
// {
//     SDL_Surface *voiture =NULL;
//     int i;
//     SDL_Rect positiononoff;
//     positiononoff.y= 240;
//     voiture = IMG_Load("objet/car.png");
//     positiononoff.x= 620;
//     positiononoff.y= 240;
//     while(x=0)
//     {
//         i++;
//         if(i<10000)
//          { positionpers.x=positionpers.x+5;
//            positionpers.y=(-86/152.0)*positionpers.x+873.25;
//            voiture = IMG_Load("pers11.png");
//         }
//         else if(i>10000)
//         {
//             positionpers.x=positionpers.x+5;
//             positionpers.y=(-86/152.0)*positionpers.x+873.25;}                      
//             voiture = IMG_Load("pers11.png");
//         }
//         SDL_BlitSurface(positiononoff, NULL, fenetre, &pos);
// }

// void Sroll(SDL_Surface *background)
// {
//     while( quit == false )
//     {
//         fps.start();
//         while( SDL_PollEvent( &event ) )
//         {   
//             if( event.type == SDL_QUIT )
//             {
//                 quit = true;
//             }
//         }
//         bgX =(-86/152.0)*bgY+873.25;
//         bgY= (-86/152.0)*bgX+873.25;
//         if( bgX <= -background->w || bgY<=-background->h)
//         {
//             bgX = 0;
//             bgY = 0;
//         }    
// }
//         apply_surface( bgX, bgY, background, screen );
//         apply_surface( bgX + background->w, bgY, background, screen );
//         apply_surface( 310, 230, dot, screen );
//         if( SDL_Flip( screen ) == -1 )
//         {
//             return 1;    
//         }
//         if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
//         {
//             SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
//         }
    
// }
