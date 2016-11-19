/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:16:05 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/19 12:25:39 by kchetty          ###   ########.fr       */
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

void    testing(char *test)
{
	if (strcmp(test, "M") != 0)
	{
		if (strcmp(test, "E") != 0)
		{
			if (strcmp(test, "H") != 0)
			{
				cout << "Invalid Heuristic!" << endl;
				exit(0);
			}
		}
	}
}

int		main(int argc, char **argv)
{
	t_global	g;		

	init(&g);

	if (argc >= 2)
	{
		testing(argv[1]);
		g.heuristic = argv[1];
		if (argv[2] != NULL)
			validate_data(argv[2], &g);
		save_data(&g);
		check_solvability(&g);
		solve_puzzle(&g);
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
