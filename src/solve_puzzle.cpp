/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_puzzle.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:02:02 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/16 09:39:50 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	compare_array(t_global *g)
{
	for (int y = 0; y < (int)g->dimension; y++)
	{
		for (int x = 0; x < (int)g->dimension; x++)
		{
			if (g->c_puzzle[0]->get_puzzle(x, y) != g->mock_puzzle[y][x])
			{   
				return (0);
			}
		}
	}
	return (1);
}

void	solve_puzzle(t_global *g)
{
	int move = -1;
	int x;
	int y; 
	int tmp = 0;

	g->prev_move[0] = -1;	
	g->prev_move[1] = -1;
	for (int i = 0; i < (int)g->dimension; i++)
	{
		for (int j = 0; j < (int)g->dimension; j++)
		{
			if (g->c_puzzle[0]->get_puzzle(j, i) == 0)
			{   
				x = j;
				y = i;
			}
		}
	}

	while (1)
	{
		if (compare_array(g))
			break ;
		if (strcmp(g->heuristic, "M") == 0)
		{
			cout << "M" << endl;
			move = manhattan_heuristic(g);
		}

		if (move == 0)
		{
			tmp = g->c_puzzle[0]->get_puzzle(x - 1, y);
			g->c_puzzle[0]->set_puzzle(x, y, tmp);
			g->prev_move[0] = x;
			g->prev_move[1] = y;
			x -= 1;
			g->c_puzzle[0]->set_puzzle(x, y, 0);
		}
		if (move == 1)
		{
			tmp = g->c_puzzle[0]->get_puzzle(x + 1, y);
			g->c_puzzle[0]->set_puzzle(x, y, tmp);
			g->prev_move[0] = x;
			g->prev_move[1] = y;
			x += 1;
			g->c_puzzle[0]->set_puzzle(x, y, 0);
		}
		if (move == 2)
		{
			tmp = g->c_puzzle[0]->get_puzzle(x, y - 1);
			g->c_puzzle[0]->set_puzzle(x, y, tmp);
			g->prev_move[0] = x;
			g->prev_move[1] = y;
			y -= 1;
			g->c_puzzle[0]->set_puzzle(x, y, 0);
		}
		if (move == 3)
		{
			tmp = g->c_puzzle[0]->get_puzzle(x, y + 1);
			g->c_puzzle[0]->set_puzzle(x, y, tmp);
			g->prev_move[0] = x;
			g->prev_move[1] = y;
			y += 1;
			g->c_puzzle[0]->set_puzzle(x, y, 0);
		}	


		cout << "FINAL POUT TFTSFTFWSDR WDGV " << endl;
		for (int u = 0; u < (int)g->dimension; u++)
		{
			for (int t = 0; t < (int)g->dimension; t++)
			{
				cout << " " << g->c_puzzle[0]->get_puzzle(t, u);
			}
			cout << endl;
		}
	}
}
