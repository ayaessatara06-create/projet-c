#include "linkedlist.h"
#ifndef FILEIO_H
#define FILEIO_H
#include<stdio.h>
typedef struct node
{
    char data;
    struct node* nxt;
}node;
void list_to_file(char* filename,node* head);
node* file_to_list(char* filename);
#endif 
