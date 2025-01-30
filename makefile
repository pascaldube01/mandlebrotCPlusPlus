cc=g++ -g -std=c++20 -Wall -Wextra
CFLAGS=$(shell pkg-config --cflags --libs sdl2)
OPTIM= -O0
INCLUDES=header
SRC=src

all : 	$(SRC)/window.o \
		$(SRC)/quadratic.o \
		$(SRC)/mandlebrot_image.o \
		$(SRC)/user_input.o 
	$(cc) -g $(OPTIM) $(SRC)/*.* -I $(INCLUDES) -o mandlebrot $(CFLAGS)




$(SRC)/window.o : $(SRC)/window/window.cpp $(INCLUDES)/window.h
	$(cc) -g -c $(OPTIM)  $(SRC)/window/window.cpp -I $(INCLUDES) -o $(SRC)/window.o $(CFLAGS)

$(SRC)/quadratic.o : $(SRC)/quadratic/quadratic.cpp $(INCLUDES)/quadratic.h
	$(cc) -g -c $(OPTIM)  $(SRC)/quadratic/quadratic.cpp -I $(INCLUDES) -o $(SRC)/quadratic.o $(CFLAGS)

$(SRC)/mandlebrot_image.o : $(SRC)/mandlebrot_image/mandlebrot_image.cpp $(INCLUDES)/mandlebrot_image.h
	$(cc) -g -c $(OPTIM)  $(SRC)/mandlebrot_image/mandlebrot_image.cpp -I $(INCLUDES) -o $(SRC)/mandlebrot_image.o $(CFLAGS)

$(SRC)/user_input.o : $(SRC)/user_input/user_input.cpp $(INCLUDES)/user_input.h
	$(cc) -g -c $(OPTIM)  $(SRC)/user_input/user_input.cpp -I $(INCLUDES) -o $(SRC)/user_input.o $(CFLAGS)





clean : 
	rm $(SRC)/*.o