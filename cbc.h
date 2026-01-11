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
    void (*encryption)(uint8_t *in ,uint8_t *out , uint8_t *key);
    void (*decryption)(uint8_t *in ,uint8_t *out , uint8_t *key);
}CBC;
#endif;
