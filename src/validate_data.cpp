/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:33:18 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/09 11:15:05 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

string	fix_spaces(string line)
{
	unsigned long int	i = 0;
	string				fixed;

	while(i < line.length())
	{
		if ((isspace(line[i]) || (line[i] == '\t')) && 
				((line[i + 1] == ' ') || (line[i + 1] == '\t')))
			i++;
		else if ((line[i] == '\t') && (isdigit(line[i + 1])))
		{
			fixed += ' ';
			i++;
		}
		else
		{
			fixed += line[i];
			i++; 
		}
	}

	return (fixed);
}

void	validate_data(string file, t_global *g)
{
	string		line;
	string		fixed;
    ifstream	input(file);

	g->dimension = 0; 

	while (getline(input, line).good())
	{
		fixed = fix_spaces(line);
		cout << "the string " << fixed << endl;
	}
}
