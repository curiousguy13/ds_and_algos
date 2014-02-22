#include<stdio.h>
#include<string.h>
int main()
{
    char str[50],sub[50];
    int found=0,i,j,k;
    printf("Enter the string:");
    fflush(stdin);
    gets(str);
    fflush(stdin);
    printf("Enter the substring to be searched:");
    fflush(stdin);
    gets(sub);
    fflush(stdin);
    for(i=0;i<strlen(str);i++)
    {
        if(sub[j]==str[i])
        {
            for(j=0;j<strlen(sub);j++,i++)
            {
                if(sub[j]!=str[i])
                {
                    found=0;
                    break;
                }
                found=1;
            }
            if(found==1)
            {
                printf("The substring is found at %d\n",i+1);
            found=0;
            }
        }
    }
    return 0;
}
