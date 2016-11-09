
#include "n_puzzle.h"

vector<int>	line_parse(string line, int i)
{
	vector<int>  stuff;
	string tmp = line;

	for (int z = 0; z < i; z++)
	{
		cout << "HI  " << line  << endl;
		stuff.push_back(stoi(line));
		line = line.substr(line.find(" ") + 1, line.length());
		cout << "NEW " << line << endl; 
	}
	for (int s = 0; s < i; s++)
		cout << "fjhajdfb " << stuff[s] << endl;
	return (stuff);
}

void	save_data(string file, t_global *g)
{
	string		line;
	ifstream	input(file);
	vector<int> str;
	int				count = 0;
	int r = 0; 

	while (getline(input, line).good())
	{
		cout << line << endl;
		if (g->dimension == 0)
			g->dimension = stoi(line);
		else if (g->dimension != 0 && g->malloc_flag == 0)
		{
			malloc_puzzle(g);
			g->malloc_flag = 1;	
		}
		if (r != 0)
			str = line_parse(line, g->dimension);
		cout << str.size() << endl;
		if (str.size() == (unsigned int)g->dimension)
		{
			for (int y = 0; y < g->dimension; y++)
			{
				g->puzzle[count][y] = str[y];

			}	
			count++;
		}
		r++;
	}

	for (int u = 0; u < g->dimension; u++)
	{
		for (int k = 0; k < g->dimension; k++)
		{
			cout << g->puzzle[u][k];
		}
		cout << endl;
	}
	cout << "The dimensions " << g->dimension << endl;
}
