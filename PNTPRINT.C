#include<stdio.h>
#define P printf
void main()
{
	char str[30];
	int i=0;
	char *p;
	clrscr();
	P("Enter your string:");
	scanf("%[^\n]s",str);

	P("\nPrinting using str[i]\n");
	while(str[i]!='\0')
	{
		P("%c",str[i]);
		i++;
	}

	i=0;
	P("\n\nPrinting using *(str+i)\n");
	while(*(str+i)!='\0')
	{
		P("%c",*(str+i));
		i++;
	}

	i=0;
	p=&str[0];
	P("\n\nPrinting using p[i]\n");
	while(p[i]!='\0')
	{
		P("%c",p[i]);
		i++;
	}

	i=0;
	p=str;
	P("\n\nPrinting using *(p+i)\n");
	while(*(p+i)!='\0')
	{
		P("%c",*(p+i));
		i++;
	}
	getch();
}