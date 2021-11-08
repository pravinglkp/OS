#include<stdio.h>
char RS[50];

int nr,nf,i,j;

char F[5]={'_','_','_','_','_'};
int hit=0;
int isrt=0;
int flag1=0,flag2=0;
int k,max;

void optimal()
{
  printf("\n\n\nOptimal :- \n");
  printf("Pages   ");
  for(i=0;i<nf;i++)
    printf("F%d ",i+1);
  printf("-Hit/Page Fault-\n");
  for(i=0;i<nr;i++)
  {
    flag1=0,flag2=0;
    printf("%c\t",RS[i]);
    
    for(j=0;j<nf;j++)
    {
      if(F[j]==RS[i])
      {
      	for(j=0;j<nf;j++)
      		printf("%c  ",F[j]);
        printf("------ Hit -----\n");
        hit++;
        flag1=1;
        break;
      }
      else if(F[j]=='_')
      {
        isrt=j;
        flag2=1;
        break;
      }
    }
    if(flag1==1)
      continue;
    if(flag2!=1)
    {
      max=-1;
      for(j=0;j<nf;j++)
      {
        for(k=i+1;k<nr;k++)
        {
          if(F[j]==RS[k])
            break;
        }
        if(k==nr)
        {
          isrt=j;
          break;
        }
        else if(k>max)
        {
          max=k;
          isrt=j;
        }
      }
    }
    F[isrt]=RS[i];
    
    for(j=0;j<nf;j++)
      printf("%c  ",F[j]);
    printf("-- Page Fault --\n");
  }
  printf("\nNo of Page Faults = %d",nr-hit);
  printf("\nNo of Hits = %d",hit);
  printf("\nHit Ratio = %.2f",hit/(float)nr);
}
int main()
{
  printf("Enter number of References : ");
  scanf("%d",&nr);
  printf("Enter Reference String : ");
  for(i=0;i<nr;i++)
    scanf(" %c",&RS[i]);

  printf("Enter no of Frames : ");
  scanf("%d",&nf);

  
  optimal();

}
