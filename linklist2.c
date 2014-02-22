/*KUNAL ARORA
737/IT/12
Program-To insert an element in a sorted linked list
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int val;
    struct node* next;
}node;

node *top=NULL,*temp=NULL,*loc=NULL;
void insert(int);
void find(int);
void insloc(int);
void insert_s(int);
void sorted_insert(int);
void del(int k);
void disp();
void fre();
int main()
{
    int no_of_ele,item;
    printf("Enter the no. of elements you want to add in the list(in a sorted manner)-->");
    scanf("%d",&no_of_ele);
    printf("Enter the elements :\n");
    while(no_of_ele--)
    {
        scanf("%d",&item);
        insert(item);
    }
    printf("The current linked list is:");
    disp();
    printf("\n");
    printf("Enter item to be inserted:");
    scanf("%d",&item);
    insert_s(item);
    printf("The current linked list is:");
    disp();
    //printf("Enter the element you want to delete");
    //scanf("%d",&item);
    //del(item);
    //disp();
    fre();

    return 0;
}

void insert(int n)
{
    temp=malloc(sizeof(node));
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
void find(int item)
{
    if(top==NULL)
    {
        loc=NULL;
        return;
    }
    if(item>top->val)
    {
        loc=NULL;
        return;
    }
    //printf("half");
    node* save=top;
    node* ptr=top->next;
    while(ptr!=NULL)
    {
        if(item>ptr->val)
        {
            loc=save;
            //if(loc==NULL)
                //printf("still null");
              //  else
            //printf("loc=%d",loc->val);
            return;
        }
        save=ptr;
        ptr=ptr->next;
    }
    loc=save;
    return;
}

void insloc(int item)
{
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Memory could not be allocated successfully");
    }
    temp->val=item;
    if(loc==NULL)
    {
        temp->next=top;
        top=temp;
    }
    else
    {
        temp->next=loc->next;
        loc->next=temp;
    }
    return;
}
void insert_s(item)
{
    loc=NULL;
    find(item);
    //if(loc==NULL)
        //printf("NULL");
    insloc(item);
    loc=NULL;
    return;
}
void sorted_insert(int n)
{
    temp=malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Memory could not be allocated successfully");
    }
    temp->val=n;
    node *prev=NULL;
    node *top2=top;
    if(top==NULL)
    {
        printf("Inserting %d",temp->val);
        top=temp;
        top->next=NULL;
    }
    else
    {
        while(top!=NULL)
        {
        if(top->val >= n)
        {
            temp->next=top;
            prev->next=temp;
            top=top2;
            temp=top;
            break;
        }
        else
        {
            prev=top;
            top=top->next;
        }
        }
    }
}
void del(int n)
{
    node* temp2=NULL;
    temp=top;
    temp2=top;
    while(temp!=NULL)
    {
        if(temp->val==n)
        {
            temp2->next=temp->next;
            free(temp);
        }
        else
        {
            temp2=temp;
            temp=temp->next;
        }
    }
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
        printf("%d ",temp->val);
        temp=temp->next;
    }
}
