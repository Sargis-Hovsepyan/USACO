/*
ID: sargish1
LANG: C++
PROG: gift1
*/

#include <iostream>
#include <fstream>
#include <string>

using std::string;

typedef struct	s_Person 
{
	string			name;
	int				balance;
}				Person;

int	find(Person *ppl, int len, string name)
{
	for (int i = 0; i < len; i++)
	{
		if(ppl[i].name == name)
			return (i);
	}
	return (-1);
}

int	main()
{
	int				n;
	Person			*people;
	std::ifstream	inFile("gift1.in", std::ios::in);
	std::ofstream	outFile("gift1.out", std::ios::out);

	inFile >> n;
	people = new Person[n];
	
	/* Initializing names */
	for (int i = 0; i < n; i++)
		inFile >> people[i].name;

	for (int i = 0; i < n; i++)
	{
		int		giver, reciver;
		int		amnt, f_num;
		string	name;
		
		inFile >> name >> amnt >> f_num;
		giver = find(people, n, name);
		for (int j = 0; j < f_num; j++)
		{
			inFile >> name;
			reciver = find(people, n, name);
			people[reciver].balance += amnt / f_num;
			people[giver].balance -= amnt / f_num;
		}
	}
	for (int i = 0; i < n; i++)
		outFile << people[i].name <<  " " << people[i].balance << std::endl;
	delete[] people;
	exit(0);
}
