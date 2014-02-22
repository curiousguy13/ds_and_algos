/*Kunal Arora
737/IT/12
Program->Huffman coding
*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define size 50

//node
typedef struct node
{
    char alpha;
    int freq;
    struct node* left;
    struct node* right;
} node;


void insheap(node* tree[size],int *n,node* item);
node* delheap(node* tree[size],int *n);
void heapsort(node* a[size],int n);
void disp(node* a[size],int n);
node* huff(node* a[size],int n);
void inorderdisp(node* root);
int assigncode(node* root,char aux[],int top,char,FILE*);
int isinarray(char ch,char arr[],int n);
void display_file(FILE* fp);

int main()
{
    int i,top=0;
    char aux[50];
    node* array[size];

    char alphabets[100];
    int freq[100];
    char c;
    int no_of_characters=0;
    //opening the input file
    FILE* fp=fopen("kunal.txt","r+");
    if(fp==NULL)
    {
        printf("File could not be opened succesfully!!");
        return 0;
    }
    puts("\nContents of Input file:");
    display_file(fp);

    rewind(fp); //to get the file pointer back at the top of file

    //read from file character by character and fill the alphabets and frequency arrays
    do
    {
        c=fgetc(fp);

        //if the character(c) is already read before, just increase its frequency
        if(isinarray(c,alphabets,no_of_characters))
        {
            for(i=0; i<no_of_characters; i++)
            {
                if(alphabets[i]==c)
                {
                    freq[i]++;
                    break;
                }
            }
        }
        //if the characterhas not been read before, put it in the alphabets array and make its frequency 1;
        else
        {
            if(isalpha(c)|| c==' ')
            {
                alphabets[no_of_characters]=c;
                freq[no_of_characters]=1;
                no_of_characters++;
            }
        }
    }
    while(c!=EOF);

    //print the characters andd their frequency read from the file
    printf("no_of_characters=%d",no_of_characters);
    for(i=0; i<no_of_characters; i++)
    {
        printf("\n%c  %d",alphabets[i],freq[i]);
    }
    rewind(fp);

    //make nodes of the elements in the alphabet array and frequency array
    //and put the nodes in a node array called array
    for(i=1; i<=no_of_characters; i++)
    {
        node* temp=(node*)malloc(sizeof(node));
        temp->left=NULL;
        temp->right=NULL;
        temp->alpha=alphabets[i-1];
        temp->freq=freq[i-1];
        array[i]=temp;
    }

    //create the huffman tree from the array of nodes
    node* root=huff(array,no_of_characters);

    //open file huffed.txt to write the decompressed or huffed code
    FILE* temp=fopen("huffed.txt","w");
    //read character by character from the input file i.e kunal.txt and wrrite them in huffed.txt
    do
    {
        top=0;
        c=fgetc(fp);
        //putchar(c);
        assigncode(root,aux,top,c,temp);

    }
    while(c!=EOF);
    fclose(fp);
    fclose(temp);
    printf("\nThe file has been huffed successfully!");

    //puffing
    fp=fopen("huffed.txt","r+");
    puts("\nContents of Huffed file:");

    while((c=fgetc(fp))!=EOF)
    {
        putchar(c);
    }
    rewind(fp);

    if(fp==NULL)
    {
        printf("could not open huffed.txt");
        return 1;
    }
    temp=fopen("puffed.txt","w+");
    if(fp==NULL)
    {
        printf("could not open puffed.txt");
        return 1;
    }
    node* ptr=root;
    //printf("\ndisp:");
    //inorderdisp(root);
    if(ptr==NULL)
    {
        printf("The file is empty!");
    }
    //read the contents of huffed file and traverse the huffman tree and write the characters to the puffed file as soon as we encounter a leaf node
    else
    {
        do
        {
            c=fgetc(fp);
            if(ptr->left==NULL && ptr->right==NULL)
            {
                fputc(ptr->alpha,temp);
                ptr=root;
            }

            if(c=='0')
            {
                ptr=ptr->left;

            }
            else if(c=='1')
            {
                ptr=ptr->right;
            }

        }
        while(c!=EOF);
    }
    fclose(fp);
    fclose(temp);
    fp=fopen("puffed.txt","r+");
    puts("\nContents of Puffed file:");
    while((c=fgetc(fp))!=EOF)
    {
        putchar(c);
    }
    return 0;
}

//to check if the character ch is in array arr or not
int isinarray(char ch,char arr[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(arr[i]==ch)
            return 1;
    }
    return 0;
}
//to display a file
void display_file(FILE* fp)
{
    rewind(fp);
    char c;
    while((c=fgetc(fp))!=EOF)
    {
        putchar(c);
    }
    rewind(fp);
}

void insheap(node* tree[size],int *n,node* item)
{
    *n=*n+1;
    int ptr=*n,par;
    while(ptr>1)
    {
        par=ptr/2;
        if(item->freq>=tree[par]->freq)
        {
            tree[ptr]=item;
            return;
        }
        tree[ptr]=tree[par];
        ptr=par;
    }
    tree[1]=item;
    return;
}
node* delheap(node* tree[size],int *n)
{
    node* last;
    int ptr,left,right;
    node* item=tree[1];
    last=tree[*n];
    *n=*n-1;
    ptr=1;
    left=2;
    right=3;
    while(right<=*n+1)
    {
        if(last->freq <= tree[left]->freq && last->freq <=tree[right]->freq)
        {
            tree[ptr]=last;
            return item;
        }
        if(tree[right]->freq >= tree[left]->freq)
        {
            tree[ptr]=tree[left];
            ptr=left;
        }
        else
        {
            tree[ptr]=tree[right];
            ptr=right;
        }
        left=2*ptr;
        right=left+1;
    }
    if(left==*n && last->freq > tree[left]->freq)
    {
        ptr=left;
    }
    tree[ptr]=last;
    return item;
}
node* huff(node* a[size],int n)
{
    int j;
    node *item1,*item2,*item3;
    for(j=1; j<n; j++)
    {
        insheap(a,&j,a[j+1]);
    }
    while(n>1)
    {
        item1=delheap(a,&n);
        item2=delheap(a,&n);
        item3=(node*)malloc(sizeof(node));
        item3->freq=item1->freq+item2->freq;
        if(item1->freq<item2->freq)
        {
            item3->left=item1;
            item3->right=item2;
        }
        else
        {
            item3->left=item2;
            item3->right=item1;
        }
        insheap(a,&n,item3);
    }
    return a[1];

}

int assigncode(node* root,char aux[],int top,char character,FILE* fp)
{
    int i;
    if(root!=NULL)
    {
        if(root->left)
        {
            aux[top]='0';
            assigncode(root->left,aux,top+1,character,fp);
        }
        if(root->right)
        {
            aux[top]='1';
            assigncode(root->right,aux,top+1,character,fp);
        }
        if(root->left==NULL && root->right==NULL)
        {
            if(root->alpha==character)
            {
                for(i=0; i<top; i++)
                {
                    putc(aux[i],fp);
                }
                return top;
            }
        }
    }
}
void inorderdisp(node* root)
{
    if(root!=NULL)
    {
        inorderdisp(root->left);
        if(root->left==NULL && root->right==NULL)
        printf("\n%c :%d  ",root->alpha,root->freq);
        inorderdisp(root->right);
    }
}
void disp(node* a[size],int n)
{
    int i;
    for(i=1; i<=n; i++)
    {
        printf("\n%c : %d",a[i]->alpha,a[i]->freq);
    }
    return;
}
