#include<stdio.h>
#define P printf

void dummmy()
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
	struct student s[3],*p;
	int i;
	clrscr();
	p=&s[0];
	for(i=0;i<3;i++)
	{
		P("\nenter name,age & height of student %d:\n",i+1);
		scanf("%s %d %f",p->name,&p->age,&p->height);
		p++;
	}
	p=&s[0];
	for(i=0;i<3;i++)
	{
		P("\nDetails of student %d\n",i+1);
		P("Name=%s\tAge=%d\tHeight=%0.2f\n",p->name,p->age,p->height);
		p++;
	}
	getch();
}