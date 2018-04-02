#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<pthread.h>
typedef struct Process{
	int process_id;
	int finish_time;
	bool completed_time;
	int arr_time;
	int priority;
	int burst_time;
;
} st_Process ;
st_Process process[] ;	
int wt[5],tat[5],av_tat,av_wt;


void *RoundRobin()
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
void *Fcfs()
{
		
}
void *Priority()
{
	
}
int main()
{	
	int n,i;
	printf("Enter the number of processes \n");
	scanf("%d",&n);
    
   
    for(i=1;i<=n;i++)
    {
    	printf("PROCESS %d \n",i);
    	printf("Enter the process id \n");
    	scanf("%d",process[i].process_id);
    	printf("Enter the priority\n");
    	scanf("%d",process[i].priority);
    	process[i].arr_time=0;
    	process[i].finish_time=0;
    	printf("Enter burst time\n");
    	scanf("%d",process[i].burst_time);
    	process[i].completed_time=false;
    	
	}
	for(i=1;i<=n;i++)
	{
		if(process[i].priority==1||process[i].priority==2)
		RoundRobin();
		else if(process[i].priority==3||process[i].priority==4)
		Fcfs();
		else 
		Priority();
	}
}
