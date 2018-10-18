#include<stdio.h>
#define P printf
void main()
{
	char str1[20],str2[20];
	int res=0;
	clrscr();
	P("Enter a string:");
	scanf("%s",str1);
	res = pelindrome(str1,str2);
	if(res==1)
	{
		P("String is pelindrome.");
	}
	else
	{
		P("String is not Pelindrome.");
	}
	getch();
}
int pelindrome(char str1[],char str2[])
{
	int i=0,len=0;
	while(str1[i]!='\0')
	{
		++len;
		++i;
	}

	i=0;
	while(str1[i]!='\0')
	{
		str2[len-i-1]=str1[i];
		++i;
	}

	i=0;
	while(str1[i]!='\0' && str2[i]!='\0')
	{
		if(str2[i]!=str1[i])
		{
			return -1;
		}
		else
		{
			++i;
		}
	}
	return 1;
}