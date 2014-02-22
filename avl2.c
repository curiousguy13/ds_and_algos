#include<stdio.h>

typedef struct node
{
    struct node* par;
    int data;
    struct node* left;
    struct node* right;
    int height;
}node;

node* getnode(int n)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->par=NULL;
    temp->left=NULL;
    temp->right=NULL;
    temp->data=n;
    return temp;
}
void insert_tree(node **root,int n)
{
    node* temp=getnode(n);
    node* ptr=*root;
    node* save=NULL;
    if(root==NULL)
    {
        *root=temp;
    }
    else
    {
        while(ptr!=NULL)
        {
            if(n<ptr->data)
            {
                save= ptr;
                ptr=ptr->left;
            }
            else
            {
                save=ptr;
                ptr=ptr->right;
            }
        }
        if(n<save->data)
        {
            save->left=temp;
            temp->par=save;
        }
        else
        {
            save->right=temp;
            temp->par=save;
        }
    }
    return temp;
}
//balance factor
int getbf(node* node)
{
    int bf=node->left->height-node->right->height;
    return bf;
}
insert_avl(node **root,int n)
{
    node* temp=insert_tree(&*root,int n);
    ptr=temp;
    while(ptr)
}
int main()
{

}

