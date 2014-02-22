#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//tree node
typedef struct node
{
    int val;
    struct node* leftchild;
    struct node* rightchild;
    int depth;
    int offset;
} node;
//tree functions
void insert_tree(int);
void inorder_disp(node*);
void find(int,node**,node**);
void delete1(node*,node*);
void delete2(node*,node*);
void del(int);
void print_tree();
void inorder();
//tree globals
node* root=NULL;
node* temp=NULL;
int max_depth=0;
//stack node
typedef struct node_s
{
    node* val;
    struct node* next;
} node_s;
//stack functions
void push_s(int);
int pop_s();
//stack globals
node *top_s=NULL,*temp_s=NULL;
//q node
typedef struct node_q
{
    node* val;
    struct node_q* next;
} node_q;
//q functions
void pushq(node*);
node* popq();
//q globals
node_q *top_q=NULL,*temp_q=NULL;
//main
node* stack[50];
int top=0;
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
            {
                print_tree();
               printf("\ninorder traversal:");
                inorder();


            }
            break;
        case 4:
            break;
        }

    }
    while(ans!=4);
    return 0;
}

//q functions
void pushq(node* n)
{
    temp_q=(node_q*)malloc(sizeof(node_q));
    if(temp_q==NULL)
    {
        printf("Memory could not be allocated successfully");
    }
    temp_q->val=n;
    if(top_q==NULL)
    {
        top_q=temp_q;
        top_q->next=NULL;
    }
    else
    {
        node_q* ptr=top_q;

        while(ptr->next!=NULL)
        {

            ptr=ptr->next;
        }
        temp_q->next=NULL;
        ptr->next=temp_q;
    }
}
node* popq()
{
    node* k;
    if(top_q==NULL)
    {
        //printf("The queue is empty");
        return 0;
    }

    temp_q=top_q;
    k=top_q->val;
    top_q=top_q->next;
    free(temp_q);

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
    temp->depth=0;
    if(root==NULL)
    {
        root=temp;
        // root->offset=20;
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
                (temp->depth)++;
                if(temp->depth>max_depth)
                {
                    max_depth=temp->depth;
                }
            }
            else
            {
                save=ptr;
                ptr=ptr->rightchild;
                (temp->depth)++;
                if(temp->depth>max_depth)
                {
                    max_depth=temp->depth;
                }
            }

        }
        if(n<save->val)
        {
            save->leftchild=temp;
            //   save->leftchild->offset=save->offset-2;
        }
        else
        {
            save->rightchild=temp;
            //    save->rightchild->offset=save->offset+2;
        }
    }
    return;
}

void print_tree()
{
    int tree_arr[50];
    int tree_depth[50];
    int tree_offset[50];

    node* ptr=root;
    //node* temp=NULL;
    //node* save=NULL;
    //int offset;
    int i=0,j=0;
    ptr->offset=pow(max_depth,2)+10;
    int count=0;
    do
    {

        // offset=pow(max_depth-ptr->depth,2);

        // save=ptr;
        if(ptr!=NULL)
        {
            tree_arr[i]=ptr->val;
            tree_depth[i]=ptr->depth;
            tree_offset[i]=ptr->offset;
            count++;
            i++;
        }
        /*if(ptr->leftchild==NULL || ptr->rightchild==NULL)
        {
            tree_arr[i]=-1;
            tree_depth[i]=ptr->depth+1;
            i++;
        }*/
        if(ptr->leftchild!=NULL)
        {
            ptr->leftchild->offset=pow(max_depth-ptr->depth,2);//offset formula not right
            pushq(ptr->leftchild);
        }

        if(ptr->rightchild!=NULL)
        {
            ptr->rightchild->offset=pow(max_depth-ptr->depth,2);
            pushq(ptr->rightchild);
        }

        ptr=popq();
        // if(ptr!=NULL && save!=NULL)
        //{


        // if((ptr->depth)!=(save->depth))
        //{
        //     printf("\n");
        // }
        // }
    }
    while(ptr!=NULL);
    /*
        printf("\narray:");
        for(j=0; j<i; j++)
        {
            printf("%d ",tree_arr[j]);
        }
        printf("\ndepth:");
        for(j=0; j<i; j++)
        {
            printf("%d ",tree_depth[j]);
        }
        printf("\noffset:");
        for(j=0; j<i; j++)
        {
            printf("%d ",tree_offset[j]);
        }
        */
    printf("\n");
    for(j=0; j<count; j++)
    {


        for(i=0; i<tree_offset[j]; i++)
        {
            printf(" ");
        }
        printf("%d",tree_arr[j]);
        if(j==0)
        {
            printf("\n");
        }
        else if(tree_depth[j]==tree_depth[j+1])
        {
            tree_offset[j+1]=tree_offset[j+1]-tree_offset[j];
            continue;
        }
        else
        {
            printf("\n");
        }
    }
    return;

}
void inorder_disp(node* root)
{
    if(root!=NULL)

    {
        inorder_disp(root->leftchild);
        printf("%d",root->val);
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

void inorder()
{
    top=0;
    stack[top]=NULL;
    node* ptr=root;
label:
    while(ptr!=NULL)
    {
        stack[++top]=ptr;
        ptr=ptr->leftchild;

    }
    ptr=stack[top];
    top--;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->val);
        if(ptr->rightchild!=NULL)
        {
            ptr=ptr->rightchild;
            goto label;

        }
        ptr=stack[top--];
    }
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
