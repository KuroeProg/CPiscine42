/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   latinsquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:44:15 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/15 14:44:17 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>

void	find_overlap(int *overlap, t_cell *c)
{
	int	i;

	i = 0;
	while (i < c->size)
	{
		if (c->size == 1)
			overlap[c->values[i] - 1] = 1;
		++i;
	}
}

void	apply_overlap(int *overlap, t_cell *c, int n)
{
	int	i;

	i = 0;
	if (c->values)
		free(c->values);
	c->values = malloc(sizeof(int) * n);
	c->size = 0;
	while (i < n)
	{
		if (!overlap[i])
			c->values[c->size++] = i + 1;
		++i;
	}
}

void	check(t_board *b, int *overlap, int i, int j)
{
	if ((i % b->size) + j < b->size)
		find_overlap(overlap, &b->grid[i + j]);
	if ((i % b->size) - j >= 0)
		find_overlap(overlap, &b->grid[i - j]);
	if ((i / b->size) + j < b->size)
		find_overlap(overlap, &b->grid[i + j * b->size]);
	if ((i / b->size) - j >= 0)
		find_overlap(overlap, &b->grid[i - j * b->size]);
}

void	apply_latinsquare(t_board *b)
{
	int	i;
	int	j;
	int	*overlap;

	i = 0;
	overlap = malloc(sizeof(int) * b->size);
	while (i < b->size * b->size)
	{
		j = 0;
		while (j < b->size)
			overlap[j++] = 0;
		j = 0;
		while (j < b->size)
		{
			check(b, overlap, i, j);
			++j;
		}
		if (b->grid[i].size != 1)
			apply_overlap(overlap, &b->grid[i], b->size);
		++i;
	}
	free(overlap);
}

unsigned long long	possible_states(t_board *b)
{
	int					i;
	unsigned long long	count;

	i = 0;
	count = 1;
	while (i < b->size * b->size)
		count *= b->grid[i++].size;
	return (count);
}
