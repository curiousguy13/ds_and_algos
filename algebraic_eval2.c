//for unary operators too
//not working correctly
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 80
typedef struct node
{
    int val;
    struct node* next;
} node;

struct stack
{
    struct node* arr[size];
    int top;
};
void push2(struct stack *,int);
float pop2(struct stack *);
void convert(char[],char[]);
int isopnd(char);
int prcd(char,char);
int isempty(struct stack);

node *top=NULL,*temp=NULL;

void push(float);
float pop();

float evaluate (float,float,char );

int main ( )
{
    char postfix[size],infix[size];
    float result ;


    printf( " \n Enter valid infix expression  " );
    scanf("%s", infix);

    convert(infix,postfix);
    printf("\nThe postfix expression is: %s\n",postfix);

    int i ;
    char ch ;
    float op1 ,  op2 , ans , x ;


    for ( i=0 ; postfix[i] !='\0' ; i++ )
    {
        ch = postfix [i] ;
        if ( ch>='0' && ch<='9')
        {
            x= ch-48;
            push (x);
        }
        else
        {
            op2 = pop();
            op1=pop();
            ans = abs(evaluate (op1,op2,ch));
            push(ans);
        }
    }
    result=pop();



    printf("result is = %f" , result);
    return 0;
}
void convert(char infix[size],char postfix[size])
{
    int i,j=0;
    char ch,op;
    struct stack s;
    s.top=-1;
    for(i=0; infix[i]!='\0'; i++)
    {
     //   display(&s);
        ch=infix[i];
        if(isopnd(ch)==1)
        {
            postfix[j]=ch;
            j++;
        }
        else if(ch=='(')
        {
            push2(&s,ch);
        }
        else if(ch==')')
        {
            char k=pop2(&s);
            while(k!='(')
            {
                postfix[j]=k;
                j++;
                k=pop2(&s);
            }
            //pop(&s);
        }
        else if(infix[i]=='+' && infix[i+1]=='+')
        {
            push2(&s,'$');
            i++;
        }
        else
        {
            while(!isempty(s))
            {
                //result=prcd(ch,s.arr[s.top]);
                if(pop2(&s)=='$')
                {
                    postfix[j]='+';
                    j++;
                    postfix[j]='+';
                    j++;
                }
                if(prcd(s.arr[s.top],ch)||ch=='(')
                    break;
                op=pop2(&s);
                postfix[j]=op;
                j++;
            }
            push2(&s,ch);
        }
    }
    while(!isempty(s))
    {
        op=pop2(&s);
        postfix[j]=op;
        j++;
    }
    postfix[j]='\0';
}


int isempty(struct stack s)
{
    if(s.top==-1)
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

int prcd(char out, char in)
{
    if(in=='^')
        return 1;
    else if ( out=='^')
        return 0;
    else if(in=='/'|| in=='*')
        return 1;
    else if(out=='/' || out=='*')
        return 0;
    else
        return 1;

}



float evaluate (float a, float b, char op)
{

    switch(op)
    {
    case '+' :

        return(a+b);

    case'-' :

        return(a-b);

    case'*' :

        return(a*b);

    case'/' :

        return(a/b);

    case '^'   :

        return(pow(a,b));

    }
    return -1;
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
        //printf("The stack is empty");
        return 0;
    }
    temp=top;
    k=top->val;
    top=top->next;
    free(temp);
    return k;
}

void push2 ( struct stack *p , int x)
{
    if ( p -> top == 9)
    {
        printf( "stack overflow");
        return;
    }
    p -> arr[ ++ p -> top ] = x;
}



float pop2 ( struct stack *p)
{
    int n ;
    if ( p -> top == -1)
    {
        printf( " stack under flow");
        return -1 ;
    }
    n= p-> arr [ p-> top --] ;
    return (n);
}
