#include<stdio.h>
#include<conio.h>
#include<process.h>
#define QUE_SIZE 3
int item,front=0,rear=-1,q[10];


void insertrear()
{
	if(rear==QUE_SIZE-1)
	{
		printf("Queue overflow\n");
	    return ;
	}
	else
	rear =rear+1;
	q[rear]=item;
}

int deletefront()
{
	if(front>rear)
	{
		front=0;
		rear=-1;
		return -1;
	}
	else
	front =front+1;
	return q[front];
}
void displayQ()
{
	int i;
	if(front>rear)
	{
		printf("Queue is empty\n");
	}
	else
	printf("Contents of queue are\n");
	for(i=front;i<=rear;i++)
	{
		printf("%d\n",q[i]);
	}
}
void main()
{
	int choice;
	for(;;)
	{
		printf("\n1:insert rear \n2 :Delete front \n3: Display \n4:Exit\n");
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
		  case 1:
			printf("enter the item to be inserted\n");
			scanf("%d",&item);
			insertrear();
			break;
		   case 2:
		    item=deletefront();
		    if(item==-1)
		    printf("Queue is empty\n");
		    else
		    printf("item deleted = %d\n",item);
		    break;
		   case 3:
		    displayQ();
		    break;
		   default:
		    exit(0);
			
			
			
			}
	}
}
