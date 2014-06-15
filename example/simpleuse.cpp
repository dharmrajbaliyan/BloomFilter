#include <errno.h>
#include <math.h>  
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "bloomfilter.h"

int main ( int argc, char *argv[] ) {
	uint32_t seed[4] = {211, 311, 411, 511};
	uint32_t numBits = 64<<3;
	BloomFilter bf;
	bf.create(numBits, 4, seed);
	for(uint32_t i=0; i<10; ++i) {
		Key key = 2*i;
		bf.addKey(&key);
	}	
	for(uint32_t i=0; i<20; ++i) {		
		Key key = i;
		bool ret = bf.getKeyStatus(&key);
		printf("Key status: %d\n", ret);
	}	
}	

