#include<stdio.h>
int nm,np,i,j;
int M[10],P[10],FF[10],BF[10],WF[10];

void bestFit()
{
  printf("\n\nBest Fit : ");
  for(i=0;i<np;i++){
    int idx=-1;
    for(j=0;j<nm;j++){
      if(idx == -1 && BF[j]>P[i])
        idx=j;
      else if(BF[j]>P[i] && BF[j]<BF[idx])
        idx=j;
    }
    if(idx==-1)
      printf("\nProcess P%d-(%dK) must wait",i+1,P[i]);
    else {
      printf("\nProcess P%d-(%dK) is Put in Memory M%d-(%dK)",i+1,P[i],idx+1,BF[idx]);
      printf("(New Partition %dK-%dK = %dK)",BF[idx],P[i],BF[idx]-P[i]);
      BF[idx]=BF[idx]-P[i];
    }
  }
}
void worstFit()
{
  printf("\n\nWorst Fit : ");
  
  for(i=0;i<np;i++){
    int idx=-1;
    for(j=0;j<nm;j++){
      if(idx == -1 && WF[j]>P[i])
        idx=j;
      else if (idx != -1 && WF[j]>WF[idx])
        idx=j;
    }
    if(idx==-1)
      printf("\nProcess P%d-(%dK) must wait",i+1,P[i]);
    else {
      printf("\nProcess P%d-(%dK) is Put in Memory M%d-(%dK)",i+1,P[i],idx+1,WF[idx]);
      printf("(New Partition %dK-%dK = %dK)",WF[idx],P[i],WF[idx]-P[i]);
      WF[idx]=WF[idx]-P[i];
    }
  }
}
int main()
{
  printf("Enter no of Memory Partitions : ");
  scanf("%d",&nm);
  printf("Enter Memory size of Each Partition : ");
  for(i=0;i<nm;i++){
    scanf("%d",&M[i]);
    FF[i]=M[i];
    BF[i]=M[i];
    WF[i]=M[i];
  }
  printf("Enter no of Processes : ");
  scanf("%d",&np);
  printf("Enter Memory size of Each Process : ");
  for(i=0;i<np;i++)
    scanf("%d",&P[i]);
   
  bestFit();
  worstFit();
}
