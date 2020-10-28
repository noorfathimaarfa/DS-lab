#include<stdio.h>
#include<conio.h>
#include<process.h>
#define QUE_SIZE 5
int item,front=0,rear=-1,q[QUE_SIZE],count=0;

void insertrear()
{
	
	if(count==QUE_SIZE)
	{
		printf("Queue overflow\n");
		return;
	}
	
	else
	rear=(rear+1)%QUE_SIZE;
	q[rear]=item;
	count++;
}
int deletefront()
{
	if(count==0)
	return -1;
	else
	item=q[front];
	front=(front+1)%QUE_SIZE;
	count=count-1;
	return item;
}
void display()
{
	int i;
	if(count==0)
	{
		printf("Queue iis empty");
		return ;
	}
	else
	printf("Contents of queue \n");
	for(i=1;i<=count;i++)
	{
		printf("%d\n",q[front]);
		front=(front+1)%QUE_SIZE;
	}

}
void main()
{
	int choice;
	for(;;)
	{
		printf("\n1:insertrear\n2:deletefront\n3display\n4:exit");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				insertrear();
				break;
			case 2:
				item=deletefront();
				if(item==-1)
				printf("Queue is empty\n");
				else
				printf("the item deleted is %d",item);
				break;
			case 3:
				display();
			    break;
		    case 4:
		    	exit(0);
		    	
		}
	}
}
