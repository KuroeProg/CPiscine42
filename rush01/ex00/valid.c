/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:46:24 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/15 14:46:25 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	valid_latin_square(t_bruteforce_state *state, int *table);

int	check_top(t_bruteforce_state *state, int *table, int i)
{
	int	h;
	int	lasth;
	int	j;

	h = 1;
	lasth = table[i];
	j = 1;
	while (j < state->board->size)
	{
		if (table[i + j * state->board->size] > lasth)
		{
			lasth = table[i + j * state->board->size];
			++h;
		}
		++j;
	}
	return (h == state->constraints[0][i]);
}

int	check_bot(t_bruteforce_state *state, int *table, int i)
{
	int	h;
	int	lasth;
	int	j;

	h = 1;
	lasth = table[i + state->board->size * (state->board->size - 1)];
	j = state->board->size - 1;
	while (j >= 0)
	{
		if (table[i + j * state->board->size] > lasth)
		{
			lasth = table[i + j * state->board->size];
			++h;
		}
		--j;
	}
	return (h == state->constraints[1][i]);
}

int	check_left(t_bruteforce_state *state, int *table, int i)
{
	int	h;
	int	lasth;
	int	j;

	h = 1;
	lasth = table[i * state->board->size];
	j = 1;
	while (j < state->board->size)
	{
		if (table[j + i * state->board->size] > lasth)
		{
			lasth = table[j + i * state->board->size];
			++h;
		}
		++j;
	}
	return (h == state->constraints[2][i]);
}

int	check_right(t_bruteforce_state *state, int *table, int i)
{
	int	h;
	int	lasth;
	int	j;

	h = 1;
	lasth = table[(i + 1) * state->board->size - 1];
	j = state->board->size - 1;
	while (j >= 0)
	{
		if (table[j + i * state->board->size] > lasth)
		{
			lasth = table[j + i * state->board->size];
			++h;
		}
		--j;
	}
	return (h == state->constraints[3][i]);
}

int	is_valid(t_bruteforce_state *state, int *table)
{
	int	i;

	i = 0;
	while (i < state->board->size)
	{
		if (!check_top(state, table, i)
			|| !check_bot(state, table, i)
			|| !check_left(state, table, i)
			|| !check_right(state, table, i))
			return (0);
		++i;
	}
	return (valid_latin_square(state, table));
}
