/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:46:00 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/15 14:46:01 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>
#include <stdlib.h>

/* Check for duplicates up */
int	check_dup_up(t_bruteforce_state *state, int *table, int i, int *tmp)
{
	int	j;

	j = 0;
	while (j < state->board->size)
	{
		tmp[j] = 0;
		++j;
	}
	j = i - 1;
	while (j >= 0)
	{
		if (tmp[table[j] - 1])
		{
			return (0);
		}
		tmp[table[j] - 1] = 1;
		j -= state->board->size;
	}
	return (1);
}

/* Check for duplicates on the left */
int	check_dup_left(t_bruteforce_state *state, int *table, int i, int *tmp)
{
	int	j;

	j = 0;
	while (j < state->board->size)
		tmp[j++] = 0;
	j = i;
	while (j % state->board->size)
	{
		if (tmp[table[i - j] - 1])
			return (0);
		tmp[table[i - j] - 1] = 1;
		--j;
	}
	return (1);
}

/** Checks whether table is a valid partial latin square until i */
int	valid_partial_latin_square(t_bruteforce_state *state, int *table, int i)
{
	int	val;

	val = check_dup_up(state, table, i, state->tmp)
		&& check_dup_left(state, table, i, state->tmp);
	return (val);
}
