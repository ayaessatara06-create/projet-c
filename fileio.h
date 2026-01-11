#include "linkedlist.h"
#ifndef FILEIO_H //si le fichier n'est pas définie
#define FILEIO_H
#include<stdio.h>
void list_to_file(char* filename,node* head); //recall of the function list_to_file
node* file_to_list(char* filename);//recall of the function file_to_list
#endif // FILEIO_H
