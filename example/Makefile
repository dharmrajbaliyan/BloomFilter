SRC=*.cpp
INC=-I../lib/
FLAGS=-ggdb -Wall
LIBDIR=-L../lib/
LIBS=-lbloomfilter
TARGET=example 

all:
	g++ -o $(TARGET) $(SRC) $(INC) $(FLAGS) $(LIBDIR) $(LIBS) 

clean:
	rm -rf *.o
