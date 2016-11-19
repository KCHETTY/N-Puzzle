
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

int		get_size()
{
		int size = 0;
		string input;

		cout << "Enter puzzle dimensions (3 - 100): " << endl;
		cin >> size;

		if (size == 0)
			return (3);
		else if (size < 0)
			size *= -1;
		
		if (size < 101 && size > 2)
			return (size);
		return (3);
}

void	swaps(int swap, t_global *g)
{
	int s;
	int rx1;
	int rx2;
	int ry1;
	int ry2;
	int temp;
	struct timeval tp;
	long int ms; // = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	s = 0;
	while (s < swap)
	{
		 gettimeofday(&tp, NULL);
		 ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
		 srand(ms);
		 rx1 = rand() % g->dimension;
		 rx2 = rand() % g->dimension;
		 ry1 = rand() % g->dimension;
		 ry2 = rand() % g->dimension;
		 temp = g->puzzle[ry1][rx1];
		 g->puzzle[ry1][rx1] = g->puzzle[ry2][rx2];
		 g->puzzle[ry2][rx2] = temp;
		 s++;
	}

}

void	map_gen(t_global *g)
{
	int puzzle_max;
	int num;
	int x;
	int y;

	g->dimension = get_size();
	g->c_puzzle[0]->malloc_puzzle(g->dimension);
	malloc_puzzle(g);
	puzzle_max = (g->dimension * g->dimension) - 1;
	y = 0;
	num = 0;
	while (y < (int)g->dimension && num < puzzle_max)
	{
		 x = 0;
		 for (int x = 0; x < (int)g->dimension; x++)
				g->puzzle[y][x] = num++;
	}
	swaps(1000000, g);
	
	for (y = 0; y < (int)g->dimension; y++)
	{
		for (x = 0; x < (int)g->dimension; x++)
			g->c_puzzle[0]->set_puzzle(x, y, g->puzzle[y][x]);
	}
	
}

void	save_data(t_global *g)
{
	vector<int>			str;
	unsigned long int	r = 0;
	g->c_puzzle.push_back(new map_puzzle());
	//g->c_puzzle[0]->malloc_puzzle(g->dimension);

	//malloc_puzzle(g);
	if (g->data.size() != 0)
	{
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
	}
	else
		map_gen(g);

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
