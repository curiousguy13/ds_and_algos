//original --seg fault
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int val;
    struct node* next;
}node;
void push(float);
float pop();
void disp();
void fre();

node *top=NULL,*temp=NULL;
int main()
{
    char post_expr[80];
    int i,x,y;
    float ans;
    printf("Enter a postfix expression:");
    gets(post_expr);
    printf("\n--1--\n");
    //post_expr[strlen(post_expr)]=')';   //sentinnel
    for(i=0;post_expr[i]!='\0';i++)
    {
        char ch;
        printf("\n--2--\n");
        //if(post_expr[i]=='+'|| post_expr[i]=='-'||post_expr[i]=='*'||post_expr[i]=='/'||post_expr[i]=='^')
        //{
            //x=pop();
           // y=pop();
           ch=post_expr[i];
           if(ch='0' && ch<='9')
           {
               push(ch-48);
           }
           else
           {
               x=pop();
               y=pop();



            switch(ch)
            {
                case '+':
                  //  printf("\n--3--\n");
                    push(x+y);
                    break;
                case '-':
//                    printf("\n--4--\n");

                    push(x-y);
                    break;
                case '*':
  //               printf("\n--5--\n");

                    push(x*y);
                    break;
                case '/':
    //                printf("\n--6--\n");

                    push(x/y);
                    break;
               // case '^':
                   // printf("\n--7--\n");
                  //  x=pop();
                   // y=pop();

                 //   break;
      //          case ')':
        //            printf("\n--8--\n");
         //           x=pop();
          //          printf("The result of evaluated expression is: %d",x);
           //         break;
                //default:
                 //   push(post_expr[i]-'0');


            }
        //}
    }
    }
    ans=pop();
    printf("%f",ans);
    return 0;
}
void push(float n)
{
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Memory could not be allocated successfully");
    }
    temp->val=n;
    if(top==NULL)
    {
        top=temp;
        top->next=NULL;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}
float pop()
{
    int k;
    if(top==NULL)
    {
        printf("The stack is empty");
        return 0;
    }
    temp=top;
    k=top->val;
    top=top->next;
    free(temp);
    return k;
}

void fre()
{
    temp=top;
    while(temp!=NULL)
    {
        temp=temp->next;
        free(top);
        top=temp;
    }
}

void disp()
{
    temp=top;
    while(temp!=NULL)
    {
        printf("%d",temp->val);
        temp=temp->next;
    }
}

