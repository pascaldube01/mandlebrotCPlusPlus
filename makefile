cc=g++ -g -Wall -Wextra
CFLAGS=$(shell pkg-config --cflags --libs sdl2)

INCLUDES=header
SRC=src

all :
	time $(cc) -g -O0 main.cpp $(SRC)/*.cpp -I $(INCLUDES) -o mandlebrot $(CFLAGS)
