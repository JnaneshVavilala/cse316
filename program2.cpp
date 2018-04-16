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
    printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
    rt[9]=9999;
    for(j=0;remain!=n;j++)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
            if(arrival_T[i]<=j && rt[i]<rt[smallest] && rt[i]>0)
            {
                smallest=i;
            }
        }
        rt[smallest]--;
        if(rt[smallest]==0)
        {
            remain++;
            endTime=j+1;
            printf("\nP[%d]\t|\t%d\t|\t%d",smallest+1,endTime-arrival_T[smallest],endTime-burst_T[smallest]-arrival_T[smallest]);
            avgwait+=endTime-burst_T[smallest]-arrival_T[smallest];
            avgturnaround+=endTime-arrival_T[smallest];
        }
    }
    printf("\n\nAverage waiting time = %f\n",avgwait*1.0/n);
    printf("Average Turnaround time = %f",avgturnaround*1.0/5);
    return 0;
}
