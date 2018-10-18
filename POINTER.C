#include<stdio.h>
#define P printf
void main()
{
	int a=7;
	int *p;  //creation of a pointer(Dangling)
	clrscr();
	p=&a;    //Assigning the pointer to a specifc variable and making
	P("%d",*p); //De-referencing the pointer and hence access the content of the address
	getch();
}