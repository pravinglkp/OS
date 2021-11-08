#include<stdio.h>
struct process
{
	int at;
	int bt;
	int wt;
	int tt;
}P[20];
int isNotDone(int* sjf,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(sjf[i]!=1)
			return 1;
	}
	return 0;
}
int minpro(int* sjf,int n)
{
	int min=1000,minidx=-1,i;
	for(i=0;i<n;i++)
	{
		if(P[i].bt<=min && sjf[i]==0)
		{
			if(P[i].bt<min || P[i].at<P[minidx].at)
			{
			minidx=i;
			min=P[i].bt;
			}
		}
	}
	return minidx;
}
int main()
{
	printf("Sortest Job First Algorithm(Non-Pre-emtive) :-\n\n");
	int sjf[20],readyqueue[20];
	int n,i,j,cur,curtime=0;
	int totwt=0,tottt=0;
	float avgwt,avgtt;
	printf("Enter no of process : ");
	scanf("%d",&n);
	printf("Enter Arraival times of Each Process :-\n");
	for(i=0;i<n;i++)
	{
		printf("P%d --> ",i+1);
		scanf("%d",&P[i].at);
		P[i].wt=0;
		P[i].tt=0;
		sjf[i]=-1;
	}
	printf("Enter Burst times of Each Process :-\n");
	for(i=0;i<n;i++)
	{
		printf("P%d --> ",i+1);
		scanf("%d",&P[i].bt);
	}
	printf("\nOrder Of Exection : ");
	while(isNotDone(sjf,n))
	{
		for(i=0;i<n;i++)
		{
			if(sjf[i]==-1 && P[i].at<=curtime)
			{
				
				sjf[i]=0;
			}
		}
		cur=minpro(sjf,n);
		if(cur==-1)
		{
			curtime+=1;
			continue;
		}
		printf("P%d ",cur+1);
		curtime+=P[cur].bt;
		P[cur].tt=curtime-P[cur].at;
		tottt+=P[cur].tt;
		P[cur].wt=P[cur].tt-P[cur].bt;
		totwt+=P[cur].wt;
		sjf[cur]=1;
	}
	printf("\nProcess AT\tBT\tWT\tTT\n");
	for(i=0;i<n;i++)
	{
		printf("P-%d-->  %d\t%d\t%d\t%d\n",i+1,P[i].at,P[i].bt,P[i].wt,P[i].tt);
	}
	printf("\n\nAvarage   waiting  time : %0.2f",(totwt/(float)n));
	printf("\nAvarage turnaround time : %0.2f",(tottt/(float)n));
	return 0;
}
