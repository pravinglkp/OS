
#include<stdio.h>
int i,j;//temp
int n;//no of Process
int m;//no of resources

int instance[10];

int max[10][10];
int allocation[10][10];

int available[10];
int need[10][10];

int sequence[10];
int availseq[10][10];
int flag1[10];
int doneprocess=0;

void readsize()
{
	printf("Enter number of Processess : ");
	scanf("%d",&n);
	
	printf("Enter number of Types of Resources : ");
	scanf("%d",&m);
} 

void readinstances()
{
	printf("Enter Maximum Instance of Each Resources : \n");
	for(i=0;i<m;i++)
	{
		printf("%c : ",i+'A');
		scanf("%d",&instance[i]);
	}
}

void readallocation()
{
	printf("Enter Instance of Each Resources Each Process Currently Holds :\n\t");
	for(i=0;i<m;i++)
		printf("%c ",i+'A');
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("P%d-->   ",i);
		for(j=0;j<m;j++)
			scanf("%d",&allocation[i][j]);
	}
}

void readmax()
{
	printf("Enter Instance of Each Resources Each Process can Maximum Request :\n\t");
	for(i=0;i<m;i++)
		printf("%c ",i+'A');
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("P%d-->   ",i);
		for(j=0;j<m;j++)
			scanf("%d",&max[i][j]);
	}	
}


void dispavail()
{
	printf("\nAvailable Resources : ");
	for(i=0;i<m;i++)
	{
		available[i]=instance[i];
		for(j=0;j<n;j++)
			available[i]-=allocation[j][i];	
		printf("%d ",available[i]);
	}	
}
void dispneed()
{
	printf("\n\nNeed of Each Resources of Each Process :\n\t");
	for(i=0;i<m;i++)
		printf("%c ",i+'A');
	
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t",i);
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
			printf("%d ",need[i][j]);	
		}	
	}
}
int check()
{
	int count=0;
	for(i=0;i<n;i++)
	{
		if(flag1[i]==1)
			count++;
	}
	if(count==n)
		return 0;
	else if(doneprocess==count)
		return -1;
	else
	{
		doneprocess=count;
		return 1;
	}
		
	
}
void bankers()
{
	int flag2;
	int ans=0;
	int idx=0;
	
	//step1
	for(i=0;i<n;i++)
		flag1[i]=0;
	
	dispneed();
	
	
	do
	{
		for(i=0;i<n;i++)
		{
			if(flag1[i]==0)
			{
				flag2=0;
				for(j=0;j<m;j++)
				{
					if(need[i][j]>available[j])
					{
						flag2=1;
						break;
					}
						
				}
				if(flag2==0)
				{
					sequence[idx]=i;
					flag1[i]=1;
					for(j=0;j<m;j++)
					{
						availseq[idx][j]=available[j];
						available[j]+=allocation[i][j];	
					}
					idx++;	
				}	
			}
		}	
	}while((ans=check())==1);
	
	if(ans==-1)
		printf("\nSystem in unsafe state\nDeadlock may occur");
	else
	{
		printf("\nSystem in Safe state\nDeadlock will not occur\n");
		printf("\nSafe Sequence : <");
		for(i=0;i<n;i++)
		{
			printf(" P%d(",sequence[i]);
			for(j=0;j<m;j++)
				printf(" %d",availseq[i][j]);
			printf(" )");
		}
			
		printf(" >");
		
	}
}

int main()
{
	readsize();
	readinstances();
	readallocation();
	readmax();
	
	dispavail();
	
	
	bankers();
	
	
	return 0;
}
