/*Kunal arora
737/it/12
program-to find if the two entered trees are mirror images of each other or  not
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
    struct node* par;
} node;

node* getnode(int n)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->left=NULL;
    temp->right=NULL;
    temp->key=n;
    temp->par=NULL;
    return temp;
}
void insert_tree(node **root,int n)
{
    node* temp=getnode(n);
    if(*root==NULL)
    {
        *root=temp;
    }
    else
    {
        node* ptr=*root;
        node* save=NULL;
        while(ptr!=NULL)
        {
            if(n<ptr->key)
            {
                save=ptr;
                ptr=ptr->left;
            }
            else if(n>ptr->key)
            {
                save=ptr;
                ptr=ptr->right;
            }
            else if(n==ptr->key)
            {
                printf("\nElement already in the tree");
                return;
            }
        }

        if(n<save->key)
        {
            save->left=temp;
        }
        else
        {
            save->right=temp;
        }
    }
}
void insert_tree2(node **root,int n,node **loc)
{
    node* temp=getnode(n);
    if(*root==NULL)
    {
        *root=temp;
        (*root)->par=NULL;
        *loc=*root;
        return;
    }
    else
    {
        if((*loc)->left==NULL)
        {
            (*loc)->left=temp;
            (*loc)->left->par=(*loc);

        }
        else
        {
            (*loc)->right=temp;
            (*loc)->right->par=(*loc);
            if((*loc)->par==NULL)
               *loc=(*loc)->left;
            else if(*loc==((*loc)->par)->right)
            {
                *loc=((*loc)->par);
                while((*loc)->left!=NULL)
                {
                    *loc=(*loc)->left;
                }
            }
            else
                *loc=(*loc)->par->right;
        }
        /*
        node* ptr=*root;
        node* save=NULL;
        while(ptr->height!=height_of_tree)
        {
            save=ptr;
            ptr=ptr->left;
            if(ptr->left==NULL)
            {
                break;
            }
        }

        if(insert_tree2(*root->left,n))
        {
            return 1;
        }
        else
            insert_tree2(*root->right,n)
            */
    }

}

void inorder(node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d  ",root->key);
        inorder(root->right);
    }
}

//to check if the two trees are mirror images o each other
int ismirror(node* root1,node* root2)
{
    if(root1==NULL&&root2!=NULL)
    {
        return 0;
    }
    else if(root1!=NULL&&root2==NULL)
    {
        return 0;
    }
    else if(root1==NULL&&root2==NULL)
    {
        return 1;
    }
    if(root1->key!=root2->key)
    {
        return 0;
    }
    if(ismirror(root1->left,root2->right))
    {
        return 1;
    }
    else

        return 0;
    }
    if(ismirror(root1->right,root2->left))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    node* root1=NULL;
    node* root2=NULL;
    node* loc1=NULL;
    node* loc2=NULL;
    int n;
    char ans;
    do
    {
        printf("\nEnter the elements of first tree:");
        scanf("%d",&n);
        insert_tree2(&(root1),n,&loc1);
        printf("do you want to enter more elemnts?(y/n)");
        fflush(stdin);
        scanf("%c",&ans);
        fflush(stdin);
    }
    while(ans!='n');
    printf("\nThe first tree is:");
    inorder(root1);
    do
    {
        printf("\nEnter the elements of second tree:");
        scanf("%d",&n);
        insert_tree2(&root2,n,&loc2);
        printf("do you want to enter more elemnts?(y/n)");
        fflush(stdin);
        scanf("%c",&ans);
        fflush(stdin);
    }
    while(ans!='n');
    printf("\nThe second tree is:");
    inorder(root2);
    if(ismirror(root1,root2))
    {
        printf("\nThe two trees are mirror images of each other");
    }
    else
    {
        printf("\nThey are not mirror images of each other");
    }
    return 0;
}
