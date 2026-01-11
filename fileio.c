#include "linkedlist.h"
#include "fileio.h"
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
void list_to_file(char* filename,node* head)
{
    FILE* fp=fopen(filename,"w");
    if(fp==NULL)
        return;
    node*current=head;
    while(current!=NULL)
    {
        fprintf(fr,"%s\n",current->data);
        current=current->nxt;
    }
    fclose(fp);
}
node* file_to_list(char* filename)
{
    FILE* fp=fopen(filename,"r");
    if(fr==NULL)
        return NULL;
    node* head=NULL;
    node* tail=NULL;
    char tmp[100];
    while(fscanf(fp,"%99s",tmp)!=EOF)
    {
        node* maillon=(node*)malloc(sizeof(node));
        if(maillon==NULL) break;
        strcpy(maillon->data,tmp);
        if(head==NULL)
        {
            head=maillon;
            tail=maillon;
        }
        else
        {
            tail->nxt=maillon;
            tail=maillon;
        }
    }
    fclose(fp);
    return head;
}


