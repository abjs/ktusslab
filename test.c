#include <stdio.h>
#include <string.h>
int main()
{
    char str[50][50][50], format[4]
    ;
    char dote='.';
    int count, num[50];
    printf("Enet The Number of Directorys in Level ONE  :");
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        printf("Enter The %d th Main Directory Name :", i + 1);
        scanf("%s", str[i][0]);
        printf("Enter The Sub directory Name in %s:", str[i][0]);
        scanf("%s", str[i][1]);

        printf("Enter The Number of Files in Directory %s:", str[i][1]);
        scanf("%d", &num[i]);

        for (int j = 2; j < num[i] + 2; j++)
        {
            printf("Enter The %d th File in the directory %s:", i + 1, str[i][i]);
            scanf("%s", str[i][j]);
            // printf("Enter the Format:");
            // scanf("%s", format);
            // strcpy(str[i][j],dote);
            // strcpy(str[i][j], format);
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
        printf("")
        for (int j = 2; j < num[i] + 2; j++)
        {
            printf("%s", str[i][j]);
        }
    }

    return (0);
}