/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:14:49 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/09 10:27:25 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	malloc_puzzle(t_global *g)
{
	g->puzzle = (int **)malloc(sizeof(int *) * g->dimension + 1);
	for (int i = 0; i < g->dimension; i++)
		g->puzzle[i] = (int *)malloc(sizeof(int) * g->dimension);
}
