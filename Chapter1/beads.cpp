/*
ID:		sargish1
LANG:	C++
PROG:	beads
*/

#include <iostream>
#include <fstream>
using namespace std;

int		N;
string	s;

int	main()
{
	ifstream	fin("beads.in");
	ofstream	fout("beads.out");
	int			state;
	int			curr = 0;
	int			max = 0;
	char		c;

	fin >> N >> s;
	s = s + s;
	for (int i = 0; i < N; i++)
	{
		c = static_cast<char>(s[i]);
		state = c == 'w' ? 0 : 1;
	 	curr = 0;

		int j = i;
		while (state <= 2)
		{
			while (j < N + i && (s[j] == c || s[j] == 'w'))
			{
				curr++;
				j++;
			}
			state++;
			if (c == s[j]) break;
			c = s[j];
		}
		if (curr > max)
			max = curr;
	}

	fout << max << endl;
	return (0);
}
