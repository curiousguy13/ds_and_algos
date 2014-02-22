//2-5 B-tree
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
#define MIN 2
typedef struct Btreenode
{
    int key[MAX];
    int t; //indegree
    int nok; //no. of keys currently
    struct Btreenode *child[MAX+1];

    bool leaf;
} Btreenode;
Btreenode* getnode(int k,int t,bool val)
{
    Btreenode* temp=(Btreenode*)malloc(sizeof(Btreenode));
    temp->key[0]=k;
    temp->nok=1;
    temp->t=t
    temp->child[0]=NULL;
    temp->child[1]=NULL;
    leaf=val;
    return temp;
}

void traverse(Btreenode* root)
{
    int i;
    Btreenode* ptr=root;
    for(i=0;i<nok;i++)
    {
        if(!isleaf(ptr))
            traverse(ptr->child[i]);
        printf("  %d",ptr->keys[i]);
    }
    if(!isleaf(ptr))
        traverse(ptr->child[i]);
}

Btreenode* search_btree(Btreenode* root,int k)
{
    int i=0;
    Btreenode* ptr=root;
    while(i<ptr->nok && k>ptr->keys[i])
        i++;

    if(ptr->keys[i]==k)
        return ptr;

    if (isleaf(ptr))
        return NULL;

    return search_btree(ptr->child[i]);
}
void insert_node(Btreenode **root,int k)
{
    if(*root==NULL)
    {
        *root=getnode(k,t,true);
    }
    else
    {
        if((*root)->n==2*
    }
}
bool isleaf(Btreenode* n)
{
    if(n->leaf==true)
    {
        return true;
    }
    else
    {
        return false
    }
}
/*void insert_node(Btreenode* root,int k)
{
    Btreenode* temp=NULL;
    if(root==NULL)
    {
        temp=getnode(k,true);
    }
    else
    {
        Btreenode* ptr=root;
        if(isleaf(ptr))
        {
            for(i=0; i<ptr->nok; i++)
            {
                if(k<ptr->key[i])
                {
                    for(j=nok; j>i; j--)
                    {
                        ptr->key[j]=ptr->key[j-1];
                    }
                    ptr->key[i]=k;
                    nok++;
                    break;
                }
                else if(k>ptr->key[ptr->nok])
                {
                    ptr->key[nok]=k;
                    nok++;
                    break;
                }

            }
        }
        else
        {
            for(i=0;i<ptr->nok;i++)
            {
                if(k<ptr->key[i])
                {
                    ptr=ptr->pointer[i];
                    break;
                }
                else if(k>ptr->key[ptr->nok])
                {

                }
            }
        }



    }
*/
