#include<stdio.h>
#define size 5
typedef struct node
{
    int key[size-1];
    struct node* pointer[size];
}node;


void insert(node **root,int n)
{
    int i=0;
    if(*root==NULL)
    {
        node* temp=(node*)malloc(sizeof(node));
        for(i=0;i<size-1;i++)
            temp->key[i]=0;
        temp->key[0]=n;
        for(i=0;i<size;i++)
            temp->pointer[i]=NULL;

    }
    ptr=*root;
    while(ptr!=NULL)
    {
        if(n<ptr->key[0])
        {
            save=ptr;
            ptr=pointer[0];
        }
        else if(n<ptr->key[1])
        {
            save=ptr;
            ptr=pointer[1];
        }
        else if(n<ptr->key[2])
        {
            save=ptr;
            ptr=pointer[2];
        }
        else if(n<ptr->key[3])
        {
            save=ptr;
            ptr=pointer[3];
        }
        else if(n<ptr->key[4])
        {
            save=ptr;
            ptr=pointer[4];
        }
        else
        {
            save=ptr;
            ptr=pointer[5];
        }

    }

}

