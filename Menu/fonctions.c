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
    SDL_Surface *imageDeFond =NULL,*imagecredit=NULL,*texte = NULL;
    SDL_Rect pos,credit,positiononoff;
    SDL_Event e; 
    SDL_Event event;
    TTF_Font *police = NULL;
    TTF_Init();
    police = TTF_OpenFont("Font/western.ttf", 32);
    SDL_Color noir = {0, 0, 0};
    int compteur = 1; 
    imageDeFond = IMG_Load("Menu/fond.bmp");
    imagecredit = IMG_Load("Menu/option.jpg");
    positiononoff.x= 620;
    positiononoff.y= 240;
    pos.x =0; 
    pos.y =0;
    credit.x=380;
    credit.y=100;
    texte = TTF_RenderText_Blended(police, "On/Off", noir);

    SDL_BlitSurface(imageDeFond, NULL, fenetre, &pos);
    SDL_BlitSurface(imagecredit, NULL, fenetre, &credit);
    SDL_BlitSurface(texte, NULL, fenetre, &positiononoff);
    SDL_Flip(imagecredit);
    SDL_Flip(fenetre);
    while(compteur != 0) 
    {
        SDL_WaitEvent(&e);
        if(e.key.keysym.sym == SDLK_ESCAPE) 
            compteur =0;
    } 
           // case SDL_MOUSEBUTTONUP :
             //         if (event.texte.texte)
              //        {

                        //if (positiononoff.x <= 860 && event.button.x <= positiononoff.x + 10 && positiononoff.y <= 240 && 240 <= positiononoff.y + 10) 
    SDL_FreeSurface(imageDeFond);
}

void loadgame()
{
    char str[20];
    SDL_Surface *texte=NULL;
    TTF_Font *police = NULL;
    TTF_Init();
    police = TTF_OpenFont("Font/western.ttf", 32);
    SDL_Color noir = {0, 0, 0};
    FILE *file=fopen("save.txt", "r");
    SDL_Rect pos;
    pos.x=700;
    pos.y=300;
    if (file) {
    while (fscanf(file, "%s", str)!=EOF)
        texte = TTF_RenderText_Blended(police, str, noir);
    fclose(file);
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
