#include<stdio.h>
struct process
{
	int priority;
	int at;
	int bt;
	int wt;
	int tt;
	int rbt;
}P[20];
int isNotDone(int* psq,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(psq[i]!=1)
			return 1;
	}
	return 0;
}
int nextpro(int* psq,int n)
{
	int maxpri=1000,idx=-1,i;
	for(i=0;i<n;i++)
	{
		if(P[i].priority<=maxpri && psq[i]==0)
		{
			if(idx==-1)
			{
				idx=i;
				maxpri=P[i].priority;
			}
			else if(P[i].priority<maxpri || P[i].at<P[idx].at)
			{
				idx=i;
				maxpri=P[i].priority;
			}
		}
	}
	return idx;
}

void aging(int *psq,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(psq[i]==0&&P[i].priority>0)
			P[i].priority--;
	}
}

int main()
{
	printf("Priority Sceduling Algorithm : (Preemtive) with Aging:-\n");
	int psq[20];
	int n,i,j,curpro,cur,curtime=0,pre=-1;
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
		psq[i]=-1;
	}
	printf("Enter Burst times of Each Process :-\n");
	for(i=0;i<n;i++)
	{
		printf("P%d --> ",i+1);
		scanf("%d",&P[i].bt);
		P[i].rbt=P[i].bt;
	}
	printf("Enter Prority of Each Process :-\n");
	for(i=0;i<n;i++)
	{
		printf("P%d --> ",i+1);
		scanf("%d",&P[i].priority);
	}
	printf("\nOrder of Exection : ");
	while(isNotDone(psq,n))
	{
		if(curtime%3==0&&curtime!=0)
			aging(psq,n);
		for(i=0;i<n;i++)
		{
			if(psq[i]==-1 && P[i].at<=curtime)
			{
				psq[i]=0;
			}
		}
		cur=nextpro(psq,n);
		if(cur==-1)
		{
			curtime+=1;
			continue;
		}
		P[cur].rbt-=1;
		if(pre != cur)
			printf("P%d ",cur+1);
		curtime+=1;
		if(P[cur].rbt==0)
		{
			P[cur].tt=curtime-P[cur].at;
			P[cur].wt=P[cur].tt-P[cur].bt;
			tottt+=P[cur].tt;
			totwt+=P[cur].wt;
			psq[cur]=1;
		}
		pre=cur;
	}
	
	printf("\n\nProcess AT\tBT\tPri\tWT\tTT\n");
	for(i=0;i<n;i++)
	{
		printf("P%d -->  %d\t%d\t%d\t%d\t%d\n",i+1,P[i].at,P[i].bt,P[i].priority,P[i].wt,P[i].tt);
	}
	printf("\nAvarage   waiting  time : %0.2f",(totwt/(float)n));
	printf("\nAvarage turnaround time : %0.2f",(tottt/(float)n));
	return 0;
}


	

