/*Kunal arora
737/IT/12
Program- insertion,deletion and traversal in a directed graph
*/
#include<stdio.h>
#include<stdlib.h>
//queue struct
typedef struct node_q
{
    struct node* val;
    struct node_q* next;
}node_q;

typedef struct listnode
{
    struct node* link;
    struct listnode* next;
}listnode;
typedef struct node
{
    char data;
    int status;
    struct listnode* adj;
    struct node* next;
}node;
//queue functions
void enqueue(node_q **top_q,node* n)
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
node* dequeue(node_q **top_q)
{
    node* k;
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

//graph functions
void findnode(node* start,char item,node** loc)
{
    if(start==NULL)
    {
        printf("\nNo nodes in the graph");
        return;
    }
    node* ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->data==item)
        {
            *loc=ptr;
            return;
        }
        else
        {
            ptr=ptr->next;
        }
    }
}

void findedge(node* start,char A,char B,listnode** edgeloc)
{
    if(start==NULL)
    {
        printf("\nNo nodes in the graph");
        return;
    }
    node* locA=NULL;
    findnode(start,A,&locA);
    node* locB=NULL;
    findnode(start,B,&locB);
    if(locA==NULL || locB==NULL)
    {
        printf("\nEdge not found!!!");
        *edgeloc=NULL;
        return;
    }
    listnode* ptr=locA->adj;
    while(ptr!=NULL)
    {
        if(ptr->link==locB)
        {
            *edgeloc=ptr;
            return;
        }
        else
        {
            ptr=ptr->next;
        }
    }
    printf("\nEdge not found!!!");
}
void getnode(char data,node** temp)
{
    (*temp)=(node*)malloc(sizeof(node));
    (*temp)->data=data;
    (*temp)->adj=NULL;
    (*temp)->next=NULL;
}
void getlistnode(node* link,listnode** temp)
{
    (*temp)=(listnode*)malloc(sizeof(listnode));
    (*temp)->link=link;
    (*temp)->next=NULL;
}

void insertnode(node **start,char data)
{
    node* temp=NULL;
    getnode(data,&temp);
//   printf("\n%c",temp->data);
    if(*start==NULL)
    {
        *start=temp;
        return;
    }
    else
    {
        node* ptr=*start;
        node* save=NULL;
        while(ptr!=NULL)
        {
            save =ptr;
            ptr=ptr->next;
        }
        save->next=temp;
        return;
    }
}

void insertedge(node* start,char A,char B)
{
    if(start==NULL)
    {
        printf("\nNo nodes in the graph");
        return;
    }
    node* locA=NULL;
    findnode(start,A,&locA);
    node* locB=NULL;
    findnode(start,B,&locB);
    if(locA==NULL || locB==NULL)
    {
        printf("\nNodes not present in graph!!!");
        return;
    }
    listnode* temp=NULL;
    getlistnode(locB,&temp);
    temp->next=locA->adj;
    locA->adj=temp;
}
void delete_edge(node* start,char A, char B)
{
    if(start==NULL)
    {
        printf("\nNo nodes in the graph!!\n");
        return ;
    }
    if(start==NULL)
    {
        printf("\nNo nodes in the graph");
        return;
    }
    node* locA=NULL;
    findnode(start,A,&locA);
    node* locB=NULL;
    findnode(start,B,&locB);
    if(locA==NULL || locB==NULL)
    {
        printf("\nNodes not present in graph!!!");
        return;
    }
    listnode* ptr=locA->adj;
    listnode* save=ptr;

    while(ptr!=NULL)
    {
        if(ptr->link==locB)
        {
            if(ptr==locA->adj)
                locA->adj=ptr->next;
            else
                save->next=ptr->next;
            free(ptr);
            return;
        }
        save=ptr;
        ptr=ptr->next;
    }
}
void delete_node(node **start, char A)
{
    if(*start==NULL)
    {
        printf("\nNo nodes in the graph!!\n");
        return ;
    }
    node *ptr1=*start;
    //checking if the node is in the graoh or not
    node* locA=NULL;
    findnode(*start,A,&locA);
    if(locA==NULL)
    {
        printf("\nThe entered node is not in the graph\n");
        return ;
    }
    listnode *ptr2=ptr1->adj;
    listnode* save2=ptr2;
    //deleting all the incoming edges
    while(ptr1!=NULL)
    {
        if(ptr1->data!=A)
        {
            while(ptr2!=NULL)
            {
                if(ptr2->link->data==A)
                {
                    if(ptr2==ptr1->adj)
                        ptr1->adj=ptr2->next;
                    else
                        save2->next=ptr2->next;
                }
                save2=ptr2;
                ptr2=ptr2->next;
            }
        }

        ptr1=ptr1->next;
    }
    //deleting all outgoing edges


    listnode* ptr=locA->adj;
    listnode* save=ptr;
    while(ptr!=NULL)
    {
        save=ptr;
        ptr=ptr->next;
        free(save);
    }
    //if starting node is to be deleted
    if((*start)->data==A)
    {
        *start=(*start)->next;
    }
    //delete the node
    free(locA);
}

void bfs_disp(node* start)
{
    //initialise status of all node as 1 i.e ready
    if(start==NULL)
    {
        printf("\nNo nodes in the graph!!\n");
        return ;
    }
    node* ptr1=start;
    while(ptr1!=NULL)
    {
        ptr1->status=1;
        ptr1=ptr1->next;
    }
    node_q *top_q=NULL;
    ptr1=start;
    //printf("%c",ptr1->data);
    enqueue(&top_q,ptr1);
    //printf("%c",ptr1->data);
    ptr1->status=2;//waiting
    while(top_q!=NULL)
    {
        ptr1=dequeue(&top_q);
        printf("\n%c",ptr1->data);
       // printf("!");
        ptr1->status=3; //processed
        listnode* ptr2=ptr1->adj;
        while(ptr2!=NULL)
        {
            if(ptr2->link->status==1)
            {
                enqueue(&top_q,ptr2->link);
                ptr2->link->status=2;//waiting
            }
            ptr2=ptr2->next;
        }

    }
}
int main()
{
    int n,ans,a,b;
    node* start=NULL;
    do
    {
        printf("\n---------Directed Graph------------");
        printf("\n1.Insertnode");
        printf("\n2.Insertedge");
        printf("\n3.Deletenode");
        printf("\n4.Deleteedge");
        printf("\n5.Display-nodes");
        printf("\n6.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&ans);
        fflush(stdin);
        switch(ans)
        {
        case 1:
            printf("\nEnter the value to be inserted:");
            fflush(stdin);
            scanf("%c",&n);
            fflush(stdin);
            insertnode(&start,n);
            break;
        case 2:
            printf("\nEnter the start point of edge:");
            fflush(stdin);
            scanf("%c",&a);
            fflush(stdin);
            printf("\nEnter the end point of edge:");
            scanf("%c",&b);
            fflush(stdin);
            insertedge(start,a,b);
            break;

        case 3:
            printf("Enter the value to be deleted-->");
            fflush(stdin);
            scanf("%c",&n);
            fflush(stdin);
            delete_node(&start,n);
            break;
        case 4:
            printf("\nEnter the start point of edge:");
            fflush(stdin);
            scanf("%c",&a);
            fflush(stdin);
            printf("\nEnter the end point of edge:");
            scanf("%c",&b);
            fflush(stdin);
            delete_edge(start,a,b);
            break;
        case 5:
            printf("\nDisplaying node of the graph using breadth first traversal: \n");
            bfs_disp(start);
            break;
        case 6:
            break;
        }

    }
    while(ans!=6);
    return 0;
}

