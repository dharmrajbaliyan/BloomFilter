#ifndef __BLOOMFILTER__
#define __BLOOMFILTER__

#include <stdint.h>
#include <bitarray.h>
#define MAXSEEDS 256

typedef uint32_t Key;

class BloomFilter {
	private:
		uint32_t numHashes;
		uint32_t hashSeeds[MAXSEEDS];
		BitArray* array;	
	public:
		void create(uint32_t numBits, uint32_t numHashes, uint32_t* hashSeeds);
		void addKey(Key* key);
		bool getKeyStatus(Key* key);
};
//Hashing related functions

uint32_t hashMrmr(uint32_t seed, Key* key, uint32_t len);
uint32_t hashJnkns(uint32_t seed, Key* key, uint32_t len);

#endif 
