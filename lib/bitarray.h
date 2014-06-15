// =====================================================================================
// 
//       Filename:  bitarray.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  Sunday 15 June 2014 10:12:35  IST
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  lplay (tc), 
//        Company:  
// 
// =====================================================================================
#ifndef __BITARRAY__
#define __BITARRAY__

#include <stdint.h>

#define CELLUNIT 32
#define CELLSIZE 4 // size of cell in bytes 8*8=64

class BitArray {
	private:
		uint32_t numBytes;
		uint64_t numBits;
		uint32_t* array;	
		uint32_t getByteOffset(uint64_t bit);
		uint32_t getBitOffset(uint64_t bit);
	public:	
		BitArray(uint32_t numBits);
		void setBit(uint64_t bit);
		uint32_t getBit(uint64_t bit);
};

#endif

