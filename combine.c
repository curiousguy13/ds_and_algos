/*given one array in ascending order and another in descending order
WAP to convert them into third array that is in ascending order
*/

#include<stdio.h>
#define size 50
void disp(int a[size],int);
void bubblesort(int a[size],int);
int main()
{
    int sizea,sizeb,i,j,k;
    int a[size],b[size],array[2*size];
    printf("\nEnter the no. of elements of first array:");
    scanf("%d",&sizea);
    printf("\nEnter the elements of first array in ascending order:");
    for(i=0;i<sizea;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the no. of elements in second array:");
    scanf("%d",&sizeb);
    printf("\nEnter the elements of second array in descending order:");
    for(i=0;i<sizeb;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0,j=(sizeb-1),k=0;i<sizea && j>=0;k++)
    {
        if(a[i]<b[j])
        {
            array[k]=a[i];
            i++;
        }
        else
        {
            array[k]=b[j];
            j--;
        }
    }
    if(i<sizea)
    {
        while(i<sizea)
        {
            array[k]=a[i];
            i++;
            k++;
        }
    }
    else
    {
        while(j>=0)
        {
            array[k]=b[j];
            k++;
            j--;
        }
    }
    printf("\nThe resulting combined array is:");
    disp(array,sizea+sizeb);
    return 0;
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
