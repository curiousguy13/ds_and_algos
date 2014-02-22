/*given two strings
a)WAP to concatenate,copy one string to another
b) convert the string into uppercase
*/
#include<stdio.h>
#include<string.h>
#define size 50
void strupper(char str[2*size]);
int main()
{
    int i,j;
    char str1[2*size],str2[size],str3[2*size];
    printf("\nEnter the first string: ");
    gets(str1);
    printf("\nEnter the second string: ");
    gets(str2);
    for(i=strlen(str1),j=0;j<strlen(str2);i++,j++)
    {
        str1[i]=str2[j];
    }
    printf("\nThe concatenated string is: ");
    puts(str1);
    strupper(str1);
    printf("The concatenated string in uppercase is: ");
    puts(str1);
    return 0;
}
//to convert the string to uppercase
void strupper(char str[2*size])
{
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]>=97 && str[i]<=122)
        {
            str[i]=str[i]-32;
        }
    }
    return;
}
