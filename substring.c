//not working correctly as it only displays the first instance of the substring
#include<stdio.h>
#include<string.h>
#include<time.h>
int main()
{
    clock_t start,end;
    double time_taken;
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
    start=clock();
    for(i=0;i<strlen(str);i++)
    {
        j=0;
        if(sub[j]==str[i])
        {
           // printf("\ninside");
            found=0;
            for(k=i,j=0;k<strlen(sub);k++,j++)
            {
                //printf("%c & %c",str[k],sub[j]);
                if(str[k]!=sub[j])
                {
                    found=0;
                    break;
                }

                found=1;
                //printf("found=%d",found);
            }
            j=0;

        }
        if(found==1)
        {
            printf("The substring is found at %d\n",i+1);
            found=0;
        }

    }
    end=clock();
    time_taken=(end-start)/CLOCKS_PER_SEC;
    printf("ntim-->%f\n",time_taken);
    return 0;
}


