/*KUNAL ARORA
737/IT/12
Program-To implement an AVL tree
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
}node;

int max(int a, int b);
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}

struct node* newNode(int key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int key)
{

    if (root == NULL)
        return root;
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct node *temp = root->left ? root->left : root->right;

            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp;

            free(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            struct node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void printGivenLevel( node *root, int level, int n)    // for printing nodes
{
                                                        // of given level
    int i;
    if(root == NULL)
    {
        printf(" ");
        for( i=1; i<=n; i++)
            printf("   ");
        return;
    }
    if(level == 1)
    {
        printf("%d", root->key);
        for( i=1; i<=n; i++)
            printf("   ");
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1, n );
        printGivenLevel(root->right, level-1, n );
    }
}

void display( node* root)       // for level order display
{
    int i,j,t,h;
    h = height(root);
    t= 4*h;
    for(i=1; i<=h; i++)
    {
        for(j= t/2 ; j>=1; j--)
            printf("   ");
        printGivenLevel(root, i, t);
        t/=2;
        printf("\n\n");
    }
}

int main()
{
    int n,ans;
    node* root=NULL;
    do
    {
        printf("\n---------AVL tree------------");
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
            root=insert(root,n);
            break;
        case 2:
            printf("Enter the item to be deleted-->");
            scanf("%d",&n);
            root = deleteNode(root, n);
            break;
        case 3:
            //printf("\nPre order traversal: \n");
            display(root);
            break;
        case 4:
            break;
        }

    }
    while(ans!=4);
    return 0;
}
