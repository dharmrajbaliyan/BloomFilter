#include "bitarray.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

BitArray::BitArray(uint32_t numBits) {
	this->numBits = numBits;
	this->numBytes = (numBits)/sizeof(char);

	array = (uint32_t*)malloc(this->numBytes*CELLSIZE);
	assert(this->array != NULL);
}

uint32_t BitArray::getBit(uint64_t bit) {
	bit = bit%this->numBits;
	return array[getByteOffset(bit)] & getBitOffset(bit);
}

void BitArray::setBit(uint64_t bit) {
	bit = bit%(this->numBits);
	array[getByteOffset(bit)] |= getBitOffset(bit); 
}

uint32_t BitArray::getByteOffset(uint64_t bit) {
	return bit/CELLUNIT;	
}

uint32_t BitArray::getBitOffset(uint64_t bit) {
	return 1<<bit%CELLUNIT;	
}
