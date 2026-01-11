#ifndef LINKEDLIST_H //si le fichier n'est pas définie
#define LINKEDLIST_H
#include<stdint.h>
typedef struct node
{
    unsigned char data[16];
    struct node* nxt;
}node;
void display(node* head);
node* createnode(unsigned char* data);
#endif // LINKEDLIST_H
