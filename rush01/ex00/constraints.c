/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:43:30 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/15 14:43:34 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	cons_top(t_board *b, int *constraints[4], int i)
{
	int	j;

	if (constraints[0][i] == b->size)
	{
		j = 0;
		while (j < b->size)
		{
			deinit_cell(&b->grid[j * b->size + i]);
			b->grid[j * b->size + i] = single_cell(j + 1);
			++j;
		}
	}
	else if (constraints[0][i] == 1)
	{
		deinit_cell(&b->grid[i]);
		b->grid[i] = single_cell(b->size);
	}
}

void	cons_bot(t_board *b, int *constraints[4], int i)
{
	int	j;

	if (constraints[1][i] == b->size)
	{
		j = 0;
		while (j < b->size)
		{
			deinit_cell(&b->grid[(b->size - 1 - j) * b->size + i]);
			b->grid[(b->size - 1 - j) * b->size + i] = single_cell(j + 1);
			++j;
		}
	}
	else if (constraints[1][i] == 1)
	{
		deinit_cell(&b->grid[i + b->size * (b->size - 1)]);
		b->grid[i + b->size * (b->size - 1)] = single_cell(b->size);
	}
}

void	cons_left(t_board *b, int *constraints[4], int i)
{
	int	j;

	if (constraints[2][i] == b->size)
	{
		j = 0;
		while (j < b->size)
		{
			deinit_cell(&b->grid[i * b->size + j]);
			b->grid[i * b->size + j] = single_cell(j + 1);
			++j;
		}
	}
	else if (constraints[2][i] == 1)
	{
		deinit_cell(&b->grid[i * b->size]);
		b->grid[i * b->size] = single_cell(b->size);
	}
}

void	cons_right(t_board *b, int *constraints[4], int i)
{
	int	j;

	if (constraints[3][i] == b->size)
	{
		j = 0;
		while (j < b->size)
		{
			deinit_cell(&b->grid[(i + 1) * b->size - j - 1]);
			b->grid[(i + 1) * b->size - j - 1] = single_cell(j + 1);
			++j;
		}
	}
	else if (constraints[3][i] == 1)
	{
		deinit_cell(&b->grid[(i + 1) * b->size - 1]);
		b->grid[(i + 1) * b->size - 1] = single_cell(b->size);
	}
}

void	apply_constraints(t_board *b, int *constraints[4])
{
	int	i;

	i = 0;
	while (i < b->size)
	{
		cons_top(b, constraints, i);
		cons_bot(b, constraints, i);
		cons_left(b, constraints, i);
		cons_right(b, constraints, i);
		++i;
	}
}
