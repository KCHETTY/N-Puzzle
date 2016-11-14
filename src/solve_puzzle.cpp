/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_puzzle.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:02:02 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/14 09:13:12 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	solve_puzzle(t_global *g)
{
	if (strcmp(g->heuristic, "A") == 0)
		cout << "A" << endl;
	if (strcmp(g->heuristic, "B") == 0)
		cout << "B" << endl;
	if (strcmp(g->heuristic, "C") == 0)
		cout << "C" << endl;
}
