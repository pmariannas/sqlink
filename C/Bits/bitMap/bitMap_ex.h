#ifndef BITMAP_H
#define BITMAP_H

typedef struct 
{
    int m_nf;           /*number of feature*/  
    int* m_bitArray;    

}bitMap_t;
typedef int (*bitFunc)(bitMap_t* , int);
int callFunc(bitFunc func, bitMap_t* bm, int n);
bitMap_t* createBitMap(int nf);
int bitOn(bitMap_t* bm, int n);
int bitOff(bitMap_t* bm, int n);
int bitStatus(bitMap_t* bm, int n);
int printBitMap(bitMap_t* bm);
void destroyBitMap(bitMap_t* bm);


#endif