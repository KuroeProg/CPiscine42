/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:41:38 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/15 14:41:45 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H

/**
 * @brief Represents a cell in the board
 *
 * A cell holds list of all possible values it can take
 * Cells with a single value are called `certain cells`
 * because they may only take one value
 */
typedef struct s_cell
{
	/// Number of values in the cell (0 for empty cell)
	int	size;
	/// Possible values of the cell
	int	*values;
}	t_cell;

/**
 * @brief Represents the game's board
 */
typedef struct s_board
{
	/// Side length of the grid
	int		size;
	/// Grid
	t_cell	*grid;
}	t_board;

/**
 * @brief Creates an empty cell
 *
 * @note Empty cell do not require any allocations
 * @returns The newly created cell
 */
t_cell	empty_cell(void);
/**
 * @brief Creates a cell with a single value
 *
 * @param v Value to assign the cell
 * @returns The newly created cell
 */
t_cell	single_cell(int v);
/**
 * @brief Deinitializes a cell
 *
 * @param The cell to de-initialize
 */
void	deinit_cell(t_cell *c);
/**
 * @brief Allocates a new board of `size * size`
 *
 * @param size Size of the new board
 *
 * The board is initialized with empty cells
 * These cells have to be filled using @see apply_latinsquare
 */
t_board	init_board(int size);
/**
 * @brief Deinitializes the board
 *
 * @param Board to deinitialize
 */
void	deinit_board(t_board *b);

#endif // BOARD_H
