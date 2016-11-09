/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:33:18 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/09 12:45:46 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

string	fix_spaces(string line, int count)
{
	unsigned long int	i = 0;
	string				fixed;

	while(i < line.length())
	{
		if (((line[i]) == ' ' || (line[i] == '\t')) && (line[i + 1] == '\0'))
			i++;
		else if ((isspace(line[i]) || (line[i] == '\t')) && 
				((line[i + 1] == ' ') || (line[i + 1] == '\t')))
			i++;
		else if ((line[i] == '\t') && (isdigit(line[i + 1])))
		{
			if (count != 1)
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

void	validate_line(string line, int count)
{
	unsigned long int i = 0; 
	while (i < line.length())
	{
		if (count == 1 && line[i] == '0' && i == 0)
			error();
		else if (line[i] == ' ')
			i++;
		else if (!isdigit(line[i]))
			error();
		else
			i++;
	}
}

bool	check_line_size(string fixed, t_global *g, int line_count)
{
	unsigned int count = 0;

	if (line_count > 1)
	{
		for (unsigned long int i = 0; i < fixed.length(); i++)
		{
			if (fixed[i] == ' ')
				count++;		
		}
		count += 1;
		cout << "count " << count << endl;
		if (g->dimension == count)
			return (true);
		error();
	}
	return (false);	
}

void	validate_data(string file, t_global *g)
{
	string		line;
	int			line_count = 0;
	string		fixed;
    ifstream	input(file);

	g->dimension = 0;

	while (getline(input, line).good())
	{
		line_count += 1;
		fixed = fix_spaces(line, line_count);
		cout << "the string " << fixed << endl;
		validate_line(fixed, line_count);
		if (g->dimension == 0)
			g->dimension = stoi(fixed);
		if (check_line_size(fixed, g, line_count))
			g->data.push_back(fixed);
	}
}
