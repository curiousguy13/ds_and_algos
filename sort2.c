/*KUNAL ARORA
737/IT/12
//WAP to implement selection, bubble and insertion sort & also compare their execution times
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define size 20000
//#include<dos.h>

void insertion_sort(int*,int);
void  disp(int*,int);
void bubblesort(int*,int);
void selection(int*,int);
int main()
{
    int A[size],i,n,choice;
    printf("\n--------SORTING---------");
    do
    {
        printf("\n1.Bubble sort");
        printf("\n2.Selection sort");
        printf("\n3.Insertion sort");
        printf("\n4.Compare the time of diff. sorts");
        printf("\n5.Exit");
        printf("\nEnter your choice(1/2/3/4/5)");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the size of the array:");
                scanf("%d",&n);
                printf("Enter the elements of the array:");
                for(i=0;i<n;i++)
                {
                    scanf("%d",&A[i]);
                }
                bubblesort(A,n);
                printf("\nThe sorted array is:");
                disp(A,n);
                break;
            case 2:
                printf("Enter the size of the array:");
                scanf("%d",&n);
                printf("Enter the elements of the array:");
                for(i=0;i<n;i++)
                {
                    scanf("%d",&A[i]);
                }
                selection(A,n);
                printf("\nThe sorted array is:");
                disp(A,n);
                break;
            case 3:
                printf("Enter the size of the array:");
                scanf("%d",&n);
                printf("Enter the elements of the array:");
                for(i=0;i<n;i++)
                {
                    scanf("%d",&A[i]);
                }
                insertion_sort(A,n);
                printf("\nThe sorted array is:");
                disp(A,n);
                break;
            case 4:
                printf("\nEnter the size of an array(between 1000-20000 for noticeable time change)");
                scanf("%d",&n);
                clock_t start,end;
                double time_taken;
                //
                start=clock();
                bubblesort(A,n);
                end=clock();
                time_taken=(double)(end-start)/CLOCKS_PER_SEC;
                printf("\nTime taken by bubble sort to sort %d integers-->%f\n",n,time_taken);
                //
                start=clock();
                selection(A,n);
                end=clock();
                time_taken=(double)(end-start)/CLOCKS_PER_SEC;
                printf("\nTime taken by selection sort to sort %d integers-->%f\n",n,time_taken);
                //
                start=clock();
                insertion_sort(A,n);
                end=clock();
                time_taken=(double)(end-start)/CLOCKS_PER_SEC;
                printf("\nTime taken by insertion sort to sort %d integers-->%f\n",n,time_taken);
                break;
            case 5:
                return 0;
                break;
        }
    }while(choice!='5');
    return 0;
}
void bubblesort(int *a,int n)
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
void selection(int *a, int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        int index_of_min = i;
        for(j=i; j<n; j++)
        {
            if(a[j]<a[index_of_min])
            {
                index_of_min = j;
            }
        }
        int temp = a[i];
        a[i] = a[index_of_min];
        a[index_of_min] = temp;
    }
    return;
}

void insertion_sort(int *A,int n)
{
    int sorted,counter,temp,i;
    for(sorted=1;sorted<n;sorted++)
    {
        temp=A[sorted];
        for(counter=0;counter<sorted;counter++)
        {
            if(A[sorted]<A[counter])
            {
                for(i=sorted;i!=counter;i--)
                {
                    A[i]=A[i-1];
                }
                A[counter]=temp;
            }
        }
    }
}
void disp(int *A,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}

