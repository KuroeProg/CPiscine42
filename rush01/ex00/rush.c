/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:44:33 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/15 14:44:35 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include "board.h"
#include "util.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_strcmp(char *a, char *b)
{
	while (*a && *a == *b)
	{
		++a;
		++b;
	}
	return (*a - *b);
}

/* Print the board for `verbose` mode */
void	print_board(t_board *b)
{
	int	i;

	i = 0;
	while (i < b->size * b->size)
	{
		if (i % b->size == 0 && i)
			write(1, "\n", 1);
		putarray(b->grid[i].values, b->grid[i].size, "{}, ");
		write(1, ", ", 2);
		++i;
	}
	write(1, "\n", 1);
}

/* Solves the puzzle */
void	start(t_board *b, int **input, int debug, int i)
{
	apply_constraints(b, input);
	if (debug)
	{
		ft_putstr(1, " * Applying input constraints:\n");
		print_board(b);
	}
	while (i < b->size)
	{
		apply_latinsquare(b);
		++i;
	}
	if (debug)
	{
		ft_putstr(1, " * Applying latin square constraints:\n");
		print_board(b);
	}
	if (debug)
	{
		ft_putstr(1, "Bruteforcing out of ");
		putnbrull(possible_states(b));
		ft_putstr(1, " possible states...\n");
	}
	bruteforce(b, input);
}

/* End, de-initializes resources */
void	end(t_board *b, int **input)
{
	deinit_board(b);
	free(input[0]);
	free(input[1]);
	free(input[2]);
	free(input[3]);
	free(input);
}

int	main(int argc, char **argv)
{
	int		**input;
	int		size;
	t_board	b;
	int		debug;

	if (argc < 2)
	{
		ft_putstr(2, "Error\n");
		return (1);
	}
	input = parse_puzzle(argv[1], &size);
	if (!input)
	{
		ft_putstr(2, "Error\n");
		return (1);
	}
	debug = (argc >= 3) && (ft_strcmp(argv[2], "verbose") == 0);
	b = init_board(size);
	start(&b, input, debug, 0);
	end(&b, input);
	return (0);
}
