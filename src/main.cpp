/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:16:05 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/14 09:13:13 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	init(t_global *g)
{
	g->dimension = 0;
	g->malloc_flag = 0;
	g->center_x = 0;
	g->center_y = 0;
}

int		main(int argc, char **argv)
{
	t_global	g;		

	init(&g);

	if (argc == 3)
	{
		validate_data(argv[2], &g);
		g.heuristic = argv[1];
		if (g.data.size() == g.dimension)
		{
			save_data(&g);
			check_solvability(&g);
			solve_puzzle(&g);
		}
	}
	else
		cout << "missing file input" << endl;
	return(0);
}

void	error()
{
	cout << "Error" << endl;
	exit(0);
}
