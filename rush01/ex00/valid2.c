/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:45:45 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/15 14:45:46 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>

/* Check for duplicates on a column */
int	check_col(t_bruteforce_state *state, int *table, int col, int *tmp)
{
	int	i;

	i = 0;
	while (i < state->board->size)
		tmp[i++] = 0;
	i = 0;
	while (i < state->board->size)
	{
		tmp[table[i * state->board->size + col] - 1] = 1;
		++i;
	}
	i = 0;
	while (i < state->board->size)
		if (tmp[i++] == 0)
			return (0);
	return (1);
}

/* Check for duplicates on a line */
int	check_line(t_bruteforce_state *state, int *table, int line, int *tmp)
{
	int	i;

	i = 0;
	while (i < state->board->size)
		tmp[i++] = 0;
	i = 0;
	while (i < state->board->size)
	{
		tmp[table[line * state->board->size + i] - 1] = 1;
		++i;
	}
	i = 0;
	while (i < state->board->size)
		if (tmp[i++] == 0)
			return (0);
	return (1);
}

/* Checks whether table is a valid latin square */
int	valid_latin_square(t_bruteforce_state *state, int *table)
{
	int	i;

	i = 0;
	while (i < state->board->size)
	{
		if (!check_col(state, table, i, state->tmp)
			|| !check_line(state, table, i, state->tmp))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
