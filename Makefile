prog: main.o
	gcc main.o `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -o prog -g
fgifsdl.o:fgifsdl.c
	gcc -c fgifsdl.c `sdl-config --cflags --libs --fgifsdl` -lSDL_image -g
main.o:main.c
	gcc -c main.c `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -g

