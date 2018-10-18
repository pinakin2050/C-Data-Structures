#include<stdio.h>
#define P printf
int mystrlen(char []);
void main()
{
	int cnt=0;
	char str[10];
	clrscr();
	P("Enter your string:");
	scanf("%[^\n]s",str);
	cnt = mystrlen(str);
	P("String length is %d",cnt);
	getch();
}
int mystrlen(char str[])
{
	int i=0,cnt=0;
	while(str[i]!='\0')
	{
	   ++cnt;
	   ++i;
	}
	return cnt;
}
