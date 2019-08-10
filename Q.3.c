#include<stdio.h>
#include<stdlib.h>
int arriv[10], burst[10], proCount=0;

void procQ();
void checkQ(int,int);
void readyQ(int);
void changeQ();

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

void changeQ()
{
	NODE *p,*tmp2,*tmp1;
	tmp1=top;
	tmp2=top->next;

	if(tmp2==NULL || tmp1==NULL)
		return;
	else
	{
		while(tmp2->next!=NULL)
		{
			if(tmp1->bursTime<tmp2->bursTime)
			{
				if(tmp1->next==tmp2)
				{
					last->next=top;
					last=last->next;
					last->next=NULL;
					top=tmp2;
				}
				else
				{
					last->next=top;
					last=last->next;
					top=tmp2;
					p->next=tmp2->next;
					top->next=tmp1->next;
					last->next=NULL;
				}
				break;
			}
			p=tmp2;
			tmp2=tmp2->next;
		}
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
		top=top->next;
	}
	else
	{
		top->bursTime=top->bursTime-1;
	}
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
		process();

		if(p==NULL)
			printf("count:%d",count);
		while(p!=NULL)
		{
			printf("count:%d  %d : %d %d, \t",count,p->process,p->arrTime,p->bursTime);
			p=p->next;
		}
		checkQ(count, n);
		changeQ();
		count++;
	}
	printf("\n");
}
