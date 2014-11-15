#ifndef PEOPLE_H
#define PEOPLE_H
class people
{
	int root;
	int anti;
public:
	people();
	people(int r);
	people(int r, int a);
	int getRoot();
	int getAnti();
	void setAnti(int );
	void setRoot(int );
	~people();
};

#endif