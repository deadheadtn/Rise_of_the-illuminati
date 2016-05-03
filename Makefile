prog: main.o
	gcc main.o `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -o prog -g
main.o:main.c
	gcc -c main.c `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -g