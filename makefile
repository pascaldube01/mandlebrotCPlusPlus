cc=g++ -g -Wall -Wextra -Werror
CFLAGS=$(shell pkg-config --cflags --libs sdl2)

INCLUDES=header
SRC=src

all :
	time $(cc) main.cpp $(SRC)/*.cpp -I $(INCLUDES) -o mandlebrot $(CFLAGS)
