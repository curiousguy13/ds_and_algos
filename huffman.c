#include<stdio.h>

#include<stdlib.h>
#define size 50
typedef struct node
{
    char alpha;
    int freq;
}node;

void insheap(node* tree[size],int n,node* item);
node* delheap(node* tree[size],int *n);
void heapsort(node* a[size],int n);
void disp(node* a[size],int n);

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
    int n,i,fr;
    char ch;
    node* array[size];
    printf("\nEnter the no. of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements of the array:");
    for(i=1;i<=n;i++)
    {
        node* temp=malloc(sizeof(node));
        printf("\nEnter the alphabet:");
        scanf("%d",&temp->alpha);
        printf("\nEnter its frequency:");
        scanf("%d",&temp->freq);
        array[i]=temp;
    }
    heapsort(array,n);
    printf("\nthe sorted array is:");
    disp(array,n);
    return 0;
}


void insheap(node* tree[size],int n,node* item)
{
    n=n+1;
    int ptr=n,par;
    while(ptr>1)
    {
        par=ptr/2;
        if(item->freq<=tree[par]->freq)
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
        if(last->freq >= tree[left]->freq && last->freq >=tree[right]->freq)
        {
            tree[ptr]=last;
            return item;
        }
        if(tree[right]->freq <= tree[left]->freq)
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
    if(left==*n && last->freq < tree[left]->freq)
    {
        ptr=left;
    }
    tree[ptr]=last;
    return item;
}

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

void disp(node* a[size],int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("\n%c : %d",a[i]->alpha,a[i]->freq);
    }
    return;
}
