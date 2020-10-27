#include <stdio.h>

int main()
{
    char str[50][50][50];
  
    int count, num[50];
    printf("Enet the number of directorys in level 1 :");
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        printf("Enter The %d th main directory name :", i + 1);
        scanf("%s",str[i][0]);
        printf("Enter The Sub directory name in %s:", str[i][0]);
        scanf("%s",str[i][1]);

        printf("Enter The Number of Files in Directory %s:", str[i][1]);
        scanf("%d", &num[i]);

        for (int j = 2; j < num[i] + 2; j++)
        {
            printf("Enter The %d th File in the directory %s:", i + 1, str[i][1]);
            scanf("%s", str[i][j]);
        }
    }
    /*          Printing the results     */

    for (int i = 0; i < count; i++)
    {
        printf("\n");
        printf("Folder Name:%s", str[i][0]);
        printf("\n\t");
        printf("Sub Folder:%s", str[i][1]);

        printf("\n\t\t");
        for (int j = 2; j < num[i] + 2; j++)
        {
            printf("%s", str[i][j]);
            printf("\n");
        }
    }

    return (0);
}