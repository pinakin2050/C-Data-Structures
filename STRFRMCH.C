#include<stdio.h>
#define P printf
void main()
{
	char str[20],ch,*ptr;
	clrscr();
	P("Enter the character from where you want to print the string:");
	scanf("%c",&ch);
	P("\nEnter your string:");
	scanf("%s",str);
	ptr=str;
	while(*ptr!=ch)
	{
		++ptr;
	}

	/* This will cause erro cuz ary name is a constant ptr & should not be altered
	while(*str!=ch)
	{
		++str;
	}   */

	P("\nString from the given character:%s",ptr);
	getch();
}