#include<stdio.h>
#define P printf
void main()
{
	char str1[30],str2[30],*p1,*p2;
	int i=0;
	clrscr();
	p1=str1;
	p2=str2;
	P("Enter your string:");
	scanf("%[^\n]s",p1);
	while(p1[i]!='\0')
	{
		p2[i]=p1[i];
		i++;
	}
	P("\nOriginal string:%s",p1);
	P("\nCopied string:%s",p2);
	getch();
}