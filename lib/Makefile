GCC=g++
SRC= *.cpp 
INCLUDE=-I.
OBJ=*.o
TARGET=libbloomfilter.so.1.0
default: all

compile:
	$(GCC) -fPIC -g -c $(INCLUDE) $(SRC)


all: clean compile 
	$(GCC) -shared -Wl,-soname,libbloomfilter.so.1.0 -o $(TARGET) $(OBJ)
	ln -s $(TARGET) libbloomfilter.so

clean:
	rm  *.so* $(OBJ) || true
