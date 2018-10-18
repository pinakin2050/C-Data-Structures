#include<stdio.h>
#define P printf
void mystrcpy();
char str1[10],str2[10];

void main()
{
	clrscr();
	P("Enter your string:");
	scanf("%[^\n]s",str1);
	mystrcpy();
	getch();
}
void mystrcpy()
{
	int i=0;
	while(str1[i]!='\0')
	{
	  str2[i] = str1[i];
	  ++i;
	}
	str2[i]='\0';
	P("String after copying is %s",str2);

}