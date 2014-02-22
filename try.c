#include<stdio.h>
int main()
{
    char c;
    FILE* fp=fopen("huffed.txt","r+");
    while((c=fgetc(fp))!=EOF)
    {
        putchar(c);
    }
}
