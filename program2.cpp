#include<stdio.h>
int main()
{
    int arrival_T[10],burst_T[10],rt[10],endTime,i,smallest;
    int remain=0,n,j,avgwait=0,avgturnaround=0;
    printf("Enter no of Processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time for Process P%d : ",i+1);
        scanf("%d",&arrival_T[i]);
        printf("Enter burst time for Process P%d : ",i+1);
        scanf("%d",&burst_T[i]);
        rt[i]=burst_T[i];
    }
   
    return 0;
}
