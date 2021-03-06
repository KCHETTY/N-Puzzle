/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_puzzle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:15:55 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/19 12:00:42 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _N_PUZZLE_H_
# define _N_PUZZLE_H_

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <sys/time.h>
# include <vector>
# include <math.h>
# include <unistd.h>
# include <regex>
# include "puzzle.class.h"

//g->co_ordinates.push_back(new coordinates());

using namespace std;

typedef struct					s_global
{
		int						center_x;
		char					*heuristic;
		int						center_y;
		int						**puzzle;
		vector<vector<int> >	prev_move;
		int						**mock_puzzle;
		unsigned int			dimension;
		int						malloc_flag;
		vector<int>				move;
		vector<map_puzzle*>		c_puzzle;
		vector<string>			data;
		vector<int>				dummy;
}								t_global;

void	save_data(t_global *g);
void 	malloc_puzzle(t_global *g);
void	validate_data(string file, t_global *g);
void	check_solvability(t_global *g);
void	error(void);
void	heuristic(t_global *g);
void	solve_puzzle(t_global *g);

#endif
