//linear & binary search
#include<stdio.h>
#define size 50
void disp(int a[size],int);
void bubblesort(int a[size],int);
void linearsearch(int a[size],int n,int item);
void binary(int a[size],int low,int high,int item);
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
    do
    {
        printf("\n1)Linear Search ");
        printf("\n2)Binary search");
        printf("\n3)Exit");
        scanf("%d",&ans);
        switch(ans)
        {
            case 1:
                printf("\nEnter the element to be saerched:");
                scanf("%d",&item);
                int k=linearsearch(a,n,item);
                if(k==-1)
                    printf("\nElement not found!!");
                else
                    printf("\nElement found at location %d",k);
                break;
            case 2:
                printf("\nEnter the element  to be saerched:");
                scanf("%d",&item);
                bubblesort(a,n);
                int k=binary(a,n,item);
                if(k==-1)
                    printf("\nElement not found!!");
                else
                    printf("\nElement found at location %d",k);
                break;
            case 3:
                break;
            default:
                printf("\nInvalid choice!");
                break;
        }
    }while(ans!=3);
    bubblesort(a,n);
    disp(a,n);
    return 0;

}
void linearsearch(int a[size],int n,int item)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            return i+1;
        }
    }
    return -1;
}
void binary(int a[size],int low,int high,int item)
{
    mid=(low+high)/2;
    if(low<=high)
    {
        return -1;
    }
    if(item==a[mid])
    {
        return mid+1;
    }
    else if(item<a[mid])
    {
        binary(a,low,mid-1,item);
    }
    else
    {
        binary(a,mid+1,high,item);
    }

}
void bubblesort(int a[size],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
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
