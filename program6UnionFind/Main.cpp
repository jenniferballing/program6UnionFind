#include <iostream>
#include <fstream>
#include <string>
#include "people.h"
using namespace std;

void unionPeople(int name1, int name2, people arr[]);
void antiUnionPeople(int name1, int name2, people arr[]);
int findPeople(int name, people arr[]);
int main()
{
	//first three data
	int numDataSets, numStudents, numLines, lineCount=0;
	
	//initialize array
	people arr[1001];
	for (int i = 0; i < 1001; i++)
	{
		people init;// = new people();
		arr[i] = init;
	}
	
	//Initialize data
	fstream fin;
	fin.open("highschool.txt");
	fin >> numDataSets >> numStudents >> numLines;
	
	//Read directions from file
	while (lineCount <= numLines)
	{
		char direction;
		int name1, name2;
		people first, second;
		fin >> direction >> name1 >> name2;
		
		first = arr[name1];
		second = arr[name2];
		
		//answer
		if (direction == 65) 
		{
			string message=" ";
			if (first.getAnti() == name2 || second.getAnti() == name1) message = "In different schools.";
			else if (first.getAnti() !=-1 && first.getAnti() == second.getAnti()) message = "Went to the same school";
			else message = "Not sure yet.";
			cout << "Person " << name1 << " and " << name2 << ":   " << message << endl;
		}
		//different
		else if (direction == 68)
		{
			antiUnionPeople(name1, name2, arr);
		}
		lineCount++;
	}
	return 0;
}
void antiUnionPeople(int name1, int name2, people arr[])
{
	people first = arr[name1];
	people second = arr[name2];

	//if anti already set
	if (first.getAnti() > -1)
	{
		int anti = first.getAnti();
		unionPeople(name2, anti, arr);
	}
	//if anit is not set
	else first.setAnti(name2);
	
	
	//if anti already set
	if (second.getAnti() > -1)
	{
		int anti = second.getAnti();
		unionPeople(name1, anti, arr);
	}
	//if anit is not set
	else second.setAnti(name1);
	arr[name2] = second;
	arr[name1] = first;
}
void unionPeople(int name1, int name2, people arr[])
{
	int root1 = findPeople(name1, arr);
	int root2 = findPeople(name2, arr);
	int newRoot, newChild;

	if (root1 <= root2)
	{
		newRoot = root1;
		newChild = root2;
	}
	else
	{
		newRoot = root2;
		newChild = root1;
	}
	arr[newChild] = newRoot;
}
int findPeople(int name, people arr[])
{
	
	if (arr[name].getNum() == -1)return name;
	else arr[name] = findPeople(arr[name].getNum(), arr);
	return arr[name].getNum();
}