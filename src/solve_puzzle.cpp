/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_puzzle.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:02:02 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/17 11:41:36 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	compare_array(t_global *g, int i)
{
		for (int y = 0; y < (int)g->dimension; y++)
		{
			for (int x = 0; x < (int)g->dimension; x++)
			{
				if (g->c_puzzle[i]->get_puzzle(x, y) != g->mock_puzzle[y][x])
				{   
					return (0);
				}
			}
		}
	return (1);
}

void	solve_puzzle(t_global *g)
{
	vector<int> move;
	vector<int> tmp1;
	int x;
	int y; 
	int tmp = 0;

	tmp1.push_back(-1);	
	tmp1.push_back(-1);
	g->prev_move.push_back(tmp1);
	
	/*for (int i = 0; i < (int)g->dimension; i++)
	  {
	  for (int j = 0; j < (int)g->dimension; j++)
	  {
	  if (g->c_puzzle[0]->get_puzzle(j, i) == 0)
	  {   
	  x = j;
	  y = i;
	  }
	  }
	  }*/

	while (1)
	{
		/*if (compare_array(g))
			break ;
		if (strcmp(g->heuristic, "M") == 0)
		  {
		  cout << "M" << endl;
		  move = manhattan_heuristic(g);
		  }*/

		for (unsigned long int k = 0; k < g->c_puzzle.size(); k++)
		{

			cout << "IM THIS SIZE YOU DUMB FUCK!!!!!!!!!! " << g->c_puzzle.size() << endl;
			for (int i = 0; i < (int)g->dimension; i++)
			{
				for (int j = 0; j < (int)g->dimension; j++)
				{
					if (g->c_puzzle[k]->get_puzzle(j, i) == 0)
					{
						x = j;
						y = i;
					}
				}
			}

			cout << "XXXXXXXXXXX  " << x << "YYYYYYYYYY " << y << endl;

			if (strcmp(g->heuristic, "M") == 0)
			{
					cout << "M" << endl;
					move = manhattan_heuristic(g, k, x, y);
			}

			if (move[k] == 0)
			{
				tmp = g->c_puzzle[k]->get_puzzle(x - 1, y);
				g->c_puzzle[k]->set_puzzle(x, y, tmp);
				g->prev_move[k][0] = x;
				x -= 1;
				g->c_puzzle[k]->set_puzzle(x, y, 0);
			}
			if (move[k] == 1)
			{
				tmp = g->c_puzzle[k]->get_puzzle(x + 1, y);
				g->c_puzzle[k]->set_puzzle(x, y, tmp);
				g->prev_move[k][0] = x;
				g->prev_move[k][1] = y;
				x += 1;
				g->c_puzzle[k]->set_puzzle(x, y, 0);
			}
			if (move[k] == 2)
			{
				tmp = g->c_puzzle[k]->get_puzzle(x, y - 1);
				g->c_puzzle[k]->set_puzzle(x, y, tmp);
				g->prev_move[k][0] = x;
				g->prev_move[k][1] = y;
				y -= 1;
				g->c_puzzle[k]->set_puzzle(x, y, 0);
			}
			if (move[k] == 3)
			{
				tmp = g->c_puzzle[k]->get_puzzle(x, y + 1);
				g->c_puzzle[k]->set_puzzle(x, y, tmp);
				g->prev_move[k][0] = x;
				g->prev_move[k][1] = y;
				y += 1;
				g->c_puzzle[k]->set_puzzle(x, y, 0);
			}	

			if (g->c_puzzle.size() > 1)
				g->prev_move.push_back(tmp1);

			cout << "FINAL POUT TFTSFTFWSDR WDGV " << k << endl;
			for (int u = 0; u < (int)g->dimension; u++)
			{
				for (int t = 0; t < (int)g->dimension; t++)
				{
					cout << " " << g->c_puzzle[k]->get_puzzle(t, u);
				}
				cout << endl;
			}

			if (compare_array(g, k))
				return  ;

			//sleep(15);
		}
	}
}
