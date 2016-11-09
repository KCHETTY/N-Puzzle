/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_puzzle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:15:55 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/09 12:15:08 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _N_PUZZLE_H_
# define _N_PUZZLE_H_

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <vector>
# include <regex>
# include "puzzle.class.h"

//g->co_ordinates.push_back(new coordinates());

using namespace std;

typedef struct	s_global
{
		int				**puzzle;
		int				dimension;
		int				malloc_flag;
		vector<map_puzzle*>	c_puzzle;
		vector<string>		data;
}								t_global;

void	save_data(string file, t_global *g);
void    malloc_puzzle(t_global *g);
void	validate_data(string file, t_global *g);
void    error(void);

#endif
