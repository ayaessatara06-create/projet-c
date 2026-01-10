#inlude<stdio.h>
#include<stdint.h>
#include<openssl/evap.h>
#define BLOCK_SIZE 16
void xor(node* block1,node* block2,char * result)
{
    for(int i=0;i< BLOCK_SIZE;i++)
    {
        result[i]=block1[i]^block2[i];
    }
}
void encryption(node * head , const unsigned char* key, const unsigned char *iv)
{
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    node* current= head;
    unsigned char previous[16];
    memcpy(previous,iv,16);
    EVP_EncryptInit_ex(ctx,EVP_aes_128_ecb(),NULL,key,NULL);
    EVP_CIPHER_CTX_set_padding(ctx, 0);
    while(current!=NULL)
    {
        xor(current->data,previous,current->data);
        int len;
        EVP_EncryptUpdate(ctx,current->data,&len,current->data,16);
        memcpy(previous,current->data,16);
        current=current->nxt;
    }
    EVP_CIPHER_CTX_free(ctx);
}
