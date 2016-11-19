
#include "n_puzzle.h"

void	get_blank(int *x, int *y, t_global *g, int val)
{
	for (int i = 0; i < (int)g->dimension; i++)
	{
		for (int j = 0; j < (int)g->dimension; j++)
		{
			if (g->c_puzzle[val]->get_puzzle(j, i) == 0)
			{
				*x = j;
				*y = i;
			}
		}
	}
}

void create_array(t_global *g, int pos)
{
	for (int y = 0; y < (int)g->dimension; y++)
	{
		for (int x = 0; x < (int)g->dimension; x++)
		{
			g->puzzle[y][x] = g->c_puzzle[pos]->get_puzzle(x, y);
		}
	}
}

void  get_val(int *x, int *y, t_global *g, int val)
{
	for (int i = 0; i < (int)g->dimension; i++)
	{
		for (int j = 0; j < (int)g->dimension; j++)
		{
			if ((g->mock_puzzle[i][j] == val) && (val != 0))
			{
				*x = j;
				*y = i;
			}
		}
	}
}

void create_array_2(t_global *g, int pos)
{
	for (int y = 0; y < (int)g->dimension; y++)
	{
		for (int x = 0; x < (int)g->dimension; x++)
		{
			g->c_puzzle[g->c_puzzle.size() - 1]->
				set_puzzle(x, y, g->c_puzzle[pos]->get_puzzle(x, y));
		}
	}
}

int	calc_dist(int x, int y, int x2, int y2, t_global *g)
{
	if (strcmp(g->heuristic, "E") == 0)
		return (ceil(sqrt(pow(x - x2, 2) + pow(y - y2, 2))));
	else if (strcmp(g->heuristic, "H") == 0)
	{
		if (((abs((x - x2) + (y - y2)))) != 0)
			return (1);
		return (0);
	}
	return ((abs((x - x2) + (y - y2))));
}

int	do_calc(t_global *g, int x, int y, int move, int pos)
{

	int tmp = 0;
	create_array(g, pos);

	if (move == 0)
	{
		tmp = g->puzzle[y][x];
		g->puzzle[y][x + 1] = tmp;
		g->puzzle[y][x] = 0;
	}
	if (move == 1)
	{
		tmp = g->puzzle[y][x];
		g->puzzle[y][x - 1] = tmp;
		g->puzzle[y][x] = 0;
	}
	if (move == 2)
	{
		tmp = g->puzzle[y][x];
		g->puzzle[y + 1][x] = tmp;
		g->puzzle[y][x] = 0;
	}
	if (move == 3)
	{
		tmp = g->puzzle[y][x];
		g->puzzle[y - 1][x] = tmp;
		g->puzzle[y][x] = 0;
	}

	cout << "THE RE WRITEN ARRAY" << endl;
	for (int i = 0; i < (int)g->dimension; i++)
	{
		for (int j = 0; j < (int)g->dimension; j++)
		{
			cout << g->puzzle[i][j] << " ";
		}
		cout << endl;
	}

	int tmp_x;
	int tmp_y;
	int hey = 0;

	for (int k = 0; k < (int)g->dimension; k++)
	{
		for (int m = 0; m < (int)g->dimension; m++)
		{
			if (g->puzzle[k][m] != 0)
			{
				get_val(&tmp_x, &tmp_y, g, g->puzzle[k][m]);
				hey += calc_dist(m, k, tmp_x, tmp_y, g);
				cout << "ufagewufgaur " << hey << endl;
			}

		}
	}

return (hey);

}

void		heuristic(t_global *g)
{
	//vector<int> move;
	int tmp_x;
	int tmp_y;
	int dist; // = (g->dimension * 1000);
	int dist_tmp = (g->dimension * 1000) + 1;
	int powo = g->c_puzzle.size();

	for (int i = 0; i < powo; i++)
	{
		dist = (g->dimension * 1000);
		cout << "IM IIIIIIIIIIIIIIIIIIIII " << i << endl;
		//cout << "XXXXXXXXXXX  " << tmp_x << "YYYYYYYYYY " << tmp_y << endl;
		//cout << "PREV_X  " << g->prev_move[0] << "  PREV_Y  " << g->prev_move[1] << endl;
		get_blank(&tmp_x, &tmp_y, g, i);
		cout << "XXXXXXXXXXX2222222222  " << tmp_x << "YYYYYYYYYY2222222 " << tmp_y << endl;
		cout << "movevevevevev x " << g->prev_move[i][0] << " moveveveveve y " << g->prev_move[i][1] << endl;
		for (int t = 0; t < 4; t++)
		{
			if ((t == 0) && ((tmp_x - 1) > -1))
			{
				if (tmp_x - 1 != g->prev_move[i][0])
				{
					//cout << "_______________x - 1____________________" << endl;
					dist_tmp = do_calc(g, tmp_x - 1, tmp_y, t, i);
				}
			}
			else if ((t == 1) && ((tmp_x + 1) < (int)g->dimension))
			{
				if (tmp_x + 1 != g->prev_move[i][0])
				{
					//cout << "_______________x + 1____________________" << endl;
					dist_tmp = do_calc(g, tmp_x + 1, tmp_y, t, i);
				}
			}
			else if ((t == 2) && (tmp_y - 1 > -1))
			{
				if (tmp_y - 1 != g->prev_move[i][1])
				{
					//cout << "_______________y - 1_____________________" << endl;
					dist_tmp = do_calc(g, tmp_x, tmp_y - 1, t, i);
				}
			}
			else if ((t == 3) && (tmp_y + 1 < (int)g->dimension))
			{
				if (tmp_y + 1 != g->prev_move[i][1])
				{
					//cout << "_______________y + 1______________________" << endl;
					dist_tmp = do_calc(g, tmp_x, tmp_y + 1, t, i);
				}
			}

			cout << "distance " << dist_tmp << endl;
			if (dist > dist_tmp)
			{
				g->move[i] = t;
				dist = dist_tmp;
			}
			else if (dist == dist_tmp)
			{
				g->move.push_back(t);
				g->c_puzzle.push_back(new map_puzzle());
				g->c_puzzle[g->c_puzzle.size() - 1]->malloc_puzzle(g->dimension);
				create_array_2(g, i);
			}
			dist_tmp = (g->dimension * 1000 + 1);
		}
		//for (int o = 0; o < (int)g->move.size(); o++)
		//cout << "HEY IM MOVE " << g->move[0] << endl;
	}
}
