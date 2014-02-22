#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#define size 50
using namespace std;
typedef struct node
{
    char alpha;
    int freq;
    struct node* left;
    struct node* right;
}node;
struct characters
{
    char alpha;
    char code[30];
}ch[50];
int count=0;
void insheap(node* tree[size],int *n,node* item);
node* delheap(node* tree[size],int *n);
void heapsort(node* a[size],int n);
void disp(node* a[size],int n);
node* huff(node* a[size],int n);
void inorderdisp(node* root);
void assigncode(node* root,int aux[],int top);
/*int main()
{
    node* array[size];
    char ch,ans='y';
    int i=1,fr;
    do
    {
        printf("\nEnter a node:\n");
        printf("\nEnter the alphabet:");
        scanf("%c",&ch);
        printf("\nEnter its frequency:");
        scanf("%d",&fr);
        node* temp=malloc(sizeof(node));
        temp->alpha=ch;
        temp->freq=fr;
        array[i]=temp;
        printf("\nDo you want to enter more?(y/n)");
        scanf("%d",&ans);
        i++;
    }while(ans=='y');
    heapsort(array,i);
    disp(array,i);
    return 0;
}*/

int main()
{
    int n,i,top=0;
    int aux[50];
    node* array[size];
    printf("\nEnter the no. of elements:");
    //scanf("%d",&n);
    //printf("\nEnter the elements of the array:");


    char alphabets[]={'a','b','c','d','e','f'};
    int freq[]={5,9,12,13,16,45};
    n=sizeof(freq)/sizeof(freq[0]);
    for(i=1;i<=n;i++)
    {
        node* temp=(node*)malloc(sizeof(node));
        temp->left=NULL;
        temp->right=NULL;
        temp->alpha=alphabets[i-1];
        temp->freq=freq[i-1];
        array[i]=temp;
    }

    node* root=huff(array,n);
    printf("\nthe huffman tree is:");
    inorderdisp(root);
    assigncode(root,aux,top);
    /*for(i=0;i<count;i++)
    {
        printf("\n%c -- %s",ch[i].alpha,ch[i].code);
    }*/
    return 0;
}


void insheap(node* tree[size],int *n,node* item)
{
    *n=*n+1;
    int ptr=*n,par;
    while(ptr>1)
    {
        par=ptr/2;
        if(item->freq>=tree[par]->freq)
        {
            tree[ptr]=item;
            return;
        }
        tree[ptr]=tree[par];
        ptr=par;
    }
    tree[1]=item;
    return;
}
node* delheap(node* tree[size],int *n)
{
    node* last;
    int ptr,left,right;
    node* item=tree[1];
    last=tree[*n];
    *n=*n-1;
    ptr=1;
    left=2;
    right=3;
    while(right<=*n+1)
    {
        if(last->freq <= tree[left]->freq && last->freq <=tree[right]->freq)
        {
            tree[ptr]=last;
            return item;
        }
        if(tree[right]->freq >= tree[left]->freq)
        {
            tree[ptr]=tree[left];
            ptr=left;
        }
        else
        {
            tree[ptr]=tree[right];
            ptr=right;
        }
        left=2*ptr;
        right=left+1;
    }
    if(left==*n && last->freq > tree[left]->freq)
    {
        ptr=left;
    }
    tree[ptr]=last;
    return item;
}
/*
void heapsort(node* a[size],int n)
{
    int j;
    node* item;
    for(j=1;j<n;j++)
    {
        insheap(a,j,a[j+1]);
    }
    printf("\nthe array after insertion is:");
    disp(a,n);

    while(n>1)
    {
        item=delheap(a,&n);
        a[n+1]=item;
    }
    return;
}
*/
node* huff(node* a[size],int n)
{
    int j;
    node *item1,*item2,*item3;
    for(j=1;j<n;j++)
    {
        insheap(a,&j,a[j+1]);
    }
    while(n>1)
    {
        item1=delheap(a,&n);
        item2=delheap(a,&n);
        item3=(node*)malloc(sizeof(node));
        item3->freq=item1->freq+item2->freq;
        if(item1->freq<item2->freq)
        {
            item3->left=item1;
            item3->right=item2;
        }
        else
        {
            item3->left=item2;
            item3->right=item1;
        }
        insheap(a,&n,item3);
    }
    return a[1];

}

void assigncode(node* root,int aux[],int top)
{
    int i;
    if(root!=NULL)
    {
        if(root->left)
        {
            //printf("left");
            aux[top]=0;
            assigncode(root->left,aux,top+1);
        }
        if(root->right)
        {
            //printf("right");
            aux[top]=1;
            assigncode(root->right,aux,top+1);
        }
        if(root->left==NULL && root->right==NULL)
        {

            //printf("in");

            printf("\n%c:",root->alpha);
            for(i=0;i<top;i++)
            {
                printf("%d",aux[i]);
            }
        }
    }
}
void inorderdisp(node* root)
{
    if(root!=NULL)
    {
        inorderdisp(root->left);
        printf("%d  ",root->freq);
        inorderdisp(root->right);
    }
}
void disp(node* a[size],int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("\n%c : %d",a[i]->alpha,a[i]->freq);
    }
    return;
}
