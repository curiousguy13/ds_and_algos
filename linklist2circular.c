//link list implementation
//function created-check for output & debug(if any error)(i think it's fine though!)
//top is the header in the circular header link list.
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
void link2circular();
int main()
{
    int ans,item;
    do
    {


    printf("\n**********link list**************");
    printf("\n1.Insert");
    printf("\n2.Delete");
    printf("\n3.Display");
    printf("\n4.Convert to circular");
    printf("\n5.EXIT");
    printf("\nEnter your choice(1/2/3/4/5)");
    scanf("%d",&ans);
    switch(ans)
    {
        case 1:
            printf("\nEnter the element you want to insert:");
            scanf("%d",&item);
            insert(item);
            break;
        case 2:
            printf("\nEnter the element you want to delete:");
            scanf("%d",&item);
            del(item);
            break;
        case 3:
            disp();
            break;
        case 4:
            link2circular();
            break;
        case 5:
            break;
    }
}while(ans!=5);


   // fre();

    return 0;
}

void link2circular()
{
    if(top==NULL)
    {
        printf("\nThe link list is empty\n");
    }
    node* ptr=top;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=top;
    return;
}
void insert(int n)
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
void find(int item)
{
    if(top==NULL)
    {
        loc=NULL;
        return;
    }
    if(item<top->val)
    {
        loc=NULL;
        return;
    }
    //printf("half");
    node* save=top;
    node* ptr=top->next;
    while(ptr!=NULL)
    {
        if(item<ptr->val)
        {
            loc=save;
        //    if(loc==NULL)
             //   printf("still null");
          //      else
          //  printf("loc=%d",loc->val);
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
      //  printf("NULL");
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
    return;
}
//deletes a particular element
void del(int n)
{
    if(top==NULL)
    {
        printf("Underflow(the list is empty");
        return;
    }
    node* save=NULL;
    node *ptr;
    ptr=top;
    //save=top;
    while(ptr!=NULL)
    {
        if(ptr->val==n)
        {
            save->next=ptr->next;
            free(ptr);
        }
        else
        {
            save=ptr;
            ptr=ptr->next;
        }
    }
    return;
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
    return;
}

void disp()
{
    temp=top;
    while(temp!=NULL)
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
    return;
}
