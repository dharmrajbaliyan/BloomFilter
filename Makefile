
DIRS=lib example

default: all

all: subprojects 

subprojects:
	for sub in ${DIRS}; do \
		make -C $${sub} all;\
	done

run:
	LD_LIBRARY_PATH=./lib/ ./example/example 
