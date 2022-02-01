/*
ID: sargish1
LANG: C++
PROG: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int	convert(string name)
{
	int	i;
	int	prod;

	i = 0;
	prod = 1;
	while (name[i])
	{
		prod *= name[i] - 64;
		i++;
	}
	return (prod);
}

int	main()
{
	ifstream	inFile("ride.in", ios::in);
	ofstream	outFile("ride.out", ios::out);
	string		cometName;
	string		groupName;
	int			cometNum;
	int			groupNum;

	if (!inFile || !outFile)
	{
		cerr << "Error: Could not open the file!" << endl;
		exit(0);
	}
	inFile >> cometName;
	inFile >> groupName;

	cometNum = convert(cometName) % 47;
	groupNum = convert(groupName) % 47;
	
	if (cometNum == groupNum)
		outFile << "GO" << endl;
	else
		outFile << "STAY" << endl;
	return (0);
}

