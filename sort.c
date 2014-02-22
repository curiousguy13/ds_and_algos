//insertion sort
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//#include<dos.h>

void insertion_sort(int*,int);
void  disp(int*,int);
int main()
{
    clock_t start,end;
    long long j;
    double time_taken;
    int A[10000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    start=clock();
    insertion_sort(A,5000);
    end=clock();
    //disp(A,5000);

    time_taken=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nexec tim-->%f\n",time_taken);
    return 0;
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
        printf("\n%d\n",A[i]);
    }
}
