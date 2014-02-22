/*KUNAL ARORA
737/IT/12
Program:To store student details in a file and print them
*/
#include<stdio.h>

typedef struct student
{
    char name[30];
    char roll[10];
    int marks;
}stu;
int main()
{
    stu s1;
    int choice,flag=0,i;
    FILE* fp;
    do
    {
        printf("\n1.Insert student record into file");
        printf("\n2.Display the student file");
        printf("\n3.EXIT");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                if(flag==0)
                    fp=fopen("student.txt","wb");
                else
                    fp=fopen("student.txt","ab");
                if(fp==NULL)
                {
                    printf("Could not open file successfully!!");
                }
                printf("\nEnter the student info:");
                printf("\nNAME:");
                scanf("%s",s1.name);
                printf("\nRoll no.:");
                scanf("%s",s1.roll);
                printf("\nMarks:");
                scanf("%d",&(s1.marks));
                fwrite(&s1,sizeof(s1),1,fp);
                flag=1;
                fclose(fp);
                break;
            case 2:
                fp=fopen("student.txt","rb");
                if(fp==NULL)
                {
                    printf("Could not open file successfully!!");
                    break;
                }
                printf("\nThe records in the file are:");
                i=1;
                while(fread(&s1,sizeof(stu),1,fp)==1)
                {
                     printf("\nRecord %d: %s , %s ,%d\n", i,s1.name, s1.roll,s1.marks); /* print each */
                     i++;
                }
                fclose(fp);
                break;
            case 3:
                break;
        }
    }while(choice!=3);
    return 0;
}

