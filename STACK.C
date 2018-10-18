#include<stdio.h>
#define P printf
int size=0;
int top=-1;
void push(int s[])
{       int elem=0;
	if(top==size-1)
	{
		P("Push not possible!\n");
	}
	else
	{
		P("Enter element:");
		scanf("%d",&elem);
		++top;
		s[top]=elem;
	}
}
void pop(int s[])
{
	if(top==-1)
	{
		P("Pop not possible!\n");
	}
	else
	{
		P("Popped element is %d\n",s[top]);
		--top;
	}
}
void display(int s[])
{       int i;
	if(top==-1)
	{
		P("Display not possible!!");
	}
	for(i=top;i>=0;i--)
	{
		P("\t%d\n",s[i]);
	}
}
void main()
{
	int *s,ch;
	clrscr();
	P("Enter size of the stack:");
	scanf("%d",&size);
	s=malloc(sizeof(size));
    while(1)
    {
	P("\nPress 1 to PUSH!\n");
	P("Press 2 to POP!\n");
	P("Press 3 to DISPLAY!\n");
	P("Press any key to stop\n");
	P("Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	   case 1:push(s);
		  break;

	   case 2:pop(s);
		  break;

	   case 3:display(s);
		  break;

	   default:exit(0);
		  break;
	}
    }
}