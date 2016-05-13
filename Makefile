prog:stage1.o ennemi.o perso1.o background1.o main.o
	gcc stage1.o ennemi.o perso1.o background1.o main.o `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -o prog -g
stage1.o:stage1.c
	gcc -c stage1.c `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -g
ennemi.o:ennemi.c
	gcc -c ennemi.c `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -g
perso1.o:perso1.c
	gcc -c perso1.c `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -g
background1.o:background1.c
	gcc -c background1.c `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o:main.c
	gcc -c main.c `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -g
