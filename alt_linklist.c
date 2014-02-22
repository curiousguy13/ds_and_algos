//alternating link list implementation
//done-8/10/13
#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    int roll_no;
   // struct employee* next;
}student;
typedef struct employee
{
    int salary;
   // struct student* next;
}employee;
typedef struct node
{
    union
    {
        student s;
        employee e;
    }u;
    struct node* next;

}node;
node *top=NULL,*loc=NULL;


void disp();
void fre();
void insertstu();
void insertemp();
void deltop();
int main()
{
    int ans;
    do
    {


    printf("\n**********link list**************");
    printf("\n1.Insert");
    printf("\n2.Delete");
    printf("\n3.Display");
    //printf("\n4.Convert to circular");
    printf("\n4.EXIT");
    printf("\nEnter your choice(1/2/3/4/5)");
    scanf("%d",&ans);
    switch(ans)
    {
        case 1:
            //printf("\nEnter the element you want to insert:");
            //scanf("%d",&item);
            insertstu();
            insertemp();
            break;
        case 2:
            //printf("\nEnter the element you want to delete:");
            //scanf("%d",&item);
            deltop();
            deltop();
            printf("\nTop 2 elements deleted successfully");
            break;
        case 3:
            disp();
            break;
        case 4:
           // link2circular();
            break;

    }
}while(ans!=4);


   // fre();

    return 0;
}

void insertstu()
{
    int n;
    node *temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Memory could not be allocated successfully");
    }
    printf("\nEnter the roll_no of student");
    scanf("%d",&n);
    temp->u.s.roll_no=n;
    temp->next=NULL;
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
    return;
}
void insertemp()
{
    int n;
    node *temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Memory could not be allocated successfully");
    }
    printf("\nEnter the salary of employee");
    scanf("%d",&n);
    temp->u.e.salary=n;
    temp->next=NULL;
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
    return;
}
void deltop()
{
    if(top==NULL)
    {
        printf("Underflow(the list is empty");
        return;
    }
    else
    {
        node* temp=top;
        top=top->next;
        free(temp);

    }
    return;
}
void fre()
{
    node* temp=top;
    while(temp!=NULL)
    {
        temp=temp->next;
        free(top);
        top=temp;
    }
}

void disp()
{
    node* temp=top;
    while(temp!=NULL)
    {
        printf("\nsalary-->%d",temp->u.e.salary);
        if(temp->next!=NULL)
        {
            temp=temp->next;
 //           printf("\n");
        }
        else
            break;

        printf("\nroll_no-->%d",temp->u.s.roll_no);
        if(temp->next!=NULL)
        {
            temp=temp->next;
            printf("\n");
        }
        else
            break;
    }
    return;
}
