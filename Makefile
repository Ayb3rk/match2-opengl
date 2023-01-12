all:
	g++ *.cpp -g -o main \
        `pkg-config --cflags --libs freetype2` \
        -lglfw -lGLU -lGL -lGLEW 
