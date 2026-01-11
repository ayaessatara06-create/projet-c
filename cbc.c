#include"cbc.h"
#include<stdio.h>
#include<stdint.h>
#include<openssl/evp.h> //in order to use all the openssl operations
#include<string.h>
#define BLOCK_SIZE 16 // to define that the blocks used are 16 octets


//xor function to perform on two blocks
void xor (unsigned char* block1, unsigned char* block2, unsigned char* result)
{
    for(int i=0;i< BLOCK_SIZE ;i++)
    {
        result[i]=block1[i] ^block2[i]; //appliquer le xor de chaque octect des deux block et stocker le resultat dans result
    }
}

// function to perform the encryption
void encryption(node* head,const unsigned char* key,const unsigned char* iv)
{
    EVP_CIPHER_CTX* ctx=EVP_CIPHER_CTX_new(); //donner une structure de contexte à openssl qui va stocker les données de l'algoritme après chiffrement
    node* current=head;
    unsigned char previous[16];
    memcpy(previous,iv,16);
    EVP_EncryptionInit_ex(ctx,EVP_aes_128_ecb(),NULL,key,NULL); initialiser en mode chiffrement AES_128
    EVP_CIPHER_CTX_set_padding(ctx,0); //désactiver le padding donc les données seront des multiples de 16 octets
    while(current!=NULL)
    {
        xor(current->data,previous,current->data);
        int len;
        EVP_EncryptUpdate(ctx,current->data,&len,current->data,16); //fonction de openssl qui fait le chiffrement des données
        memcpy(previous,current->data,16);
        current=current->nxt;
    }
    EVP_CIPHER_CTX_free(ctx); //liberer la mémoire utiliser pour éviter les fuites de mémoire
}



//function of decryption
void decryption(node* head,const unsigned char* key,const unsigned char* iv)
{
    EVP_CIPHER_CTX* ctx=EVP_CIPHER_CTX_new(); //donner une structure de contexe a openssl qui va stocker les données de l'algoritme après chiffrement
    node* current=head;
    unsigned char previous[16];
    unsigned char temp[16];
    memcpy(previous,iv,16);
    EVP_DecryptInit_ex(ctx,EVP_aes_128_ecb(),NULL,key,NULL); //initialiser en mode déchiffrement
    EVP_CIPHER_CTX_set_padding(ctx,0); //désactiver le padding donc les données seront des multiple de 16 octets
    while(current!=NULL)
    {
        memcpy(temp,current->data,16);
        int len;
        EVP_DecryptUpdate(ctx,current->data,&len,current->data,16); //fonction de openssl qui fait le déchiffrement de données
        xor(current->data,previous,current->data);
        memcpy(previous,temp,16);
        current=current->nxt;
    }
    EVP_CIPHER_CTX_free(ctx);//liberer la mémoire pour éviter les fuites de mémoires
}
