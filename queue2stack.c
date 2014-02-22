//stack implementation using 2 queues
#include<stdio.h>
#include<stdlib.h>
typedef struct node_q
{
    int val;
    struct node_q* next;
}node_q;
void pushq(node_q**,int);
int popq(node_q**);
void dispq(node_q**);
void freeq(node_q*);
void pushstack(node_q**,node_q**,int);


int main()
{
    node_q *top_q1=NULL,*top_q2=NULL;
    int n,k,item;
    do
    {
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nEnter the option(1/2/3/4):");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("\nEnter the element you want to push into the stack ");
            scanf("%d",&item);
            pushstack(&top_q1,&top_q2,item);
            break;
        case 2:
            k=popq(&top_q1);
            if(k!=0)
                printf("\nThe element %d has been popped",k);
            break;
        case 3:
            printf("\nThe current stack is:");
            dispq(&top_q1);
            break;
        case 4:
            break;
        }

    }
    while(n!=4);
    freeq(top_q1);
    freeq(top_q2);
    return 0;
}
void pushstack(node_q **q1,node_q **q2,int n)
{
    int k;
    pushq((&(*q2)),n);
    node_q* ptr=(*q1);
    printf("\nthe queue q1 is:");
    dispq(q1);
    printf("\nthe queue q1 is:");
    dispq(q2);
    while(ptr!=NULL)
    {
        k=popq(&ptr);
        printf("\nthe element %d is being popped out of q1 and pushed into q2\n",k);
        pushq((&(*q2)),k);
        //ptr=ptr->next;
        printf("\nendofloop");

    }

    printf("\nexchanging q1 and q2\n");
    ptr=*q2;
    *q2=*q1;
    *q1=ptr;

    return;
}
void pushq(node_q **top_q,int n)
{
    node_q* temp_q=(node_q*)malloc(sizeof(node_q));
    if(temp_q==NULL)
    {
        printf("Memory could not be allocated successfully");
    }
    temp_q->val=n;
    temp_q->next=NULL;
    if(*top_q==NULL)
    {
        *top_q=temp_q;

    }
    else
    {
        node_q* ptr=*top_q;

        while(ptr->next!=NULL)
        {

            ptr=ptr->next;
        }
        temp_q->next=NULL;
        ptr->next=temp_q;
    }
    return;
}
int popq(node_q **top_q)
{
    int k;
    if((*top_q)==NULL)
    {
        printf("The queue is empty");
        return 0;
    }

    node_q* temp_q=(*top_q);
    k=(*top_q)->val;
    (*top_q)=(*top_q)->next;
    free(temp_q);

    return k;
}

void freeq(node_q* top_q)
{
    node_q* temp_q=top_q;
    while(temp_q!=NULL)
    {
        temp_q=temp_q->next;
        free(top_q);
        top_q=temp_q;
    }
    return;
}

void dispq(node_q** top_q)
{
    node_q* temp_q=*top_q;
    while(temp_q!=NULL)
    {
        printf("%d",temp_q->val);
        temp_q=temp_q->next;
    }
    return;
}

