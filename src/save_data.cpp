
#include "n_puzzle.h"

vector<int>	line_parse(string line, int i)
{
	vector<int>  stuff;
	string tmp = line;

	for (int z = 0; z < i; z++)
	{
		stuff.push_back(stoi(line));
		line = line.substr(line.find(" ") + 1, line.length());
	}
	return (stuff);
}

void	save_data(t_global *g)
{
	vector<int>			str;
	unsigned long int	r = 0;
	g->c_puzzle.push_back(new map_puzzle());
	g->c_puzzle[0]->malloc_puzzle(g->dimension);

	malloc_puzzle(g);
	while (r < g->data.size())
	{
		cout << g->data[r] << endl;
		str = line_parse(g->data[r], g->dimension);
		cout << str.size() << endl;
		for (unsigned int x = 0; x < g->dimension; x++)
		{
				g->puzzle[r][x] = str[x];
				g->c_puzzle[0]->set_puzzle(x, r, str[x]);
		}	
		r++;
	}

	for (unsigned int u = 0; u < g->dimension; u++)
	{
		for (unsigned int k = 0; k < g->dimension; k++)
		{
			cout << g->c_puzzle[0]->get_puzzle(k, u);
		}
		cout << endl;
	}
	cout << "The dimensions " << g->dimension << endl;
}
