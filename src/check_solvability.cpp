/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solvability.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:43 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/11 13:20:01 by kchetty          ###   ########.fr       */
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
				if (g->puzzle[y][x] == g->dummy[r] && 
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

	if ((j -  (int)j) > 0.0)
		g->mock_puzzle[(int)j][(int)j] = 0;
	else
		g->mock_puzzle[(int)j][(int)j - 1] = 0;

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

void	check_solvability(t_global *g)
{
	write_array(g);
	validate_solvability(g);
}
