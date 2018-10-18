#include<stdio.h>
#define P printf
int r=-1,f=0;

void insert(int q[],int size)
{
	int elem;
	if(r==size-1)
	{
		P("\n\nInsertion not possible!!\n\n");
	}
	else
	{
		P("Enter element:");
		scanf("%d",&elem);
		++r;
		q[r]=elem;
	}
}

void delet(int q[],int size)
{
	if(r==-1||f>r)
	{
		P("\n\nDeletion not possible!!\n\n");
	}
	else
	{
		P("\n\nDeleted element is %d\n\n",q[f]);
		++f;
	}
}

void display(int q[],int size)
{
	int i=0;
	if(r==-1||f>r)
	{
		P("\n\nDisplay not possible!!!\n\n");
	}
	else
	{
		P("\n\n");
		for(i=f;i<=r;i++)
		{
			P("%d\t",q[i]);
		}
		P("\n\n");
	}
}

void main()
{
	int *q,ch,size=0;
	clrscr();
	P("Enter size of the queue:");
	scanf("%d",&size);
	q=malloc(sizeof(size));
    while(1)
    {
	P("\nPress 1 for Insertion\n");
	P("Press 2 for Deletion\n");
	P("Press 3 for Display\n");
	P("Press 5 to exit\n");
	P("Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:insert(q,size);
		       break;
		case 2:delet(q,size);
		       break;
		case 3:display(q,size);
		       break;
		default:exit();

	}
    }
}