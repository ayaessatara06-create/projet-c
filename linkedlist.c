#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
node * createnode(int data)
{
    node*tmp=(node*)malloc(sizeof(node));
    tmp->data=data;
    tmp->nxt=NULL;
    return tmp;
}
node* addhead(node*head,int data)
{
    if(!head)
        return head=createnode(data);
    node*tmp=createnode(data);
    tmp->nxt=head;
    head=tmp;
    return tmp;
}
node *deletenode(node*head,int data)
{
    if(!head)
        return head;
    node*tmp=head;
    if(head->data==data)
    {
        head=tmp->nxt;
        free(tmp);
        return head;
    }
    while(tmp->nxt && tmp->nxt->data!=data)
    {
        tmp=tmp->nxt;
    }
    if(tmp->nxt)
    {
        node*tmp2=tmp->nxt;
        tmp->nxt=tmp2->nxt;
        free(tmp2);
    }
    return head;
}
node *display(node*head)
{
    node*tmp=head;
    while(tmp)
    {
        printf("%d\t",tmp->data);
        tmp=tmp->data;
    }
}


