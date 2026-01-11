#ifndef CBC_H
#define CBC_H
#include "linkedlist.h"
void xor(unsigned char* block1,unsigned char* block2, unsigned char* result);
void encryption(node* head,const unsigned char* key,const unsigned char*iv);
void decryption(node* head,const unsigned char* key,const unsigned char*iv);
#endif // CBC_H
