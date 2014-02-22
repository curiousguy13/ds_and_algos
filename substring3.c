/*KUNAL ARORA
737/IT/12
PROGRAM-->substring search using naive substring search algorithm
*/

#include<stdio.h>
#include<string.h>
int strncmp2(char*,int,char*);
int main()
{

    char str[50],sub[50];
    int found=0,i,j,k;
    printf("\n*********SUBSTRING SEARCH***********\n");
    printf("\nKUNAL ARORA\n");
    printf("Enter the string:");

    gets(str);

    printf("Enter the substring to be searched:");

    gets(sub);

    printf("\nThe entered substring is present at the location(s):");
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]==sub[0])
        {
            if(strncmp2(str,i,sub))
            {
                k=i+1;
                printf(" %d ",k);
            }

        }
    }
    return 0;

}
//function to compare two strings
int strncmp2(char* str,int pos,char* sub)
{
    int i=0,j=0;
    for(i=0,j=pos;i<strlen(sub);i++,j++)
    {
        if(str[j]==sub[i])
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
