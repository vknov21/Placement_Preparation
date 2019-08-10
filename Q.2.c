#include<stdio.h>
#include<stdlib.h>
int arriv[10], burst[10], proCount=0;

void procQ();
void checkQ(int,int);
void readyQ(int);

typedef struct readyQueue
{
	int process;
	int arrTime;
	int bursTime;
	struct readyQueue *next;
}NODE;

/*typedef struct ganttChart
{
	int process[10];
	int arrTime;
	int bursTime;
	struct ganttChart *next;
}gc;*/

//NODE *start=NULL;
NODE *top=NULL,*last=NULL;

void checkQ(int arrive, int n)
{
	int i=0;
	while(i<n)
	{
		if(arrive==arriv[i])
		{
			readyQ(i);
		}
		i++;
	}
}

void readyQ(int i)
{
	NODE *p;
	p=top;
	p=(NODE*)malloc(sizeof(NODE));
	if(top==NULL)
	{
		top=p;
		last=p;
	}
	else
	{
		last->next=p;
		last=p;
	}
	p->process=i+1;
	p->arrTime=arriv[i];
	p->bursTime=burst[i];
	p->next=NULL;
}

void process()
{
	if(top==NULL)
	{
		return;
	}

	if(top->bursTime==0)
	{
		procQ();
	}
	else
	{
		top->bursTime=top->bursTime-1;
	}

}

void procQ()
{
	NODE *p;
	p=top;
	top=p->next;
	free(p);
	proCount++;
}

void main()
{
	int i=0, count=0, ch, n;
	printf("Number of processes : ");
	scanf("%d",&n);
	while(i<n)
	{
		printf("Enter Arrival Time for Process P%d : ",i+1);
		scanf("%d",&arriv[i]);
		printf("Enter Burst Time for Process P%d : ",i+1);
		scanf("%d",&burst[i++]);
	}
	i=0;
	while(proCount<n)
	{
		NODE *p;
		p=top;
		printf("\n");
		if(p==NULL)
			printf("count:%d",count);
		while(p!=NULL)
		{
			printf("count:%d  %d : %d %d, \t",count,p->process,p->arrTime,p->bursTime);
			p=p->next;
		}
		process();
		checkQ(count, n);
		count++;
	}
	printf("\n");
}
