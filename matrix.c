/*KUNAL ARORA
737/IT/12
PROGRAM-->insertion and deletion in an array
*/
#include<stdio.h>

void sum();
void multiply();

int a[20][20],b[20][20],c[20][20];
int i,j,k,ch,n;

void main()
{
    printf("****MATRIX OPERATIONS****");
    printf("\nKunal arora 737/IT/12\n");

    printf("Enter the size of the matrix-->");
    scanf("%d",&n);
    printf("\nEnter first matrix:\n");

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);


    printf("\nEnter second matrix:\n");

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&b[i][j]);

    sum();

    multiply();

}

//sum function
void sum()
{
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            c[i][j]=a[i][j]+b[i][j];


    printf("\nAfter addition:-\n");

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf(" %d",c[i][j]);
        printf("\n");
    }



}

//multiplication function
void multiply()
{
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            c[i][j]=0;


    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            for(k=0; k<n; k++)
                c[i][j]+=a[i][k]*b[k][j];


    printf("\nAfter multiplication:-\n");

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf(" %d",c[i][j]);
        printf("\n");
    }


}

