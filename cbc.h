#include "linkedlist.h"
#ifndef CBC_H 
#define CBC_H
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#define BLOCK_SIZE 16
typedef struct 
{
    uint8_t iv[BLOCK_SIZE];
    uint8_t key[BLOCK_SIZE];
    void (*encryption)(node * head , const unsigned char* key, const unsigned char *iv)
    void (*decryption)(node * head , const unsigned char* key, const unsigned char *iv)
}CBC;
#endif
