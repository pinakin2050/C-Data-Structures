#include<stdio.h>
#define pf printf

struct node
{
	int data;
	struct node *llink,*rlink;
};
struct node *first=NULL;

void insert_front()
{
	struct node *p;
	p=malloc(sizeof(struct node));
	//int elem;
	pf("Enter element:");
	scanf("%d",&p->data);
	p->llink=NULL;
	p->rlink=NULL;

	if(first==NULL)
	{
		first=p;
	}
	else
	{
		p->rlink=first;
		first->llink=p;
		first=p;
	}
}

void insert_rear()
{
	struct node *p,*temp;
	p=malloc(sizeof(struct node));
	//int elem;
	pf("Enter element:");
	scanf("%d",&p->data);
	p->llink=NULL;
	p->rlink=NULL;

	if(first==NULL)
	{
		first=p;
	}
	else
	{
		temp=first;
		while(temp->rlink!=NULL)
		{
			temp=temp->rlink;
		}
		temp->rlink=p;
		p->llink=temp;
	}
}

void delet_front()
{
	struct node *x;
	if(first==NULL)
	{
		pf("\nDeletion not possible.\n");
	}
	else if(first->rlink==NULL)
	{
		pf("\nElement deleted is %d\n",first->data);
		free(first);
		first=NULL;
	}
	else
	{
		x=first;
		pf("\nElement deleted is %d\n",first->data);
		first=first->rlink;
		free(x);
		x=NULL;
	}
}

void delet_rear()
{
	struct node *temp;
	if(first==NULL)
	{
		pf("\nDeletion not possible\n");
	}
	else if(first->rlink==NULL)
	{
		pf("\nElement deleted is %d\n",first->data);
		free(first);
		first=NULL;
	}
	else
	{
		temp=first;
		while(temp->rlink->rlink!=NULL)
		{
			temp=temp->rlink;
		}
		pf("\nElement deleted is %d\n",temp->rlink->data);
		free(temp->rlink);
		temp->rlink=NULL;
	}
}

void display()
{
	struct node *temp;

	if(first==NULL)
	{
		pf("\nDisplay not possible.\n");
	}
	else if(first->rlink==NULL)
	{
		pf("%d\t",first->data);
		pf("\n");
	}
	else
	{
		temp=first;
		while(temp!=NULL)
		{
			pf("%d\t",temp->data);
			temp=temp->rlink;
		}
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
