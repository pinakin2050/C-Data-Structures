#include<stdio.h>
#define P printf

int mystrcmp(char [],char []);
void main()
{
	char str1[50],str2[50];
	int res=0;
	clrscr();
	P("Enter first string:");
	scanf("%s",str1);

	P("Enter second string:");
	scanf("%s",str2);

	res=mystrcmp(str1,str2);
	if(res==1)
	{
		P("Strings are equal.\n");
	}
	else
	{
		P("Strings are unequal.");
	}
	getch();
}
int mystrcmp(char str1[],char str2[])
{
	int i=0,len1=0,len2=0;
	while(str1[i]!='\0')
	{
		++len1;
		++i;
	}

	i=0;
	while(str2[i]!='\0')
	{
		++len2;
		++i;
	}

	if(len1!=len2)
	{
		return -1;
	}
	else
	{
		while(str1[i]!='\0'&& str2[i]!='\0')
		{
			if(str1[i]!=str2[i])
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
}

