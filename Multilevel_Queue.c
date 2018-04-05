#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct Process{
	int process_id;
	int finish_time;
	int completed_time;
	int arr_time;
	int start_time;
	int priority;
	int burst_time;
};
void RoundRobin()
{
		int tq=4;
		int i;
		for( i=1;i<=5;i++)
		{
				if(process[i].priority==1)
			{
				process[i].burst_time=process[i].burst_time-tq;
				printf(process[i].burst_time);
			}
		}
		
	
}
void Fcfs()
{
	for(i=1;i<=n;i++)
	{
		if(process[i].)
		}	
}
void Priority()
{
	
}
int main()
{	
	int n,i,rr=0,pr=0,fc=0;
	int queueTimer=10,tq=4,timer=0;
	printf("Enter the number of processes \n");
	scanf("%d",&n);
	struct Process p[n];
    for(i=0;i<n;i++)
    {
    	printf("PROCESS %d \n",i);
		p[i].process_id=i+1;
		printf("Enter the Arrival Time\n");
    	scanf("%d",p[i].arr_time);
    	printf("Enter the priority from 1 to 5\n");
    	scanf("%d",p[i].priority);
    	if(p[i].priority==1)
		rr+;
		else if(p[i].priority==5)
		fc++;
		else 
		pr++;
		printf("Enter burst time\n");
    	scanf("%d",p[i].burst_time);	
		p[i].start_time=-1;
    	process[i].completed_time=0;
	}
	int rrid=0,prid=0,fcid=0;
	struct Process roundqueue[rr],priorqueue[pr],fcfsqueue[fc];
	for(i=0;i<n;i++)
	{
		if(p[i].priority==1)
		{
			roundqueue[rrid]=p[i];
			rrid++;
		}
		else if(p[i].priority==5)
		{
			priorqueue[prid]=p[i];
			prid++;
		}
		else
		{
			fcfsqueue[fcid]=p[i];
			fcid++;
		}
	}
}
