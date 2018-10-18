#include<stdio.h>
#define P printf
void mystrcpy(char[]);

void main()
{
	char str1[30];
	clrscr();
	P("Enter your string:");
	scanf("%[^\n]s",str1);
	mystrcpy(str1);
	getch();
}
void mystrcpy(char str1[])
{
	int i=0;
	char str2[30];
	for(i=0;str1[i]!='\0';++i)
	{
	   str2[i]=str1[i];
	}
	str2[i]='\0';
	P("String after copying is %s",str2);
}