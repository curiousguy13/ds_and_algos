/*KUNAL ARORA
737/IT/12
Program-To implement a Binary search tree and display it in tree form
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* A binary tree node has val, pointer to left child
   and a pointer to right child */
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int height;
} node;
struct node* newNode(int val)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
//stack node
typedef struct node_s
{
    node* val;
    struct node* next;
} node_s;
//stack functions
//void push_s(int);
//int pop_s();
//stack globals
node *top_s=NULL,*temp_s=NULL;
node* stack[50];
int top=0;
void insert_tree(node **root,int n)
{
    node *ptr=NULL,*save=NULL;
    node* temp=(node*)malloc(sizeof(node));
    temp->left=NULL;
    temp->right=NULL;
    temp->val=n;
    // temp->height=0;
    if(*root==NULL)
    {
        *root=temp;
        // root->offset=20;
    }
    else
    {
        ptr=*root;
        while(ptr!=NULL)
        {
            if(n<(ptr->val))
            {
                save=ptr;
                ptr=ptr->left;
            }
            else
            {
                save=ptr;
                ptr=ptr->right;
            }
        }
        if(n<save->val)
        {
            save->left=temp;
        }
        else
        {
            save->right=temp;
        }
    }
    return;
}

/*void print_tree(node* root)
{
    int tree_arr[50];
    int tree_depth[50];
    int tree_offset[50];

    node* ptr=root;
    int max_depth=0;
    max_depth=maxDepth(root);
    int i=0,j=0;
    ptr->depth=0;
    ptr->offset=pow(max_depth,2);
    int count=0;
    do
    {
        if(ptr!=NULL)
        {
            tree_arr[i]=ptr->val;
            tree_depth[i]=ptr->depth;
            tree_offset[i]=ptr->offset;
            count++;
            i++;
        }
        if(ptr->left!=NULL)
        {
            ptr->left->depth=ptr->depth+1;
            ptr->left->offset=ptr->offset-pow(max_depth-ptr->left->depth,2);
            pushq(ptr->left);
        }

        if(ptr->right!=NULL)
        {
            ptr->right->depth=ptr->depth+1;
            ptr->right->offset=ptr->offset+pow(max_depth-ptr->right->depth,2);

            pushq(ptr->right);
        }

        ptr=popq();
    }
    while(ptr!=NULL);
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
*/
//find item from the tree
void find(node **root,int n,node** loc1,node** par1)
{
    //printf("1");

    node* ptr=NULL;
    node* save=NULL;
    if(*root==NULL)
    {
        //  printf("2");
        *loc1=NULL;
        *par1=NULL;
        return;
    }
    if((*root)->val==n)
    {
        //printf("3");
        *loc1=*root;
        *par1=NULL;
        return;
    }
    //ptr and save initializations
    if(n<(*root)->val)
    {
        //printf("4");
        ptr=(*root)->left;
        save=*root;
    }
    else
    {
        //printf("5");
        ptr=(*root)->right;
        save=*root;
    }
    while(ptr!=NULL)
    {

        if(n<(ptr->val))
        {
            //   printf("6");
            save=ptr;
            ptr=ptr->left;
        }
        else if(n>(ptr->val))
        {
            // printf("7");
            save=ptr;
            ptr=ptr->right;
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
void delete1(node **root,node* loc,node* par)
{
    node* child=NULL;

    if(loc->left==NULL && loc->right==NULL)
    {
        child=NULL;
    }
    else if(loc->left==NULL)
    {
        child=loc->right;
    }
    else
    {
        child=loc->left;
    }
    if(par!=NULL)
    {
        if(loc==par->left)
        {
            par->left=child;
        }
        else
        {
            par->right=child;
        }
    }
    else
    {
        *root=child;
    }
    return;
}
//deletion when there are 2 children
void delete2(node **root,node* loc,node* par)
{
    //find the successor and parent of successor
    node *suc=NULL,*parsuc=NULL;
    node *ptr=NULL,*save=NULL;
    ptr=loc->right;
    save=loc;
    while(ptr->left!=NULL)
    {
        save=ptr;
        ptr=ptr->left;
    }
    suc=ptr;
    parsuc=save;

    //delete inorder successor
    delete1(&*root,suc,parsuc);

    //replace node N by its inorder successor
    if(par!=NULL)
    {
        if(loc==par->left)
        {
            par->left=suc;
        }
        else
        {
            par->right=suc;
        }

    }
    else
    {
        *root=suc;
    }
    suc->left=loc->left;
    suc->right=loc->right;
    return;
}

void del(node **root,int n)
{
    node* loc=NULL;
    node* par=NULL;
    find(&*root,n,&loc,&par);
    if(loc==NULL)
    {
        printf("Item not in tree!!");
        return;
    }
    if(loc->left!=NULL && loc->right!=NULL)
    {
        delete2(&*root,loc,par);
    }
    else
    {
        delete1(&*root,loc,par);
    }
    printf("\nItem deleted successfully\n");
    free(loc);
    return;
}
void printGivenLevel( node *root, int level, int n)    // for printing nodes
{
                                                        // of given level
    int i;
    if(root == NULL)
    {
        printf(" ");
        for( i=1; i<=n; i++)
            printf("   ");
        return;
    }
    if(level == 1)
    {
        printf("%d", root->val);
        for( i=1; i<=n; i++)
            printf("   ");
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1, n );
        printGivenLevel(root->right, level-1, n );
    }
}

int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
void display( node* root)       // for level order display
{
    int i,j,t,h;
    h = height(root);
    t= 4*h;
    for(i=1; i<=h; i++)
    {
        for(j= t/2 ; j>=1; j--)
            printf("   ");
        printGivenLevel(root, i, t);
        t/=2;
        printf("\n\n");
    }
}

void inorder(node* root)
{
    top=0;
    stack[top]=NULL;
    node* ptr=root;
label:
    while(ptr!=NULL)
    {
        stack[++top]=ptr;
        ptr=ptr->left;

    }
    ptr=stack[top];
    top--;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->val);
        if(ptr->right!=NULL)
        {
            ptr=ptr->right;
            goto label;

        }
        ptr=stack[top--];
    }
}

int main()
{
    int n,ans;
    node* root=NULL;
    do
    {
        printf("\n----------BST------------");
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
            insert_tree(&root,n);
            break;
        case 2:
            printf("Enter the item to be deleted-->");
            scanf("%d",&n);
            del(&root,n);
            break;
        case 3:
            printf("\nPreorder traversal:");
            inorder(root);
            printf("\nTree:\n");
            display(root);

            break;
        case 4:
            break;
        }

    }
    while(ans!=4);
    return 0;
}
