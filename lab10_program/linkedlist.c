#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
struct node
{
  int info;
  struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
 {
  printf("mem full\n");
  exit(0);
 }
 return x;
}
void freenode(NODE x)
{
free(x);
}
NODE insert_front(NODE first,int item)
{
NODE temp;
temp=getnode();
temp->info=item;
temp->link=NULL;
if(first==NULL)
return temp;
temp->link=first;
first=temp;
return first;
}
NODE delete_front(NODE first)
{
NODE temp;
if(first==NULL)
{
printf("list is empty cannot delete\n");
return first;
}
temp=first;
temp=temp->link;
printf("item deleted at front-end is=%d\n",first->info);
free(first);
return temp;
}
NODE insert_rear(NODE first,int item)
{
NODE temp,cur;
temp=getnode();
temp->info=item;
temp->link=NULL;
if(first==NULL)
 return temp;
cur=first;
while(cur->link!=NULL)
 cur=cur->link;
cur->link=temp;
return first;
}
NODE delete_rear(NODE first)
{
NODE cur,prev;
if(first==NULL)
{
printf("list is empty cannot delete\n");
return first;
}
if(first->link==NULL)
{
printf("item deleted is %d\n",first->info);
free(first);
return NULL;
}
prev=NULL;
cur=first;
while(cur->link!=NULL)
{
prev=cur;
cur=cur->link;
}
printf("iten deleted at rear-end is %d",cur->info);
free(cur);
prev->link=NULL;
return first;
}
NODE insert_pos(int item,int pos,NODE first)
{
NODE temp;
NODE prev,cur;
int count;
temp=getnode();
temp->info=item;
temp->link=NULL;
if(first==NULL && pos==1)
return temp;
if(first==NULL)
{
 printf("invalid pos\n");
 return first;
}
if(pos==1)
{
temp->link=first;
return temp;
}
count=1;
prev=NULL;
cur=first;
while(cur!=NULL && count!=pos)
{
 prev=cur;
 cur=cur->link;
 count++;
}
if(count==pos)
{
prev->link=temp;
temp->link=cur;
return first;
}
printf("IP\n");
return first;
}
void display(NODE first)
{
 NODE temp;
 if(first==NULL)
 printf("list empty cannot display items\n");
 for(temp=first;temp!=NULL;temp=temp->link)
  {
  printf("%d\n",temp->info);
  }
}
NODE delete_pos(int pos,NODE first)
{
	NODE prev,cur;
	int count;
	if (first==NULL || pos<=0)
	{
		printf("Invalid position\n");
		return NULL;
	}
	if (pos==1)
	{
		cur=first;
		first=first->link;
		printf("item deleted is %d\n",cur->info);
		freenode(cur);
		return first;
	}
	prev=NULL;
	cur=first;
	count=1;
	while (cur!=NULL)
	{
		if (count==pos)
		{
			break;
		}
		prev=cur;
		cur=cur->link;count++;
	}
	if (count!=pos)
	{
		printf("Invalid position\n");
		return first;
	}
	prev->link=cur->link;
	printf("item deleted is %d\n",cur->info);
	freenode(cur);
	return first;
}


void main()
{
int item,choice,pos;
NODE first=NULL;
for(;;)
{
printf("\n 1:Insert_front\n 2:Delete_front\n 3:Insert_rear\n 4:Delete_rear\n 5:insert_pos\n 6:delete at specified position\n7:display_list\n8:Exit\n");
printf("enter the choice\n");
scanf("%d",&choice);
switch(choice)
 {
  case 1:printf("enter the item at front-end\n");
	 scanf("%d",&item);
	 first=insert_front(first,item);
	 break;
  case 2:first=delete_front(first);
	 break;
  case 3:printf("enter the item at rear-end\n");
	 scanf("%d",&item);
	 first=insert_rear(first,item);
	 break;
  case 4:first=delete_rear(first);
	 break;
  case 5:printf("enter the position\n");
		 scanf("%d",&pos);
		 printf("enter the item \n");
	      scanf("%d",&item);
		 first=insert_pos(item,pos,first);
		 break;
  case 6:
  	printf("Enter the positon to delete the node\n");
  	scanf("%d",&pos);
  	
  first=delete_pos( pos,first);
 
	 break;
  case 7:display(first);
	 break;
 default:exit(0);
	 break;
 }
}
}
