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
		char name[10];
		int age;
		float per;
	};
	struct student s[3];

	int i;
	clrscr();
	for(i=0;i<3;i++)
	{
		P("\nEnter student %d name, percentage and age:",i+1);
		scanf("%s %f %d",s[i].name, &s[i].per,&s[i].age);
	}

	for(i=0;i<3;i++)
	{
		P("\nStudent %d name, marks and percentage:\n",i+1);
		P("%s\t %0.2f\t %d\n",s[i].name,s[i].per,s[i].age);
	}
	getch();
}