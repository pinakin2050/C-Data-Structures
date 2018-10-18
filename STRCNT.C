#include<stdio.h>
#define P printf

void dummy()
{
	float f,*fp;
	fp=&f;
}

void main()
{
	struct student
	{
		char name[15];
		int age;
		float height;
	};
	struct student *s;

	int i,n;
	clrscr();
	P("Enter size of Structure:");
	scanf("%d",&n);
	s=malloc(sizeof(n));
	for(i=0;i<n;i++)
	{
		P("\nEnter name,age & height of student %d:",i+1);
		scanf("%s %d %f",s[i].name,&s[i].age,&s[i].height);
	}

	for(i=0;i<n;i++)
	{
		P("\nName,age & height of student %d:\n",i+1);
		P("%s\t %d\t %0.2f\n",s[i].name,s[i].age,s[i].height);
	}
	getch();
}