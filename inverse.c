/*KUNAL ARORA
737/IT/12
PROGRAM-->to calculate inverse of an N*N matrix
*/
#include<stdio.h>
#include<math.h>
#define size 25
float determinant(float a[size][size],int);
float minor(float a[size][size],int n,int x,int y);
void cofactor(float a[size][size],int n);
void transpose(float a[size][size],int n);
int main()
{
    int n,i,j;
    float arr[size][size],det;
    printf("*********INVERSE OF A MATRIX*********\n");
    printf("KUNAL ARORA-737/IT/12\n");
    printf("Enter the order of the matrix-->");
    scanf("%d",&n);
    //input the matrix
    printf("\nEnter the elements of the matrix\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%f",&arr[i][j]);
        }
    }
    det=determinant(arr,n);
    printf("\nThe determinant is:%f",det);
    if(det==0)
    {
        printf("\nThe inverse of this matrix is not possible as determinant=0\n");
    }
    else
    {
        cofactor(arr,n);
        transpose(arr,n);
        printf("\nThe inverse of the entered matrix is:\n");
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                printf("%.2f ",arr[i][j]/det);
            }
            printf("\n");
        }
    }
    return 0;
}

//function to calculate determinant
float determinant(float a[size][size],int n)
{
    float b[size][size],det;
    int p=0,q=0,c=0,s=1,i=0,j=0;

    if(n==1)
    {

        det=a[0][0];
        return det;

    }
    else
    {
        det=0;
        for(c=0; c<n; c++)
        {
            p=0;
            q=0;
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                {
                    if(i!=0 && j!=c)
                    {
                        b[p][q]=a[i][j];
                        if (q<(n-2))
                            q++;
                        else
                        {
                            q=0;
                            p++;
                        }
                    }
                }
            }

            det=det+s*a[0][c]*determinant(b,n-1);
            s=s*(-1);
        }
    }
    return det;
}
//to calculate the minor of a given element of matrix
float minor(float a[size][size],int n,int x,int y)
{
    float b[size][size],min;
    int p=0,q=0,s=1,i=0,j=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i!=x && j!=y)
            {
                b[p][q]=a[i][j];
                if (q<(n-2))
                    q++;
                else
                {

                    q=0;
                    p++;
                }
            }
        }
    }
    min=determinant(b,n-1);
    return min;
}

//to calculate the cofactor matrix
void cofactor(float a[size][size],int n)
{
    float cof[size][size];
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cof[i][j]=pow(-1 , i + j) * minor(a,n,i,j);

        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            a[i][j]=cof[i][j];
        }
    }
    return;
}
//to calculate the tranxpose of matrix
void transpose(float a[size][size],int n)
{
    float b[size][size];
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            b[i][j]=a[j][i];
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            a[i][j]=b[i][j];
        }
    }
    return;
}
