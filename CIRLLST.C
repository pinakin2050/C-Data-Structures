#include<stdio.h>
#define pf printf

struct node
{
	int data;
	struct node *link;
};
struct node *first=NULL;

void insert_front()
{
	struct node *p,*temp;
	p=malloc(sizeof(struct node));
	pf("\nEnter element:");
	scanf("%d",&p->data);
	p->link=NULL;

	if(first==NULL)
	{
		first=p;
		first->link=first;
	}
	else
	{
	   temp=first;
	   while(temp->link!=first)
	   {
		temp=temp->link;
	   }
	   p->link=first;
	   first=p;
	   temp->link=first;
	}
}

void insert_rear()
{
	struct node *p,*temp;
	p=malloc(sizeof(struct node));
	pf("\nEnter element:");
	scanf("%d",&p->data);
	p->link=NULL;

	if(first==NULL)
	{
		first=p;
		first->link=first;
	}
	else
	{
		temp=first;
		while(temp->link!=first)
		{
			temp=temp->link;
		}
		temp->link=p;
		p->link=first;
	}
}

void delet_front()
{
	struct node *temp,*x;
	if(first==NULL)
	{
		pf("\nDeletion not possible.\n");
	}
	else if(first->link==first)
	{
		pf("\nElement deleted is %d\n",first->data);
		free(first);
		first=NULL;
	}
	else
	{
		pf("\nElement deleted is %d\n",first->data);
		x=first;
		temp=first;
		while(temp->link!=first)
		{
			temp=temp->link;
		}
		first=first->link;
		temp->link=first;
		free(x);
		x=NULL;
	}
}

void delet_rear()
{
	struct node *temp;
	if(first==NULL)
	{
		pf("\nDeletion not possible.\n");
	}
	else if(first->link==first)
	{
		pf("\nElement deleted is %d\n",first->data);
		free(first);
		first=NULL;
	}
	else
	{
		temp=first;
		while(temp->link->link!=first)
		{
			temp=temp->link;
		}
		pf("\nElement deleted is %d\n",temp->link->data);
		free(temp->link);
		temp->link=first;
	}
}

void display()
{
	struct node *temp;
	if(first==NULL)
	{
		pf("\nDisplay not possible.\n");
	}
	else if(first->link==NULL)
	{
		pf("%d\n\n",first->data);
	}
	else
	{       temp=first;
		while(temp->link!=first)
		{
			pf("%d\t",temp->data);
			temp=temp->link;
		}
		pf("%d\t",temp->data);
	}
}

void main()
{
	int ch;
	clrscr();

	for( ; ; )
	{
		pf("\nPress 1 to insert at front.");
		pf("\nPress 2 to insert at rear.");
		pf("\nPress 3 to delete at front.");
		pf("\nPress 4 to delete at rear.");
		pf("\nPress 5 to display.");
		pf("\nPress 6 to stop.");
		pf("\nEnter your choice:");
		scanf("%d",&ch);
		pf("\n");

		switch(ch)
		{
			case 1:insert_front();
			       break;

			case 2:insert_rear();
			       break;

			case 3:delet_front();
			       break;

			case 4:delet_rear();
			       break;

			case 5:display();
			       break;

			default:exit(0);
		}
	}
}

