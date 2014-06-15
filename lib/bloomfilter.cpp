#include "bloomfilter.h"
#include "murmurhash.h"
#include "jenkins.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void BloomFilter::create(uint32_t numBits, uint32_t numHashes, uint32_t* hashSeeds) {
	this->numHashes = numHashes;
	memset(this->hashSeeds, 0, sizeof(uint32_t)*MAXSEEDS);
	memcpy(this->hashSeeds, hashSeeds, sizeof(uint32_t)*numHashes);

	this->array = new BitArray(numBits);
}


void BloomFilter::addKey(Key* key) {
	for(size_t i=0; i<this->numHashes; ++i) {
		uint32_t res = i%2==0?hashMrmr(this->hashSeeds[i], key, sizeof(Key))
							 :hashJnkns(this->hashSeeds[i], key, sizeof(Key));
		this->array->setBit(res);
	}		
}

bool BloomFilter::getKeyStatus(Key* key)
{
	bool ret = true;	
	for(size_t i=0; i<this->numHashes; ++i)
	{
		uint32_t res = i%2==0?hashMrmr(this->hashSeeds[i], key, sizeof(Key))
					:hashJnkns(this->hashSeeds[i], key, sizeof(Key));
		uint32_t status = array->getBit(res);
		if(status == 0)
		{
			ret = false;
			break;	
		}
	}		
	return ret;
}

uint32_t hashJnkns(uint32_t seed, Key* key, uint32_t len)
{
	uint32_t res = JenkinsHash((ub1*)key, len, seed);
	return res;	
}
uint32_t hashMrmr(uint32_t seed, Key* key, uint32_t len)
{
	uint32_t res = 0;
	MurmurHash3_x86_32(key, len, seed, &res);
	return res;	
}


