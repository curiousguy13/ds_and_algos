//quick and merge sort
//programming lab
#include<stdio.h>
#include<stdlib.h>
#define size 50
void qst(int *A,int low,int high);
int partition(int *A,int low,int high);
void display(int *x,int n);
void merge_sort(int *A,int low,int high);
void merge(int arr[],int min,int max,int mid);
int main()
{
    int n,i,ans;
    int A[size];
    printf("\nEnter the no. of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements of array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\n1.quicksort");
    printf("\n2.mergesort");
    printf("\nEnter the choice(1/2):");
    scanf("%d",&ans);
    if(ans==1)
    {
        qst(A,0,n-1);
        printf("\nThe elements of array after quicksort are:");
        display(A,n);
    }
    else
    {
        merge_sort(A,0,n-1);
        printf("\nThe elements of array after mergesort are:");
        display(A,n);
    }
    return 0;
}
int partition(int *A,int low,int high)
{
    int pivot=A[low];
    int i;
    int pivot_index=low;
    for(i=low+1;i<=(high-low);i++)
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
    if(low>=high)
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
        printf("%d  ",x[j++]);
     }
}

void merge_sort(int A[],int low,int high)
{
    int mid=(low+high)/2;
    if(low>=high)
    {
        return;
    }
    merge_sort(A,low,mid);
    merge_sort(A,mid+1,high);
    merge(A,low,high,mid);

}

void merge(int arr[],int min,int max,int mid)
{
  int tmp[size];
  int i,j,k,m;
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(arr[j]<=arr[m])
     {
         tmp[i]=arr[j];
         j++;
     }
     else
     {
         tmp[i]=arr[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=arr[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=arr[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     arr[k]=tmp[k];
}
