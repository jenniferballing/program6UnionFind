#include "people.h"


people::people()
{
	root = -1;
	anti = -1;
}
people::people(int n)
{
	root = n;
	anti = -1;
}
people::people(int n, int a)
{
	root = n;
	anti = a;
}
int people::getRoot()
{
	return root;
}
int people::getAnti()
{
	return anti;
}
void people::setAnti(int a)
{
	anti = a;
}
void people::setRoot( int n)
{
	root = n;
}

people::~people()
{
}
