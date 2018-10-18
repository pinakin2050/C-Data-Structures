#include<stdio.h>
#define P printf
int r=-1,f=0,count=0;

void insert(int q[],int size)
{
	int elem;
	if(count==size)
	{
		P("\n\nInsertion not possible!!\n\n");
	}
	else
	{
		P("Enter your element:");
		scanf("%d",&elem);
		r=(r+1)%size;
		q[r]=elem;
		++count;
	}
}

void delet(int q[],int size)
{
	if(count==0)
	{
		P("\n\nDeletion not possible\n\n");
	}
	else
	{
		P("\n\nDeleted element is %d\n\n",q[f]);
		f=(f+1)%size;
		--count;
	}
}

void display(int q[],int size)
{
	int i,f1;
	f1=f;
	if(count==0)
	{
		P("\n\nDisplay not possible!!\n\n");
	}
	else
	{
		P("\n\n");
		for(i=1;i<=count;i++)
		{
			P("%d\t",q[f1]);
			f1=(f1+1)%size;
		}
		P("\n\n");
	}
}

void main()
{
	int *q,size,ch;
	clrscr();
	P("Enter the size of queue:");
	scanf("%d",&size);
	q = malloc(sizeof(size));
   for( ; ; )
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