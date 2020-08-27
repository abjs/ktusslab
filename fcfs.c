#include <stdio.h>
void main()
{
    int i,n, a[20], b[20],c[20],t[20],wt[20];
    float act=0,atat=0,awt=0;
    // a is  for Arrival Time, b is for Burst Time ,c is for Complition Time ,t is   for Turnround Time,wt is for Waiting time 
    printf("Enter The Number of Process\t:\t");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter The Arrival Time of Process \t%d:\t", i + 1);
        scanf("%d", &a[i]);
        printf("\nEnter The Burst Time of Process   \t%d:\t", i + 1);
        scanf("%d", &b[i]);
    }   
    c[0]=b[0];
    for (i = 1; i < n; i++)
        c[i] = c[i-1]+b[i];
    for (i = 0; i < n; i++)
        t[i] = c[i] - a[i];
    for (i = 0; i < n; i++)
        wt[i] = t[i] - b[i];
    printf("\nProcess Number\tArrival Time\tBurst Time\tComplition Time\tTurnaround Time\tWaiting Time");
    for (i = 0; i < n; i++)
        printf("\n%d\t\t  %d\t\t  %d\t\t  %d\t\t  %d\t\t  %d",i+1,a[i],b[i],c[i],t[i],wt[i]);
        for(i=0;i<n;i++)
    {
        act=act+c[i];
        atat=atat+t[i];
        awt=awt+wt[i];
    } 
    act/=n;
    atat/=n;
    awt/=n;
    printf("\nAverage Complition Time \t:\t%f",act);
    printf("\nAverage Turnaround Time \t:\t%f",atat);
    printf("\nAverage Waiting Time \t\t:\t%f",awt);
}