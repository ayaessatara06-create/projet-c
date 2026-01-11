#include "linkedlist.h"
#include "fileio.h"
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
void list_to_file(char* filename,node* head)
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
node* file_to_list(char* filename)
{
    FILE* fp=fopen(filename,"rb");
    if(fr==NULL)
        return NULL;
    node* head=NULL;
    node* tail=NULL;
    uint8_t tmp[16];
    size_t n;
    while(n=fread(tmp,1,16,fp)>0)
    {
        if(n<16) memset(tmp+n,0,16-n);
        node* maillon=(node*)malloc(sizeof(node));
        if(maillon==NULL) break;
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


