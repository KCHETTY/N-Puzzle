/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solvability.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:43 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/10 09:35:30 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	write_array(t_global *g)
{
	for (unsigned int i = 0; i < (g->dimension * g->dimension); i++)
		g->dummy.push_back(i);
	for (unsigned int j = 0; j < (g->dimension * g->dimension); j++)
		cout << " " << g->dummy[j];
	cout << endl;

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

void	check_solvability(t_global *g)
{
	write_array(g);	
}
