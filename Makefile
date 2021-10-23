all: compile run

compile:
	g++ -I dep/include/ -I dep/include/stb_image -L dep/lib/ -o bin/main main.cpp src/*.c src/*.cpp -lglfw3 -lglew32 -lopengl32 -lgdi32 -lwinmm -lshell32 -luser32
run:
	bin/main