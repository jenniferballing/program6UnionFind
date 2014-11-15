#include "people.h"


people::people()
{
	num = -1;
	anti = -1;
}
people::people(int n)
{
	num = n;
	anti = -1;
}
people::people(int n, int a)
{
	num = n;
	anti = a;
}
int people::getNum()
{
	return num;
}
int people::getAnti()
{
	return anti;
}
void people::setAnti(int a)
{
	anti = a;
}
void people::setNum( int n)
{
	num = n;
}

people::~people()
{
}
