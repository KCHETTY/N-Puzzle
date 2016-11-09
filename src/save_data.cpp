
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

void	save_data(t_global *g)
{
	vector<int>			str;
	unsigned long int	r = 0; 

	malloc_puzzle(g);
	while (r < g->data.size())
	{
		cout << g->data[r] << endl;
		str = line_parse(g->data[r], g->dimension);
		cout << str.size() << endl;
		for (unsigned int x = 0; x < g->dimension; x++)
		{
				g->puzzle[r][x] = str[x];
		}	
		r++;
	}

	for (unsigned int u = 0; u < g->dimension; u++)
	{
		for (unsigned int k = 0; k < g->dimension; k++)
		{
			cout << g->puzzle[u][k];
		}
		cout << endl;
	}
	cout << "The dimensions " << g->dimension << endl;
}
