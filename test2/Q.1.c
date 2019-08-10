#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
	int data;
	struct queue *next;
}NODE;

NODE *top=NULL, *last=NULL;

void enQueue(int data)
{
	NODE *p;
	p=top;
	p=(NODE*)malloc(sizeof(NODE));
	p->next=NULL;
	p->data=data;
	if(top==NULL)
	{
		top=p;
		last=top;
	}
	else
	{
		last->next=p;
		last=p;
	}
}

void deQueue()
{
	NODE *p;
	p=top;
	if(p==NULL)
	{
		printf("\nQueue is empty!\n");
		return;
	}
	else
	{
		printf("\n%d is removed\n",top->data);
		top=p->next;
		free(p);
	}
}

void peek()
{
	if(top!=NULL)
		printf("\nTop value : %d\n",top->data);
	else
		printf("\nNo Value to show\n");
}

void disp()
{
	NODE *tmp;
	tmp=top;
	printf("\nQueue values : ");
	while(tmp!=NULL)
	{
		printf("%d\t",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
}

void main()
{
	int choice, val;
	while(1)
	{
		printf("\n1. Enque/Create\n2. Dequeue\n3. Peek\n4. Display\n Enter choice(1-4), exit otherwise : ");
		scanf("%d",&choice);

		if(choice==1)
		{
			printf("\nEnter value to enqueue : ");
			scanf("%d",&val);
			enQueue(val);
		}
		else if(choice==2)
			deQueue();
		else if(choice==3)
			peek();
		else if(choice==4)
			disp();
		else
			break;
	}
}
