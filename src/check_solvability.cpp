/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solvability.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:43 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/19 08:47:45 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	write_array(t_global *g)
{
	for (unsigned int i = 0; i < (g->dimension * g->dimension); i++)
		g->dummy.push_back(i);

	for (unsigned int y = 0; y < g->dimension; y++)	
	{
		for (unsigned int x = 0; x < g->dimension; x++)
		{
			for (unsigned int r = 0; r < (g->dimension * g->dimension); r++)
			{
				if (g->c_puzzle[0]->get_puzzle(x, y) == g->dummy[r] && 
						g->dummy[r] != (int)(g->dimension * g->dimension + 1))
				{
					cout << "TEST " << endl;
					g->dummy[r] = (g->dimension * g->dimension + 1);
				}
			}
		}
	}

	for (unsigned int k = 0; k < (g->dimension * g->dimension); k++)
	{
		if (g->dummy[k] != (int)(g->dimension * g->dimension + 1))
			error();
	}
}

int spiral(int w, int h, int x, int y)
{
	return y ? w + spiral(h - 1, w, y - 1, w - x - 1) : x;
}

int	t_distance(t_global *g, int x, int y)
{
	cout << "XXXXX " << g->center_x << " " << "YYYYY " << g->center_y << endl;
	return (sqrt(pow((x - g->center_x), 2) + pow((y - g->center_y), 2)));
}

void	reshuffle_array(t_global *g)
{
	int tmp_x;
	int tmp_y;

	for (unsigned int y = 0; y < g->dimension; y++)
	{
		for (unsigned int x = 0; x < g->dimension; x++)
		{
			if (g->c_puzzle[0]->get_puzzle(x, y) == 0)
			{
				tmp_x = x;
				tmp_y = y;
			}
		}
	}

	int dist = g->dimension;
	int dist_tmp;;
	int move = -1;
	int tmp = 0;

	cout << "CENTER X " << g->center_x << "   " << "CENTER Y " << g->center_y << endl;	
	while (1)
	{
		if ((tmp_x == g->center_x) && (tmp_y == g->center_y))
			break;
		for (int t = 0; t < 4; t++)
		{
			if (t == 0 && tmp_x - 1 != -1)
				dist_tmp = t_distance(g, tmp_x - 1, tmp_y);
			if (t == 1 && tmp_x + 1 != (int)g->dimension)
				dist_tmp = t_distance(g, tmp_x + 1, tmp_y);			
			if (t == 2 && tmp_y - 1 != -1)
				dist_tmp = t_distance(g, tmp_x, tmp_y - 1);
			if (t == 3 && tmp_y + 1 != (int)g->dimension)
				dist_tmp = t_distance(g, tmp_x, tmp_y + 1);
			cout << "distance " << dist_tmp << endl;
			if (dist > dist_tmp)
			{
				move = t;
				dist = dist_tmp;
			}
		} 

		dist = g->dimension;
		if (dist == 0)
			break ;
		if (move == 0)
		{
			tmp = g->puzzle[tmp_y][tmp_x - 1];
			g->puzzle[tmp_y][tmp_x] = tmp;
			tmp_x -= 1;
			g->puzzle[tmp_y][tmp_x] = 0;
		}
		if (move == 1)
		{
			tmp = g->puzzle[tmp_y][tmp_x + 1];
			g->puzzle[tmp_y][tmp_x] = tmp;
			tmp_x += 1;
			g->puzzle[tmp_y][tmp_x] = 0;
		}
		if (move == 2)
		{
			tmp = g->puzzle[tmp_y - 1][tmp_x];
			g->puzzle[tmp_y][tmp_x] = tmp;
			tmp_y -= 1;
			g->puzzle[tmp_y][tmp_x] = 0;
		}
		if (move == 3)
		{
			tmp = g->puzzle[tmp_y + 1][tmp_x];
			g->puzzle[tmp_y][tmp_x] = tmp;
			tmp_y += 1;
			g->puzzle[tmp_y][tmp_x] = 0;
		}
		cout << "TMP_X " << tmp_x << "    "  << "TNP_Y "  << tmp_y << endl;	
	}

	for (unsigned int y = 0; y < g->dimension; y++)
	{
		for (unsigned int x = 0; x < g->dimension; x++)
		{
			cout << g->puzzle[y][x] << " ";
		}
		cout << endl;
	}

	cout << "move " << move << endl;
}

void	validate_solvability(t_global *g)
{
	int i = 0;
	float j = (g->dimension / 2.0);

	g->mock_puzzle = (int **)malloc(sizeof(int *) * g->dimension + 1);
	for (unsigned int i = 0; i < g->dimension; i++)
		g->mock_puzzle[i] = (int *)malloc(sizeof(int) * g->dimension);

	/*	g->mock_puzzle[0][0] = 1;
		g->mock_puzzle[0][g->dimension - 1] = g->dimension;
		g->mock_puzzle[g->dimension - 1][g->dimension - 1] = g->dimension + 
		(g->dimension - 1);
		g->mock_puzzle[g->dimension - 1][0] = (g->dimension + (g->dimension - 1)) + 
		(g->dimension - 1);
		*/ 

	int w = (int)g->dimension, h = (int)g->dimension;

	for (int u = 0; u < h; u++) 
	{
		for (int j = 0; j < w; j++)
			g->mock_puzzle[u][j] = spiral(w, h, j, u) + 1;
	}

	cout << "JJJJJJJJJJJJJJJJJ " << j << endl;
	if ((j -  (int)j) > 0.0)
	{
		g->center_x = (int)j;
		g->center_y = (int)j;
		g->mock_puzzle[(int)j][(int)j] = 0;
	}
	else
	{
		g->center_x = (int)j - 1;
		g->center_y = (int)j;
		g->mock_puzzle[(int)j][(int)j - 1] = 0;
	}

	for (unsigned int y = 0; y < g->dimension; y++)
	{
		for (unsigned int x = 0; x < g->dimension; x++)
		{
			i++;
			cout << g->mock_puzzle[y][x] << " ";
		}
		cout << endl;
	}

	cout << i << endl;
}

void	yes(t_global *g)
{
	int ha[(g->dimension * g->dimension) - 1];
	int stuff = 0;
	int i = 0;
	int	ze_row = 0;
	int row = g->dimension - 1;
	int col = g->dimension - 1;
	int l = 0;
	int t = 0;
	int dir = 0; 


	while (t <= row && t <= col)
	{
		if (dir == 0)
		{
			for (int z = l; z <= row; z++)
			{
				cout << g->puzzle[t][z] << " ";
				ha[i] = g->puzzle[t][z];
				i++;
			}
			t++;
		}
		if (dir == 1)
		{
			for (int z = t; z <= col; z++)
			{
				cout << g->puzzle[z][row] << " ";
				ha[i] = g->puzzle[z][row];
				i++;
			}
			row--;
		}
		if (dir == 2)
		{
			for (int z = row; z >= l; z--)
			{
				cout << g->puzzle[col][z] << " ";
				ha[i] = g->puzzle[col][z];
				i++;
			}
			col--;
		}
		if (dir == 3)
		{
			for (int z = col; z >= t; z--)
			{
				cout << g->puzzle[z][l] << " ";
				ha[i] = g->puzzle[z][l];
				i++;
			}
			l++;
		}
		dir = (dir + 1) % 4; 
	}

	cout << "ITS A SPIRAL" << endl;

	int test = 1;
	for (int y = ((int)g->dimension - 1); y >= 0; y--)
	{
		for (int x = 0; x < (int)g->dimension; x++)
		{
			if (g->c_puzzle[0]->get_puzzle(x, y) == 0)
				ze_row = test;
		}
		test = test  + 1; 
	}

	cout << "ze_row " << ze_row << endl;
	for (int i = 0; i < (int)(g->dimension * g->dimension); i++)
	{
		for (int k = i; k < (int)(g->dimension * g->dimension); k++)
		{
			if (ha[i] > ha[k])
				stuff++;
		}
		cout << "STUFF " << stuff << endl;
	}
	ha[0] = stuff;
	cout << "HAHAHAHA " << ha[0] << endl;
	if (g->dimension % 2 == 1 && ha[0] % 2 == 0)
		cout << "solvable.." << endl;
	else if (g->dimension % 2 == 0 && ze_row % 2 == 1 && ha[0] % 2 == 0)
		cout << "solvable.." << endl;
	else if (g->dimension % 2 == 0 && ze_row % 2 == 0 && ha[0] % 2 == 1)
		cout << "solvable.." << endl;
	else
	{
		cout << "unsolvable..." << endl;
		error();
	}
	sleep(15);
}

void	check_solvability(t_global *g)
{
	write_array(g);
	validate_solvability(g);
	reshuffle_array(g);
	yes(g);
}
