/*KUNAL ARORA
737/IT/12
PROGRAM-->insertion and deletion in an array
*/
#include<stdio.h>
void insert(int,int);
void del(int);
void disp();
int arr[20],size;
int main()
{
        int i,op,item,pos;
        printf("*******INSERTION & DELETION IN AN ARRAY**********\n");
        printf("KUNAL ARORA-737/IT/12\n");
        printf("Enter the no. of elements you want to insert in the array:\n");
        scanf("%d",&size);
        printf("Enter the elements of the array:");
        for(i=0;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }
        do
        {
            printf("\n1.Insert");
            printf("\n2.Delete");
            printf("\n3.Display");
            printf("\n4.Exit");
            printf("\nChoose an option(1/2/3/4)");
            scanf("%d",&op);
            switch(op)
            {
                case 1:
                    printf("Enter the element you want to insert:");
                    scanf("%d",&item);
                    printf("Enter the position of te element");
                    scanf("%d",&pos);
                    insert(item,(pos-1));
                    break;
                case 2:
                    printf("Enter the element you want to delete:");
                    scanf("%d",&item);
                    del(item);
                    break;
                case 3:
                    printf("The current array is:");
                    disp();
                    break;
                case 4:
                    break;
                default:
                    printf("Enter correct choice!!");
            }
        }while(op!=4);
        return 0;

}
void disp()
{
    int i;
    for(i=0;i<size;i++)
    {
        printf(" %d ",arr[i]);
    }
    return;
}
void insert(int item,int pos)
{
    int i;
    if(pos>(size))
    {
        printf("Enter the position inside the current array!!");
        return;
    }
    for(i=size-1;i>=pos;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=item;
    printf("\nInserted\n");
    size++;
    return;
}
void del(int item)
{
    int i,j;
    for(i=0;i<size-1;i++)
    {
        if(item==arr[i])
        {
            for(j=i;j<size-1;j++)
            {
                arr[j]=arr[j+1];
            }
            size--;
            printf("\nDeleted\n");
            return;
        }

    }
    printf("Item not found!");
    return;
}
