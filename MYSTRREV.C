#include<stdio.h>
#define P printf
void mystrrev(char []);
void main()
{
	char str1[30];
	clrscr();
	P("Enter a string:");
	scanf("%[^\n]s",str1);
	mystrrev(str1);
	getch();
}
void mystrrev(char str1[])
{
	char str2[30];
	int i=0,len=0;
	while(str1[i]!='\0')
	{
		++len;
		++i;
	}
	i=0;
	while(str1[i]!='\0')
	{
		str2[len-1-i]=str1[i];
		++i;
	}
	str2[i]='\0';
	P("\nOriginal String: %s",str1);
	P("\nReversed string: %s",str2);
}