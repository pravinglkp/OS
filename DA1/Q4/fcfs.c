#include<stdio.h>
struct process
{
	int at;
	int bt;
	int wt;
	int tt;
};
int main()
{
	printf("First Come First Serve Algorithm :-\n\n");
	struct process P[20];
	int fcfs[20];
	int n,i,j,cur=-1,curat;
	int curtime=0,totwt=0,tottt=0;
	printf("Enter no of process : ");
	scanf("%d",&n);
		printf("Enter Arraival times of Each Process :-\n");
	for(i=0;i<n;i++)
	{
		printf("P%d --> ",i+1);
		scanf("%d",&P[i].at);
		P[i].wt=0;
		P[i].tt=0;
		fcfs[i]=-1;
	}
	printf("Enter Burst times of Each Process :-\n");
	for(i=0;i<n;i++)
	{
		printf("P%d --> ",i+1);
		scanf("%d",&P[i].bt);
	}
	printf("\nOrder of Execution : ");
	for(i=0;i<n;i++)
	{
		curat=1000;
		for(j=0;j<n;j++)
		{
			if(fcfs[j]==-1 && P[j].at<curat)
			{
				cur=j;
				curat=P[j].at;
			}
		}		
		fcfs[cur]=i;
		if(P[cur].at>curtime)
			curtime=P[cur].at;
		printf(" P%d",cur+1);
		curtime+=P[cur].bt;
		P[cur].tt=curtime-P[cur].at;
		P[cur].wt=P[cur].tt-P[cur].bt;
		totwt+=P[cur].wt;
		tottt+=P[cur].tt;
	}		
	printf("\n\nProcess   AT\tBt\tWT\tTT\n");
	for(i=0;i<n;i++)
	{
		printf("P-%d  -->  %d\t%d\t%d\t%d\n",i+1,P[i].at,P[i].bt,P[i].wt,P[i].tt);
	}
	printf("\nAvarage   waiting  time : %0.2f",(totwt/(float)n));
	printf("\nAvarage turnaround time : %0.2f",(tottt/(float)n));
	return 0;
}