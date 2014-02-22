/*KUNAL ARORA
737/IT/12
PROGRAM-->insertion sort and selection sort
*/
#include<stdio.h>
#include<stdlib.h>
//#include<dos.h>

void insertion_sort(int*,int);
void selection(int*,int);
void  disp(int*,int);
int main()
{

    int A[10000],n,i,ans;
    printf("Enter the no. of elemnts in array:");
    scanf("%d",&n);
    printf("\nEnter the elements of array:");
    for(i=0; i<n; i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\n1.)Insertion sort");
    printf("\n2.)Selection sort");
    printf("\nEnter your choice:");
    scanf("%d",&ans);
    if(ans==1)
    {
        insertion_sort(A,n);
        disp(A,n);
    }
    else
    {
        selection(A,n);
        disp(A,n);
    }


    return 0;
}
void insertion_sort(int *A,int n)
{
    int sorted,counter,temp,i;
    for(sorted=1; sorted<n; sorted++)
    {
        temp=A[sorted];
        for(counter=0; counter<sorted; counter++)
        {
            if(A[sorted]<A[counter])
            {
                for(i=sorted; i!=counter; i--)
                {
                    A[i]=A[i-1];
                }
                A[counter]=temp;
            }
        }
    }
}
//selection sort
void selection(int *array, int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        int index_of_min = i;
        for(j=i; j<n; j++)
        {
            if(array[j]<array[index_of_min])
            {
                index_of_min = j;
            }
        }
        int temp = array[i];
        array[i] = array[index_of_min];
        array[index_of_min] = temp;
    }
    return;
}
//function to display elements of array
void disp(int *A,int n)
{
    int i;
    printf("\nThe sorted array is:");
    for(i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }
}
