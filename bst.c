
//write inorder using stack
//display in tree form
#include<stdio.h>
#include<stdlib.h>
//tree node
typedef struct node
{
    int val;
    struct node* leftchild;
    struct node* rightchild;
} node;
//tree functions
void insert_tree(int);
void inorder_disp(node*);
void find(int,node**,node**);
void delete1(node*,node*);
void delete2(node*,node*);
void del(int);
void print_tree();
//tree globals
node* root=NULL;
node* temp=NULL;
//stack node
typedef struct node_s
{
    node* val;
    struct node_s* next;
}node_s;
//stack globals
node_s *top=NULL,*temp=NULL;
//stack funcs
void push_s(int);
int pop_s();

//main
int main()
{
    int n,ans;
    do
    {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit\n");
        scanf("%d",&ans);
        switch(ans)
        {
        case 1:
            printf("\nEnter the value to be inserted:");
            scanf("%d",&n);
            insert_tree(n);
            break;
        case 2:
            printf("Enter the item to be deleted-->");
            scanf("%d",&n);
            del(n);
            break;
        case 3:

            if(root==NULL)
            {
                printf("the tree is empty!!");
            }
            else
                inorder_disp(root);
            break;
        case 4:
            break;
        }

    }
    while(ans!=4);
    return 0;
}
//stack functions
void push_s(node* n)
{
    temp=(node_s*)malloc(sizeof(node_s));
    if(temp==NULL)
    {
        printf("Memory could not be allocated successfully");
    }
    temp->val=n;
    if(top==NULL)
    {
        top=temp;
        top->next=NULL;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}
node* pop_s()
{
    node* k;
    if(top==NULL)
    {
        printf("The stack is empty");
        return 0;
    }
    temp=top;
    k=top->val;
    top=top->next;
    free(temp);
    return k;
}

//tree functions
void insert_tree(int n)
{
    node *ptr=NULL,*save=NULL;
    temp=(node*)malloc(sizeof(node));
    temp->leftchild=NULL;
    temp->rightchild=NULL;
    temp->val=n;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        ptr=root;
        while(ptr!=NULL)
        {
            if(n<(ptr->val))
            {
                save=ptr;
                ptr=ptr->leftchild;
            }
            else
            {
                save=ptr;
                ptr=ptr->rightchild;
            }

        }
        if(n<save->val)
        {
            save->leftchild=temp;
        }
        else
        {
            save->rightchild=temp;
        }
    }
    return;
}

void inorder_disp(node* root)
{
    if(root
       !=NULL)

    {
        inorder_disp(root->leftchild);
        printf("%d ",root->val);
        inorder_disp(root->rightchild);
    }
    /* if(t->leftchild!=NULL)
     {
         inorder(t->leftchild);
     }
     else
     {
         printf("%d",t->val);
     }
     */
    return;
}

//find item from the tree
void find(int n,node** loc1,node** par1)
{
    //printf("1");

    node* ptr=NULL;
    node* save=NULL;
    if(root==NULL)
    {
        //  printf("2");
        *loc1=NULL;
        *par1=NULL;
        return;
    }
    if(root->val==n)
    {
        //printf("3");
        *loc1=root;
        *par1=NULL;
        return;
    }
    //ptr and save initializations
    if(n<root->val)
    {
        //printf("4");
        ptr=root->leftchild;
        save=root;
    }
    else
    {
        //printf("5");
        ptr=root->rightchild;
        save=root;
    }
    while(ptr!=NULL)
    {

        if(n<(ptr->val))
        {
            //   printf("6");
            save=ptr;
            ptr=ptr->leftchild;
        }
        else if(n>(ptr->val))
        {
            // printf("7");
            save=ptr;
            ptr=ptr->rightchild;
        }
        else if(n==(ptr->val))
        {
            // printf("8");
    //        printf("\nfound\n");
            *loc1=ptr;
            *par1=save;
            return;
        }
    }
    //printf("9");
    *loc1=NULL;
    *par1=save;
    return;
}
//deletion when there is only one or no children
void delete1(node* loc,node* par)
{
    node* child=NULL;

    if(loc->leftchild==NULL && loc->rightchild==NULL)
    {
        child=NULL;
    }
    else if(loc->leftchild==NULL)
    {
        child=loc->rightchild;
    }
    else
    {
        child=loc->leftchild;
    }
    if(par!=NULL)
    {
        if(loc==par->leftchild)
        {
            par->leftchild=child;
        }
        else
        {
            par->rightchild=child;
        }
    }
    else
    {
        root=child;
    }
    return;
}
//deletion when there are 2 children
void delete2(node* loc,node* par)
{
    //find the successor and parent of successor
    node *suc=NULL,*parsuc=NULL;
    node *ptr=NULL,*save=NULL;
    ptr=loc->rightchild;
    save=loc;
    while(ptr->leftchild!=NULL)
    {
        save=ptr;
        ptr=ptr->leftchild;
    }
    suc=ptr;
    parsuc=save;

    //delete inorder successor
    delete1(suc,parsuc);

    //replace node N by its inorder successor
    if(par!=NULL)
    {
        if(loc==par->leftchild)
        {
            par->leftchild=suc;
        }
        else
        {
            par->rightchild=suc;
        }

    }
    else
    {
        root=suc;
    }
    suc->leftchild=loc->leftchild;
    suc->rightchild=loc->rightchild;
    return;
}

void del(int n)
{
    node* loc=NULL;
    node* par=NULL;
    find(n,&loc,&par);
    if(loc==NULL)
    {
        printf("Item not in tree!!");
        return;
    }
    if(loc->leftchild!=NULL && loc->rightchild!=NULL)
    {
        delete2(loc,par);
    }
    else
    {
        delete1(loc,par);
    }
    /*if(par==NULL && loc!=NULL && loc->leftchild==NULL && loc->rightchild==NULL)
    {
        root=NULL;
    }*/
    printf("\nItem deleted successfully\n");
    free(loc);
    return;
}
