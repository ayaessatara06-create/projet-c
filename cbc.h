#ifndef CBC_H //si le fichier n'est pas definie
#define CBC_H
#include "linkedlist.h"
void xor(unsigned char* block1,unsigned char* block2, unsigned char* result); //recall of the function xor
void encryption(node* head,const unsigned char* key,const unsigned char*iv); // recall of the function encryption
void decryption(node* head,const unsigned char* key,const unsigned char*iv); // recall of the function decryption
#endif // CBC_H
