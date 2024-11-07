cc=g++ -g -Wall -Wextra -Werror
CFLAGS=$(shell pkg-config --cflags --libs sdl2)

INCLUDES=header
SRC=src

all :
	$(cc) main.cpp $(SRC)/*.c -I $(INCLUDES) -o mandlebrot $(CFLAGS)
