/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:42:16 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/15 14:42:19 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "board.h"

/* Creates an empty cell */
t_cell	empty_cell(void)
{
	return ((t_cell){
		.size = 0,
		.values = NULL,
	});
}

/* Creates a cell with a single value */
t_cell	single_cell(int v)
{
	int	*values;

	values = malloc(sizeof(int));
	values[0] = v;
	return ((t_cell){
		.size = 1,
		.values = values,
	});
}

/* Deinitializes (free) a cell */
void	deinit_cell(t_cell *c)
{
	if (c->values)
		free(c->values);
}

/* Initializes a board with empty cell */
t_board	init_board(int size)
{
	int		i;
	t_cell	*grid;

	grid = malloc(size * size * sizeof(t_cell));
	i = 0;
	while (i < size * size)
		grid[i++] = empty_cell();
	return ((t_board){
		.size = size,
		.grid = grid,
	});
}

/* Deinitializes (free) the board */
void	deinit_board(t_board *b)
{
	int	i;

	i = 0;
	while (i < b->size * b->size)
	{
		deinit_cell(&b->grid[i]);
		++i;
	}
	free(b->grid);
}
