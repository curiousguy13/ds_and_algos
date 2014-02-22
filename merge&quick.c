#include<stdio.h>
void qst(int *A,int low,int high);
int partition(int *A,int low,int high);
void display(int *x,int n);
int main()
{
    int n;
    int A[30];
    printf("\nEnter the no. of elements:");
    scanf("%d",&n);
    qst(A,0,n-1);
    display(A,n);
    return 0;
}
int partition(int *A,int low,int high)
{
    int pivot=A[low];
    int pivot_index=low;
    for(i=low+1;i<(high-low);i++)
    {
        if(A[i]>pivot)
        {
            continue;
        }
        else
        {
            int temp=A[pivot_index];
            A[pivot_index]=A[i];
            A[i]=temp;
            pivot_index=i;
        }
    }
    return pivot_index;
}
void qst(int *A,int low,int high)
{
    if(l>=r)
        return;
    else
    {
        qst(A,low,partition(A,low,high)-1);
        qst(A,partition(A,low,high)+1,high);
    }
    return;
}

void display(int *x,int n)
{
    int j=0;
     while(j<n)
     {
        printf("%d\n",x[j++]);
     }
}
