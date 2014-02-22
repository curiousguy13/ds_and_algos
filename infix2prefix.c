//debug
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


struct stack
{
    char arr[50];
    int tos;
};
void push2(struct stack *,char);
char pop2(struct stack *);
void convert(char[],char[]);
int isopnd(char);
int prcd(char,char);
int isempty(struct stack*);




int main ( )
{
    char prefix[80],infix[80];



    printf( " \n Enter valid infix expression  " );
    scanf("%s", infix);

    convert(infix,prefix);
    printf("\nThe prefix expression is: %s\n",prefix);
    return 0;
}

void convert(char infix[50],char prefix[50])
{
    char temp[50],out[50];
    int i,j;
    struct stack *st=(struct stack*)malloc(sizeof(struct stack));
    (*st).tos=-1;
    //reverse the infix expression
    for(i=strlen(infix)-1,j=0;i>=0;i--,j++)
    {
        temp[j]=infix[i];
    }
    temp[j]='\0';

    printf("\nThe temp expression is: %s\n",temp);
    for(i=0,j=0;temp[i]!='\0';i++)
    {
        /*if temp[i] is an operand write it to out[j]
        if it is an operator(op) and stack is empty, push it onto stack and if stack is not empty , pop from stack
        and compare the popped element and operator(op) precedence .if the precedence of popped operator is
        greater than that of the operator(op) write popped opearator into out[j] otherwise push operator(op)
        onto the stack. repeat the process
        */
        if(isopnd(temp[i]))
        {
            out[j]=temp[i];
            j++;
        }
        else if(temp[i]==')')
        {
            push2(st,temp[i]);
        }
        else if(temp[i]=='(')
        {
            char k=pop2(st);
            while(k!=')')
            {
                out[j]=k;
                j++;
                k=pop2(st);
            }
            pop2(st);
        }
        else
        {
            char op1;
            int flag=0;
            while(1)
            {
            op1=temp[i];
            if(isempty((st)))
            {
                push2(st,op1);
                flag=1;
                break;
            }
            else
            {
                char op2=pop2(st);

                if(prcd(op1,op2)||op2=='(')   //prcd op1>op2
                {
                    push2(st,op2);

                    break;
                }
                else
                {
                    out[j]=op2;
                    j++;
                }
            }
            }

        if(flag==0)
            push2(st,op1);
        }

    }
    while(!isempty(st))
    {
        printf("in");
        out[j]=pop2(st);
        j++;
    }
    out[j]='\0';
    //printf("\nThe output expression is: %s\n",out);
    //reverse the output string
    for(i=strlen(out)-1,j=0;i>=0;i--,j++)
    {
        prefix[j]=out[i];
    }
    prefix[j]='\0';
    return;


}

int isempty(struct stack *s)
{
    if((*s).tos==-1)
        return 1;
    else
        return 0;
}

int isopnd(char ch)
{
    if(ch>='0' && ch<='9')
        return 1;
    else
        return 0;
}

//return 1 if precedence of op1 is greater than or equal to precedence of op2
int prcd(char op1, char op2)
{
    if(op1=='^')
        return 1;
    else if ( op2=='^')
        return 0;
    else if(op1=='/'|| op1=='*')
        return 1;
    else if(op2=='/' || op2=='*')
        return 0;
    else
        return 1;

}

void push2 ( struct stack *p , char x)
{
    if ( p -> tos == 49)
    {
        printf( "stack overflow");
        return ;
    }
    p -> arr[ ++ p -> tos ] = x;
}



char pop2 ( struct stack *p)
{
    char n ;
    if ( p -> tos == -1)
    {
        printf( " stack under flow");
        return -1 ;
    }
    n= p-> arr [ p-> tos --] ;
    return (n);
}
