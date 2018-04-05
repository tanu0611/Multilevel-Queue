#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int i,timer=0,queueTimer=10,total;
struct Process{
	int process_id;
	int finish_time;
	int completed_time;
	int arr_time;
	int start_time;
	int priority;
	int burst_time;
	int store;
};
void RoundRobin(struct Process p[],int r)
{	
		int tq=4;
		for( i=0;i<r;i++)
		{	
			if(tq<=queueTimer&&p[i].arr_time<=timer)
			{
			if(p[i].start_time==-1)
			{
			p[i].start_time=timer;
			}
			if(p[i].burst_time>=4)
			{
			p[i].burst_time=p[i].burst_time-tq;
			timer=timer+tq;
			queueTimer-=tq;
			}
			if(p[i].burst_time<4&&p[i].burst_time>0)
			{
			timer=timer+p[i].burst_time;
			queueTimer-=p[i].burst_time;
			p[i].burst_time=0;
			}
			if(p[i].burst_time==0&&p[i].completed_time==-1)
			{
				p[i].completed_time=timer;
				total--;
			}
			}
		}
		queueTimer=10;
}
void Fcfs(struct Process p[],int r)
{
		for(i=0;i<r;i++)
		{	
			if(p[i].burst_time<=queueTimer&&p[i].arr_time<=timer&&p[i].burst_time>0)
			{
			if(p[i].start_time==-1)
			p[i].start_time=timer;
			p[i].burst_time=0;
			timer=timer+p[i].burst_time;
			queueTimer-=p[i].burst_time;
			if(p[i].burst_time==0&&p[i].completed_time==-1)
			{
				p[i].completed_time=timer;
				total--;
			}
			}
			else
			{
				if((p[i].burst_time-queueTimer>0)&&p[i].arr_time<=timer&&p[i].burst_time>0)
				{
				if(p[i].start_time==-1)
				p[i].start_time=timer;
				p[i].burst_time=p[i].burst_time-queueTimer;
				timer=timer+queueTimer;
				queueTimer=0;
				if(p[i].burst_time==0&&p[i].completed_time==-1)
				{
					p[i].completed_time=timer;
					total--;
				}
				}
			}
		}
		queueTimer=10;
}
void Priority(struct Process p[],int r)
{
	int remain=r,smallest;
	while(remain!=0&&queueTimer>0)
	{
	smallest=r+1;
	for(i=0;i<r;i++)
	{
	if(p[i].arr_time<=timer && p[i].priority<p[smallest].priority && p[i].burst_time>0)
	{
	smallest=i;
	}
	}
	if(p[i].burst_time<=queueTimer)
	{
		if(p[i].start_time==-1)
				p[i].start_time=timer;
	timer+=p[smallest].burst_time;
	queueTimer-=p[smallest].burst_time;
	remain--;
	p[smallest].burst_time=0;
	}
	if(p[i].burst_time-queueTimer>0)
	{
		if(p[i].start_time==-1)
				p[i].start_time=timer;
	p[smallest].burst_time=p[i].burst_time-queueTimer;
	timer+=queueTimer;
	queueTimer=0;
	remain--;
	}
	if(p[i].burst_time==0&&p[i].completed_time==-1)
	{
	p[i].completed_time=timer;
	total--;
	}
	}
	queueTimer=10;
}
int main()
{	
	int n,i,rr=0,pr=0,fc=0;
	total=n;
	printf("Enter the number of processes \n");
	scanf("%d",&n);
	total=n;
	struct Process p[n];
    for(i=0;i<n;i++)
    {
    	printf("PROCESS %d \n",i+1);
		p[i].process_id=i+1;
		printf("Enter the Arrival Time\n");
    	scanf("%d",&p[i].arr_time);
    	printf("Enter the priority from 1 to 5\n");
    	scanf("%d",&p[i].priority);
    	p[i].completed_time=-1;
    	p[i].start_time=-1;
    	if(p[i].priority==1)
		rr++;
		else if(p[i].priority==5)
		fc++;
		else 
		pr++;
		printf("Enter burst time\n");
    	scanf("%d",&p[i].burst_time);	
		p[i].store=p[i].burst_time;
		p[i].start_time=-1;
    	p[i].completed_time=-1;
	}
	int rrid=0,prid=0,fcid=0;
	struct Process roundqueue[rr],priorqueue[pr+1],fcfsqueue[fc];
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
	priorqueue[prid].priority=INT_MAX;
	while(total>0)
	{
		RoundRobin(roundqueue,rr);
		Priority(priorqueue,pr);
		Fcfs(fcfsqueue,fc);
	}
	printf("PID AT BT ST CT\n");
	for(i=0;i<rr;i++)
	{
		printf("%2d %2d %2d %2d %2d\n",roundqueue[i].process_id,roundqueue[i].arr_time,roundqueue[i].store,roundqueue[i].start_time,roundqueue[i].completed_time);
	}
}
