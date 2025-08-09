compiler=g++

headers= -I./lib/include

libs=./lib/glad.c -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl -I./lib/include/ -I./src/include/

src=./src/main.c

build:
	${compiler} ${src} ${libs} -o output/enigma

run:
	./output/enigma

valgrind:
	valgrind ./output/enigma
