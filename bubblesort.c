//bubble sort
#include<stdio.h>
#define size 50
void disp(int a[size],int);
void bubblesort(int a[size],int);
int main()
{
    int n,i;
    int a[size];
    printf("\nEnter te no. of elements:");
    scanf("%d",&n);
    printf("\nenter the elemnts of array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    disp(a,n);
    printf("\n");
    bubblesort(a,n);
    disp(a,n);
    return 0;

}
void bubblesort(int a[size],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<(n-1);j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    return;

}

void disp(int a[size],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return;
}
