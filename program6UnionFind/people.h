#ifndef PEOPLE_H
#define PEOPLE_H
class people
{
	int num;
	int anti;
public:
	people();
	people(int n);
	people(int n, int a);
	int getNum();
	int getAnti();
	void setAnti(int );
	void setNum(int );
	~people();
};

#endif