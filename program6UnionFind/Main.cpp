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
	int numDataSets, numStudents, numLines, lineCount, dataSetCount = 0;
	fstream fin;
	fin.open("highschool.txt");
	fin >> numDataSets;
	while (dataSetCount <numDataSets)
	{
		//initialize array
		people arr[1001];
		for (int i = 0; i < 1001; i++)
		{
			people init;
			arr[i] = init;
		}
		//Initialize data	
		fin >> numStudents >> numLines;
		lineCount = 0;
		//Read directions from file
		while (lineCount < numLines)
		{
			char direction;
			int name1, name2;
			fin >> direction >> name1 >> name2;
			people one(name1), two(name2);
			if (one.getAnti() == -1)one.setAnti(arr[name1].getAnti());
			if (two.getAnti() == -1)two.setAnti(arr[name2].getAnti());


			//answer
			if (direction == 65)
			{
				string message = " ";
				int root1 = findPeople(one.getRoot(), arr);
				int root2 = findPeople(two.getRoot(), arr);
				if (one.getRoot() != -1 && root1 == root2)  message = "Went to the same school";
				else
				{
					int rootAnti1 = arr[root1].getAnti();
					int rootAnti2 = arr[root2].getAnti();
					if (rootAnti1 == root2 || rootAnti2 == root1) message = "In different schools.";
					else message = "Not sure yet.";
				}
				cout << "Person " << name1 << " and " << name2 << ":   " << message << endl << endl;
			}
			//different
			else if (direction == 68)
			{ 
				if (one.getAnti() != -1 && one.getAnti() == two.getAnti())
				cout << "Different " << name1 << " " << name2 << " :" << " BAD DATA." << endl<<endl;

				else antiUnionPeople(name1, name2, arr);
			}lineCount++;			
		}dataSetCount++;
	}fin.close();
	return 0;
}
void antiUnionPeople(int name1, int name2, people arr[])
{
	//get the roots of the two
	int root1 = findPeople(name1, arr);
	arr[name1].setRoot(root1);
	int root2 = findPeople(name2, arr);
	arr[name2].setRoot(root2);


	//if anti already set
	if (arr[name1].getAnti() > -1)
	{
		int anti = arr[name1].getAnti();
		//if (arr[anti].getRoot != -1)
		unionPeople(name2, anti, arr);
	}
	//if anit is not set
	else arr[name1].setAnti(root2);
	
	
	//if anti already set
	if (arr[name2].getAnti() > -1)
	{
		int anti = arr[name2].getAnti();
		unionPeople(name1, anti, arr);
	}
	//if anti is not set
	else arr[name2].setAnti(root1);
}
void unionPeople(int name1, int name2, people arr[])
{
	int root1 = findPeople(name1, arr);
	arr[name1].setRoot(root1);
	int root2 = findPeople(name2, arr);
	arr[name2].setRoot(root2);
	
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
	arr[newChild].setRoot(newRoot);

}
int findPeople(int name, people arr[])
{	
	if (arr[name].getRoot() == -1 || arr[name].getRoot() == name)return name;
	else return findPeople(arr[name].getRoot(), arr);
}