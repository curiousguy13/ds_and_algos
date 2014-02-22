/*KUNAL ARORA
737/IT/12
Program-To implement heapsort using a binary heap
*/
#include<stdio.h>
#define size 50
void insheap(int tree[size],int n,int item);
int delheap(int tree[size],int *n);
void heapsort(int a[size],int n);
void disp(int a[size],int n);
int main()
{
    int n,a[size],i;
    printf("\n----------HEAPSORT----------");
    printf("\nEnter the no. of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements of the array:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    printf("\nthe sorted array is:");
    disp(a,n);
    return 0;
}

void insheap(int tree[size],int n,int item)
{
    n=n+1;
    int ptr=n,par;
    while(ptr>1)
    {
        par=ptr/2;
        if(item<=tree[par])
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
int delheap(int tree[size],int *n)
{
    int last,ptr,left,right;
    int item=tree[1];
    last=tree[*n];
    *n=*n-1;
    ptr=1;
    left=2;
    right=3;
    while(right<=*n+1)
    {
        if(last>=tree[left] && last>=tree[right])
        {
            tree[ptr]=last;
            return item;
        }
        if(tree[right]<=tree[left])
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
    if(left==*n && last<tree[left])
    {
        ptr=left;
    }
    tree[ptr]=last;
    return item;
}

void heapsort(int a[size],int n)
{
    int j;
    int item;
    for(j=1;j<n;j++)
    {
        insheap(a,j,a[j+1]);
    }
    printf("\nthe array after insertion is:");
    disp(a,n);
    int temp=n;
    while(n>1)
    {
        item=delheap(a,&n);
        a[n+1]=item;
    }
    return;
}

void disp(int a[size],int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    return;
}
