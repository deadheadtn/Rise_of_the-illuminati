prog:fonctions.o main.o
	gcc fonctions.o main.o `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -o prog -g
main.o:main.c
	gcc -c main.c `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -g
fonctions.o:fonctions.c
	gcc -c fonctions.c `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -g
