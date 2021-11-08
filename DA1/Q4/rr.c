#include<stdio.h>

struct process
{
       int p;
	   int at;
	   int bt;
	   int wt;
	   int tt;
	   int rnt;
};
 
void sortart(struct process P[],int pro)
{
       int i,j;
       struct process temp;
       for(i=0;i<pro;i++)
       {
              for(j=i+1;j<pro;j++)
              {
                     if(P[i].at > P[j].at)
                     {
                           temp = P[i];
                           P[i] = P[j];
                           P[j] = temp;
                     }
              }
       }
       return;
}
 
int main()
{
       int i,j,n,time,remain,flag=0,ts;
       struct process P[100];
       int totwt=0,tottt=0;
       printf("Round Robin Scheduling Algorithmn :-\n");

       printf("Enter number of process : ");
       scanf("%d",&n);
       remain=n;
       printf("Enter arrival time for processess :\n");
       for(i=0;i<n;i++)
       {
       		printf("P-%d-->",i+1);
          	scanf("%d",&P[i].at);
          	P[i].p = i;
       } 
       printf("Enter burst time for processess :\n");
       for(i=0;i<n;i++)
       {
       		printf("P-%d-->",i+1);
            scanf("%d",&P[i].bt);
            P[i].rnt = P[i].bt;
       }
       sortart(P,n);
       printf("Enter Time Quantum : ");
       scanf("%d",&ts);
       printf("\nOrder Of Execution :");
       for(time=0,i=0;remain!=0;)
       {
              if(P[i].rnt<=ts && P[i].rnt>0)
              {
                     time = time + P[i].rnt;
                     printf(" P%d",P[i].p+1);
                     P[i].rnt=0;
                     flag=1;
              }
              else if(P[i].rnt > 0)
              {
                     P[i].rnt = P[i].rnt - ts;
                     time = time + ts;
                     printf(" P%d",P[i].p+1);
              }
              if(P[i].rnt==0 && flag==1)
              {
                     remain--;
                     P[i].tt = time-P[i].at;
                     P[i].wt = time-P[i].at-P[i].bt;
                     totwt = totwt + time-P[i].at-P[i].bt;
                     tottt = tottt + time-P[i].at;
                     flag=0;
              }
              if(i==n-1)
                     i=0;
              else if(P[i+1].at <= time)
                     i++;
              else
                     i=0;
       }
       printf("\nProcess\tAT\tBT\tWT\tTT\n");
       for(i=0;i<n;i++)
       {
              printf("P%d\t%d\t%d\t%d\t%d\n",P[i].p+1,P[i].at,P[i].bt,P[i].wt,P[i].tt);
       }
       
       printf("\nAverage Waiting Time : %.2f\n",totwt/(float)n);
       printf("Average Turnaround Time : %.2f\n\n",tottt/(float)n);
       return 0;
}