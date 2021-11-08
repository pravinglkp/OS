#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	fork();
	printf("Good Morning!\n");
	return 0;	
}
