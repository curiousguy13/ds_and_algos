/*Kunal Arora
737/IT/12
Program-B-tree implementation
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 4
#define MIN 2

typedef struct btnode
{
    int value[MAX+1];
    int count;
    struct btnode* child[MAX+1];
}btnode;

struct btnode * insert ( int, struct btnode * ) ;
int setval ( int, struct btnode *, int *, struct btnode ** ) ;
struct btnode * search ( int, struct btnode *, int * ) ;
int searchnode ( int, struct btnode *, int * ) ;
void fillnode ( int, struct btnode *, struct btnode *, int ) ;
void split ( int, struct btnode *, struct btnode *,
                int, int *, struct btnode ** ) ;
struct btnode * delete ( int, struct btnode * ) ;
int delhelp ( int, struct btnode * ) ;
void clear ( struct btnode *, int ) ;
void copysucc ( struct btnode *, int ) ;
void restore ( struct btnode *, int ) ;
void rightshift ( struct btnode *, int ) ;
void leftshift ( struct btnode *, int ) ;
void merge ( struct btnode *, int ) ;
void display ( struct btnode * ) ;
/*
int main()
{
    btnode* root;
    root=NULL;

    root=insert(27,root);
    root=insert(42,root);
    root=insert(22,root);
    root=insert(47,root);
    root=insert(32,root);
    root=insert(2,root);
    root=insert(51,root);

    printf ( "B-tree of order 5:\n" ) ;
    display ( root ) ;

    root = delete ( 22, root ) ;
    root = delete ( 11, root ) ;

    printf ( "\n\nAfter deletion of values:\n" ) ;
    display ( root ) ;
    return 0;
}
*/
int main()
{
    int n,ans;
    btnode* root=NULL;
    do
    {
        printf("\n---------B-tree------------");
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit\n");
        scanf("%d",&ans);
        switch(ans)
        {
        case 1:
            printf("\nEnter the value to be inserted:");
            scanf("%d",&n);
            root=insert(n,root);
            break;
        case 2:
            printf("Enter the item to be deleted-->");
            scanf("%d",&n);
            root = delete(n,root);
            break;
        case 3:
            printf("\nB-tree of order 5 is:\n");
            display(root);
            break;
        case 4:
            break;
        }

    }
    while(ans!=4);
    return 0;
}
//insert in the node
btnode* insert(int val,btnode* root)
{
    int i;
    btnode *new_child,*node;
    int flag;
    flag=setval(val,root,&i,&new_child);
    //when root==NULL, flag will be 1 and we will create a new node
    if(flag)
    {
        node=(btnode*)malloc(sizeof(btnode));
        node->count=1;
        node->value[1]=i;
        node->child[0]=root;
        node->child[1]=new_child;
        return node;
    }
    //when root is not NULL and flag is 0 it will return the root
    return root;

}
//sets the value in the node
int setval(int val,btnode* node,int *new_value,btnode **new_child)
{
    int pos;
    if(node==NULL)
    {
        *new_value=val;
        *new_child=NULL;
        return 1;
    }
    else
    {
        if(searchnode(val,node,&pos))
            printf("\nkey value already exists\n");
        if(setval(val,node->child[pos],new_value,new_child))
        {
            if(node->count<MAX)
            {
                fillnode(*new_value,*new_child,node,pos);
            }
            else
            {
                split(*new_value,*new_child,node,pos,new_value,new_child);
                return 1;
            }
            return 0;
        }

    }
}
//searches for the node
btnode* search(int val,btnode* root,int *pos)
{
    if(root==NULL)
        return NULL;
    else
    {
        //if we find the value in the given root node , it will return that node
        //note that the root node will change depending on the level of recursion
        if(searchnode(val,root,pos))
            return root;
            //else it would search in the child just before the value that is greater than val
        else
        {
            return search(val,root->child[*pos],pos);
        }
    }
}
//searches value in the node and cahnges the pos to the first value greater than val
/* searches for the node */
int searchnode ( int val, struct btnode *n, int *pos )
{
    if ( val < n -> value [1] )
    {
        *pos = 0 ;
        return 0 ;
    }
    else
    {
        *pos = n -> count ;
        while ( ( val < n -> value [*pos] ) && *pos > 1 )
            ( *pos )-- ;
        if ( val == n -> value [*pos] )
            return 1 ;
        else return 0 ;
    }
}/*inserts the value val at the right place in the node*/
void fillnode(int val,btnode* child,btnode *node,int pos)
{
    int i;
    for(i=node->count;i>pos;i--)  //shift the values to the right of pos
    {
        node->value[i+1]=node->value[i];
        node->child[i+1]=node->child[i];
    }
    node->value[pos+1]=val;
    node->child[pos+1]=child;
    node->count++;
}
//splits the node
void split(int val,btnode* new_child,btnode* node,int pos,int *new_value,btnode **newnode)
{
    int i,mid;
    //MIN=2
    if(pos<=MIN)
        mid=MIN;
    else
        mid=MIN+1;

    *newnode=(struct btnode*)malloc(sizeof(struct btnode));
    for(i=mid+1;i<=MAX;i++)
    {
        (*newnode)->value[i-mid]=node->value[i];
        (*newnode)->child[i-mid]=node->child[i];
    }
    (*newnode)->count=MAX-mid;
    node->count=mid;
    if(pos<=MIN)
        fillnode(val,new_child,node,pos);
    else
            fillnode(val,new_child,*newnode,pos-mid);
    *new_value=node->value[node->count];
    (*newnode)->child[0]=node->child[node->count];
    node->count--;

}

/* displays the B-tree */
void display ( struct btnode *root )
{
    int i ;

    if ( root != NULL )
    {
        for ( i = 0 ; i < root -> count ; i++ )
        {
            display ( root -> child [i] ) ;
            printf ( "%d\t", root -> value [i + 1] ) ;
        }
        display ( root -> child [i] ) ;
    }
}


/* deletes value from the node */
struct btnode * delete ( int val, struct btnode *root )
{
    struct btnode * temp ;
    if ( ! delhelp ( val, root ) )
        printf ( "\nValue %d not found.", val ) ;
    else
    {
        if ( root -> count == 0 )
        {
            temp = root ;
            root = root -> child [0] ;
            free ( temp ) ;
        }
    }
    return root ;
}

/* helper function for delete( ) */
int delhelp ( int val, struct btnode *root )
{
    int i ;
    int flag ;
    if ( root == NULL )
        return 0 ;
    else
    {
        flag = searchnode ( val, root, &i ) ;
        if ( flag )
        {
            if ( root -> child [i - 1] )
            {
                copysucc ( root, i ) ;
                flag = delhelp ( root -> value [i], root -> child [i] ) ;
                if ( !flag )
                    printf ( "\nValue %d not found.", val ) ;
            }
            else
                clear ( root, i ) ;
        }
        else
            flag = delhelp ( val, root -> child [i] ) ;

        if ( root -> child [i] != NULL )
        {
            if ( root -> child [i] -> count < MIN )
                restore ( root, i ) ;
        }
        return flag ;
    }
}

/* removes the value from the node and adjusts the values */
void clear ( struct btnode *node, int k )
{
    int i ;
    for ( i = k + 1 ; i <= node -> count ; i++ )
    {
        node -> value [i - 1] = node -> value [i] ;
        node -> child [i - 1] = node -> child [i] ;
    }
    node -> count-- ;
}

/* copies the successor of the value that is to be deleted */
void copysucc ( struct btnode *node, int i )
{
    struct btnode *temp ;

    temp = node -> child [i] ;

    while ( temp -> child[0] )
        temp = temp -> child [0] ;

    node -> value [i] = temp -> value [1] ;
}

/* adjusts the node */
void restore ( struct btnode *node, int i )
{
    if ( i == 0 )
    {
        if ( node -> child [1] -> count > MIN )
            leftshift ( node, 1 ) ;
        else
            merge ( node, 1 ) ;
    }
    else
    {
        if ( i == node -> count )
        {
            if ( node -> child [i - 1] -> count > MIN )
                rightshift ( node, i ) ;
            else
                merge ( node, i ) ;
        }
        else
        {
            if ( node -> child [i - 1] -> count > MIN )
                rightshift ( node, i ) ;
            else
            {
                if ( node -> child [i + 1] -> count > MIN )
                    leftshift ( node, i + 1 ) ;
                else
                    merge ( node, i ) ;
            }
        }
    }
}

/* adjusts the values and children while shifting the value from parent to right
    child */
void rightshift ( struct btnode *node, int k )
{
    int i ;
    struct btnode *temp ;

    temp = node -> child [k] ;

    for ( i = temp -> count ; i > 0 ; i-- )
    {
        temp -> value [i + 1] = temp -> value [i] ;
        temp -> child [i + 1] = temp -> child [i] ;
    }

    temp -> child [1] = temp -> child [0] ;
    temp -> count++ ;
    temp -> value [1] = node -> value [k] ;

    temp = node -> child [k - 1] ;
    node -> value [k] = temp -> value [temp -> count] ;
    node -> child [k] -> child [0] = temp -> child [temp -> count] ;
    temp -> count-- ;
}

/* adjusts the values and children while shifting the value from parent to left
    child */
void leftshift ( struct btnode *node, int k )
{
    int i ;
    struct btnode *temp ;

    temp = node -> child [k - 1] ;
    temp -> count++ ;
    temp -> value [temp -> count] = node -> value [k] ;
    temp -> child [temp -> count] = node -> child [k] -> child [0] ;

    temp = node -> child [k] ;
    node -> value [k] = temp -> value [1] ;
    temp -> child [0] = temp -> child [1] ;
    temp -> count-- ;

    for ( i = 1 ; i <= temp -> count ; i++ )
    {
        temp -> value [i] = temp -> value [i + 1] ;
        temp -> child [i] = temp -> child [i + 1] ;
    }
}

/* merges two nodes */
void merge ( struct btnode *node, int k )
{
    int i ;
    struct btnode *temp1, *temp2 ;


    temp1 = node -> child [k] ;
    temp2 = node -> child [k - 1] ;
    temp2 -> count++ ;

    temp2 -> value [temp2 -> count] = node -> value [k] ;
    temp2 -> child [temp2 -> count] = temp1-> child [0] ;

    for ( i = 1 ; i <= temp1 -> count ; i++ )
    {
        temp2 -> count++ ;
        temp2 -> value [temp2 -> count] = temp1 -> value [i] ;
        temp2 -> child [temp2 -> count] = temp1 -> child [i] ;
    }

    for ( i = k ; i < node -> count ; i++ )
    {
        node -> value [i] = node -> value [i + 1] ;
        node -> child [i] = node -> child [i + 1] ;
    }

    node -> count-- ;

    free ( temp1 ) ;
}

