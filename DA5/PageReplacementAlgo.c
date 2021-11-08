#include<stdio.h>
char RS[50];

int nr,nf,i,j;

void fifo()
{
  char F[5]={'_','_','_','_','_'};
  int hit=0;
  int isrt=-1;
  int flag;

  printf("\n\n\nFIFO :- \n");
  printf("Pages   ");
  for(i=0;i<nf;i++)
    printf("F%d ",i+1);
  printf("\n");
  for(i=0;i<nr;i++)
  {
    flag=0;
    printf("%c\t",RS[i]);
    for(j=0;j<nf;j++)
    {
      if(F[j]==RS[i])
      {
        printf("--Hit--\n");
        hit++;
        flag=1;
        break;
      }
    }
    if(flag==1)
      continue;

    F[(++isrt)%nf]=RS[i];

    for(j=0;j<nf;j++)
      printf("%c  ",F[j]);
    printf("\n");

  }

  printf("\nNo of Page Faults = %d",nr-hit);
  printf("\nNo of Hits = %d",hit);
  printf("\nHit Ratio = %.2f",hit/(float)nr);

}

void lru()
{
  char F[5]={'_','_','_','_','_'};
  int t[5]={-1,-1,-1,-1,-1};
  int hit=0;
  int isrt=0;
  int flag1=0,flag2=0;

  printf("\n\n\nLRU :- \n");
  printf("Pages   ");
  for(i=0;i<nf;i++)
    printf("F%d ",i+1);
  printf("\n");
  for(i=0;i<nr;i++)
  {
    flag1=0;
    printf("%c\t",RS[i]);
    for(j=0;j<nf;j++)
    {
      if(F[j]==RS[i])
      {
        printf("--Hit--\n");
        hit++;
        t[j]=i;
        flag1=1;
        break;
      }
      else if(F[j]=='_')
      {
        isrt=j;
        break;
      }
      else if(t[j]<t[isrt]){
        isrt=j;
      }
    }
    if(flag1==1)
      continue;
    F[isrt]=RS[i];
    t[isrt]=i;
    
    for(j=0;j<nf;j++)
      printf("%c  ",F[j]);
    printf("\n");
  }
  printf("\nNo of Page Faults = %d",nr-hit);
  printf("\nNo of Hits = %d",hit);
  printf("\nHit Ratio = %.2f",hit/(float)nr);
}

void optimal()
{
  char F[5]={'_','_','_','_','_'};
  int hit=0;
  int isrt=0;
  int flag1=0,flag2=0;
  int k,max;

  printf("\n\n\nOptimal :- \n");
  printf("Pages   ");
  for(i=0;i<nf;i++)
    printf("F%d ",i+1);
  printf("\n");
  for(i=0;i<nr;i++)
  {
    flag1=0,flag2=0;
    printf("%c\t",RS[i]);
    
    for(j=0;j<nf;j++)
    {
      if(F[j]==RS[i])
      {
        printf("--Hit--\n");
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
    printf("\n");
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

  fifo();
  lru();
  optimal();

}