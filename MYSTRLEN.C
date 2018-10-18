#include<stdio.h>
#define P printf
char str[10];
void mystrlen();
void main()
{
	clrscr();
	P("Enter your string:");
	scanf("%s",str);
	mystrlen();
	getch();
}

void mystrlen()
{       int i=0,cnt=0;
	while(str[i]!='\0')
	{
	  ++cnt;
	  ++i;
	}
	P("String length is %d",cnt);
}