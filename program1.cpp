#include<stdio.h>
main()
{   starting :
	printf("1.SJF\n\nEnter your choice : ");
	int x,y,z,i,j;
	float avg_tt,avg_wt;
	FILE *ptr;
	scanf("%d",&x);
	switch(x)
	{
		case 1 :
			{   
				int at=0,bt[5],ct[5],tt[5],wt[5],pid[5];
				printf("Reading burst times of processes from file........\n\n");
				ptr=fopen("Burst.txt","rb");
				for(y=0;y<5;y++)
				{
					fread(&z,sizeof(z),1,ptr);
					bt[y]=z;
					pid[y]=y+1;
				}
				printf("Read Successful......\n");
				for(i=0;i<4;i++)
				for(j=0;j<4-i;j++)
				if(bt[j]>bt[j+1])
				{
					int temp=bt[j];
					bt[j]=bt[j+1];
					bt[j+1]=temp;
					temp=pid[j];
					pid[j]=pid[j+1];
					pid[j+1]=temp;
				}
				printf("\nImplementing Shortest Job First Algorithm...........\n\n");
				ct[0]=at+bt[0];
				tt[0]=ct[0]-at;
				wt[0]=tt[0]-bt[0];
				avg_tt=tt[0];
				avg_wt=wt[0];
				fclose(ptr);
				printf("Process_id              Burst_time         Completion_time         Turnaround_time           Waiting_time\n");
				printf("-----------------------------------------------------------------------------------------------------------\n");
				for(i=0;i<5;i++)
				printf("   P%d                     %d                    %d                       %d                        %d\n",pid[i],bt[i],ct[i],tt[i],wt[i]);
				printf("Average TurnAround_Time :%.2f\n",avg_tt/5.00);
				printf("Average Waiting Time    :%.2f\n",avg_wt/5.00);
				goto starting;
			
			}
	}
}
