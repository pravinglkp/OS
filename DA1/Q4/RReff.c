#include<stdio.h>
int readyqueue[20],size=0,next=0;
int n,TQ;

struct process
{
	int status;
	int at;
	int bt;
	int wt;
	int tt;
	int rbt;
}P[20];

int isNotDone()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(P[i].status!=1)
			return 1;
	}
	return 0;
}
void update(int time)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(P[i].status==-1 && P[i].at==time)
		{
			readyqueue[size++]=i;
			P[i].status=0;
		}
	}
}
int nextPro()
{
	if(next!=size)
	{
		return readyqueue[next++];
	}
	return -1;
}


int main()
{
	printf("Round Robin :-");
	
	int i,j,cur=-1,pre=-1;
	int curtime=0,pretime=0;
	int totwt=0,tottt=0;
	
	printf("Enter no of process : ");
	scanf("%d",&n);
	
	printf("Enter Arraival times of Each Process :-\n");
	for(i=0;i<n;i++)
	{
		printf("P%d --> ",i+1);
		scanf("%d",&P[i].at);
		P[i].wt=0;
		P[i].tt=0;
		P[i].status=-1;
	}
	
	printf("Enter Burst times of Each Process :-\n");
	for(i=0;i<n;i++)
	{
		printf("P%d --> ",i+1);
		scanf("%d",&P[i].bt);
		P[i].rbt=P[i].bt;
	}
	printf("Enter Time Quantum : ");
	scanf("%d",&TQ);
	printf("\nOrder Of Exection : ");
	update(0);
	while(isNotDone())
	{
		cur=nextPro();
		while(cur==-1)
		{
			curtime++;
			update(curtime);
			cur=nextPro();
		}
		if(pre != cur)
			printf(" P%d",cur+1);
		pretime=curtime;
		if(P[cur].rbt<=TQ)
		{
			curtime+=P[cur].rbt;
			P[cur].rbt=0;
			P[cur].status=1;
			P[cur].tt=curtime-P[cur].at;
			P[cur].wt=P[cur].tt-P[cur].bt;
			totwt+=P[cur].wt;
			tottt+=P[cur].tt;
		}
		else
		{
			curtime+=TQ;
			P[cur].rbt-=TQ;
		}
		pre=cur;
		for(i=pretime+1;i<=curtime;i++)
			update(i);
		if(P[cur].status!=1)
			readyqueue[size++]=cur;
		
	}
	printf("\n\nProcess AT\tBT\tWT\tTT\n");
	for(i=0;i<n;i++)
	{
		printf("P%d -->  %d\t%d\t%d\t%d\n",i+1,P[i].at,P[i].bt,P[i].wt,P[i].tt);
	}
	printf("\nAvarage   waiting  time : %0.2f",(totwt/(float)n));
	printf("\nAvarage turnaround time : %0.2f",(tottt/(float)n));
}
