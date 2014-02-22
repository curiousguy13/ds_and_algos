/*
KUNAL ARORA
IT-1
737/IT/12
Program-To implement stack using array
*/
#include<stdio.h>

const int size=20;
void push(int*,int);
int pop(int*);
void display(int*);
int top=-1;
int main()
{
    int A[size],n,ans;
    int another=1;
    while(another==1)
    {
    printf("What do you want to do?\n");
    printf("1)PUSH\n");
    printf("2)POP\n");

    scanf("%d",&ans);


    switch(ans)
    {
        case 1:
            printf("\nEnter the element you want to push int the array-->");
            scanf("%d",&n);
            push(A,n);
            display(A);
            break;
        case 2:
            n=pop(A);
            printf("\nThe popped element is-->%d\n",n);
            display(A);
            break;
        default:
            printf("Invalid choice");
            break;
    }
    printf("\nDo you want to enter another choice?(1 for yes /2 for no)");

    scanf("%d",&another);
    }
    return 0;
}
void push(int *A,int n)
{
    if(top==(size-1))
    {
        printf("Overflow");
    }
    else
    {
        top++;
        A[top]=n;
    }
}
int pop(int *A)
{
    int popped_element=0;
    if(top==-1)
    {
        printf("Underflow");
    }
    else
    {
        popped_element=A[top];
        top--;
    }
    return popped_element;
}

void display(int *A)
{
    int i;
    printf("The current stack is:-->");
    for(i=0;i<=top;i++)
    {
        printf("%d ",A[i]);
    }
}
