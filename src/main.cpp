/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:16:05 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/09 15:58:56 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	init(t_global *g)
{
	g->dimension = 0;
	g->malloc_flag = 0;
}

int		main(int argc, char **argv)
{
	t_global	g;		

	init(&g);

	if (argc == 2)
	{
		validate_data(argv[1], &g);
		if (g.data.size() == g.dimension)
		{
			save_data(&g);
			check_solvability(&g);
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
