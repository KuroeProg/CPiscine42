/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:42:43 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/15 14:43:06 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include "util.h"
#include <stdlib.h>

/* Displays the table */
void	print_table(int *table, int size)
{
	int	i;

	i = 0;
	while (i < size * size)
	{
		putnbrull(table[i++]);
		if (i % size == 0)
			ft_putstr(1, "\n");
		else
			ft_putstr(1, " ");
	}
}

/* The recursive bruteforce */
void	bruteforce_impl(t_bruteforce_state *state, int *table, int i)
{
	int	j;

	if (state->found || !valid_partial_latin_square(state, table, i))
		return ;
	while (i < state->board->size * state->board->size)
	{
		if (state->board->grid[i].size == 1)
			table[i] = state->board->grid[i].values[0];
		else
		{
			j = 0;
			while (j < state->board->grid[i].size)
			{
				table[i] = state->board->grid[i].values[j++];
				bruteforce_impl(state, table, i + 1);
			}
			return ;
		}
		++i;
	}
	if (is_valid(state, table) && !state->found)
	{
		print_table(table, state->board->size);
		state->found = 1;
	}
}

/* Bruteforce entry point */
void	bruteforce(t_board *b, int **constraints)
{
	int					i;
	int					*table;
	t_bruteforce_state	state;

	table = malloc(b->size * b->size * sizeof(int));
	i = 0;
	while (i < b->size * b->size)
		table[i++] = 0;
	state = (t_bruteforce_state){
		.board = b,
		.constraints = constraints,
		.found = 0,
		.tmp = malloc(sizeof(int) * b->size),
	};
	bruteforce_impl(&state, table, 0);
	free(state.tmp);
	free(table);
	if (!state.found)
		ft_putstr(2, "Error\n");
}
