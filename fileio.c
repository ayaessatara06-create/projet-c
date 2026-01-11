#include "linkedlist.h"
#include "fileio.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


// function to turn a list (liste chaine) into a file
void liste_to_file(char* filename,node* head)
{
    FILE* fp=fopen(filename,"wb");
    if(fp==NULL)
        return;
    node*current=head;
    while(current!=NULL)
    {
        fwrite(current->data,1,16,fp);
        current=current->nxt;
    }
    fclose(fp);
}
// function to turn a file into a list (liste chaine)
node* file_to_list(char* filename)
{
    FILE* fp=fopen(filename,"rb");
    if(fp==NULL)
        return NULL;
    node* head=NULL;
    node* tail=NULL;
    unsigned char tmp[16];
    size_t n;
    while((n=fread(tmp,1,16,fp))>0)
    {
        if(n<16)
            memset(tmp+n,0,16-n);
        node* maillon=(node*)malloc(sizeof(node));
        if(maillon==NULL)
            break;
        memcpy(maillon->data,tmp,16);
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
