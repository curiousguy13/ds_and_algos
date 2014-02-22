//done :)
//test case-->4-2+(3*6)/9-4
#include<stdio.h>
#include<stdlib.h>
#define size 50
//tree node
typedef struct node
{
    char val;
    struct node* leftchild;
    struct node* rightchild;
}node;

//stack structure
struct stack
{
    char arr[size];
    int top;
};
//stack funcs
void push(struct stack*,char);
char pop(struct stack*);
void display(struct stack*);
//stack2 structure
struct stack2
{
    node* arr[size];
    int top;
};
//other funcs
void convert(char[],char[]);
int isopnd(char);
int prcd(char,char);
int isempty(struct stack);
node* expr_tree(char postfix[size]);
void inorder_disp(node* root);
//main
int main ( )
{
    char postfix[80],infix[80];
    //float result ;


    printf( " \n Enter valid infix expression  " );
    scanf("%s", infix);

    convert(infix,postfix);
    printf("\nThe postfix expression is: %s\n",postfix);

    inorder_disp(expr_tree(postfix));
    return 0;
}
void push(struct stack* s,char n)
{
    if(s->top==(size-1))
    {
        printf("Overflow");
    }
    else
    {
        s->top++;
        s->arr[s->top]=n;
    }
    return;
}
char pop(struct stack* s)
{
    char popped_element;
    if(s->top==-1)
    {
        printf("Underflow");
    }
    else
    {
        popped_element=s->arr[s->top];
        s->top--;
    }
    return popped_element;
}

void display(struct stack* s)
{
    int i;
    printf("\nThe current stack is-->");
    for(i=0; i<=s->top; i++)
    {
        printf("%c ",s->arr[i]);
    }
}
//stack 2 functions
void push2(struct stack2* s,node* n)
{
    if(s->top==(size-1))
    {
        printf("Overflow");
    }
    else
    {
        s->top++;
        s->arr[s->top]=n;
    }
    return;
}
node* pop2(struct stack2* s)
{
    node* popped_element;
    if(s->top==-1)
    {
        printf("Underflow");
    }
    else
    {
        popped_element=s->arr[s->top];
        s->top--;
    }
    return popped_element;
}

//functions to convert infix to postfix
void convert(char infix[50],char postfix[50])
{
    int i,j=0;
    char ch,op;
    struct stack s;
    s.top=-1;
    for(i=0; infix[i]!='\0'; i++)
    {
        display(&s);
        ch=infix[i];
        if(isopnd(ch)==1)
        {
            postfix[j]=ch;
            j++;
        }
        else if(ch=='(')
        {
            push(&s,ch);
        }
        else if(ch==')')
        {
            char k=pop(&s);
            while(k!='(')
            {
                postfix[j]=k;
                j++;
                k=pop(&s);
            }
            //pop(&s);
        }
        else
        {
            while(!isempty(s))
            {
                //result=prcd(ch,s.arr[s.top]);
                if(prcd(s.arr[s.top],ch)||ch=='(')
                    break;
                op=pop(&s);
                postfix[j]=op;
                j++;
            }
            push(&s,ch);
        }
    }
    while(!isempty(s))
    {
        op=pop(&s);
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

//expression tree formation
node* expr_tree(char postfix[size])
{
    struct stack2 st;
    int i;
    node* temp=NULL,*op1=NULL,*op2=NULL;
    for(i=0;postfix[i]!='\0';i++)
    {
        char ch=postfix[i];
        if(isopnd(ch))
        {
            temp=(node*)malloc(sizeof(node));
            temp->leftchild=NULL;
            temp->rightchild=NULL;
            temp->val=ch;
            push2(&st,temp);

        }
        else
        {
            op1=pop2(&st);
            op2=pop2(&st);
            temp=(node*)malloc(sizeof(node));
            temp->leftchild=op2;
            temp->rightchild=op1;
            temp->val=ch;
            push2(&st,temp);
        }
    }
    node* root=pop2(&st);
    return root;
}
void inorder_disp(node* root)
{
    if(root!=NULL)

    {
        inorder_disp(root->leftchild);
        printf("%c",root->val);
        inorder_disp(root->rightchild);
    }

    return;
}
