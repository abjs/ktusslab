#include <stdio.h>
int main()
{
    int numberofResource, numberofProcess, i, j, c, count1 = 0, pscount = 0, count, flag=0;
    int resourceArray[25], Total[25], avl[25], allocation[30][25], maxNeed[30][25], avilable[30][25], remianingNeed[30][25], sequence[25], sumAllocation[50], remAvailable[50], processList[50];
    char processLetter = 'A';
    printf("Enter The number of Resorces:");
    scanf("%d", &numberofResource);
    for (int i = 0; i < numberofResource; i++)
    {
        printf("Enter the Number Of Resource Availability %c :", processLetter + i);
        scanf("%d", &resourceArray[i]);
    }

    printf("Enter The Number of Process:");
    scanf("%d", &numberofProcess);
    printf("\n\n\n");
    for (int i = 0; i < numberofProcess; i++)
    {
        printf("\n\nEnter The Details of Process : %d\n\n", i + 1);
        for (int j = 0; j < numberofResource; j++)
        {
            printf("\tEnter Resource Already Allocated for %c:", processLetter + j);
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("\n\n\n");
    for (int i = 0; i < numberofProcess; i++)
    {
        printf("\n\nEnter The Details of Process : %d\n\n", i + 1);
        for (int j = 0; j < numberofResource; j++)
        {
            printf("\tEnter Maximum Nedd of the Resource %c:", processLetter + j);
            scanf("%d", &maxNeed[i][j]);
        }
    }
    for (i = 0; i < numberofResource; i++)
    {
        sumAllocation[i] = 0;
    }
    for (i = 0; i < numberofProcess; i++)
    {
        for (j = 0; j < numberofResource; j++)
        {
            sumAllocation[j] += allocation[i][j];
        }
    }
    for (j = 0; j < numberofResource; j++)
    {

        remAvailable[j] = resourceArray[j] - sumAllocation[j];
    }
    printf("\n");
    // for (j = 0; j < numberofResource; j++)
    // {
    //     printf("%d", remAvailable[j]);
    // }

    for (i = 0; i < numberofProcess; i++)
    {
        for (j = 0; j < numberofResource; j++)
        {
            remianingNeed[i][j] = maxNeed[i][j] - allocation[i][j];
        }
        remianingNeed[i][numberofResource] = 0;
    }
    printf("\n   Allocated \t\t\t Max Need \t\t\t Remianing Need\n\n");
    for (i = 0; i < numberofProcess; i++)
    {
      
        for (j = 0; j < numberofResource; j++)
        {
            printf("%d\t", allocation[i][j]);
        }
        printf("\t");
        for (j = 0; j < numberofResource; j++)
        {
            printf("%d\t", maxNeed[i][j]);
        }
        printf("\t");
        for (j = 0; j < numberofResource; j++)
        {
            printf("%d\t", remianingNeed[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < numberofResource; i++)
    {
        printf("\nAvailable  Resource %c :%d", processLetter + i,resourceArray[i]);
        printf("\nAlready Allocated Resource %c :%d", processLetter + i,sumAllocation[i]);
        printf("\nRemianing  Resource %c :%d", processLetter + i,remAvailable[i]);
    }
    while (1)
    {
        for (i = 0; i < numberofProcess; i++)
        {
            count = 0;
            for (j = 0; j < numberofResource; j++)
            {
                if (remAvailable[j] >= remianingNeed[i][j])
                    count++;
            }
            if (remianingNeed[i][numberofResource] == 1)
            {
                count--;
            }
            if (count == numberofResource)
            {
                // printf("\nresource used %d\t", i);
                remianingNeed[i][numberofResource] = 1;
                count1++;
                processList[pscount]=i+1;
                pscount++;
                // printf("P%d \t", i + 1);

                for (j = 0; j < numberofResource; j++)
                {
                    remAvailable[j] += allocation[i][j];
                }
            }
        }
      
        if (count1 == numberofProcess)
            break;
        flag++;
        if (flag > numberofProcess){
            break;
        }
       
    }
    printf("\n\n");


    if( flag <= numberofProcess)
    {
        printf("Order:");
        for(i=0; i<numberofProcess; i++)
                printf("P%d\t",  processList[i]);
    }
    else{
            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n|\t     Dead lock occured\t\t|\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

    }
    printf("\n");
}


// 3 10 5 7  5   0 1 0 2 0 0 3 0 2 2 1 1 0 0 2 7 5 3 3 2 2 9 0 2 4 2 2 5 3 3
//3 10 5 7  5   0 1 0 2 0 0 3 0 2 2 1 1 0 0 4 7 5 3 3 2 2 9 20 2 4 2 2 5 3 3