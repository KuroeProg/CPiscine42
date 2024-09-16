/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:44:52 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/15 14:44:53 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include "board.h"
# include "util.h"

/**
 * @brief Parses input from argv[1]
 *
 * @param s Puzzle input string
 * @param size Returned puzzle size
 *
 * @returns Parsed input
 */
int					**parse_puzzle(char *s, int *size);
/**
 * @brief Resolves basic constraints from the puzzle's rules
 *
 * @param board Board to apply constraints to
 * @param constraints Constraints to apply to the board
 *
 * The applied constraints are the following:
 *  * If constraint is 1, then the next cell is of height size
 *  * If constraint is size, then the next row/column is made of
 *    cells {1 .. size}
 */
void				apply_constraints(t_board *board, int *constraints[4]);
/**
 * @brief Applies Latin Squqre constraints to the board
 *
 * @param board Board to apply constraints to
 *
 * The applied constraints are the following:
 *  * Each row and column must features each numbers from 1 to size
 */
void				apply_latinsquare(t_board *board);
/**
 * @brief Calculates the number of potential board states
 *
 * @param board Board to calculate states for
 * @returns Number of possible board states
 */
unsigned long long	possible_states(t_board *board);

/**
 * @brief Structure passed around during bruteforce to store the puzzle's data
 */
typedef struct s_bruteforce_state
{
	/* The game's board */
	t_board	*board;
	/* The puzzle's constraints */
	int		**constraints;
	/* Whether a solution has been found */
	int		found;
	/* A temporary buffer used to check for duplicates */
	int		*tmp;
}	t_bruteforce_state;

/**
 * @brief Attempts to bruteforce the board for a solution
 *
 * @param b The board to bruteforce
 * @param constraints The puzzle's constraints
 *
 * @note In case the board has empty cells, it won't be
 * solvable.
 */

void				bruteforce(t_board *b, int **constraints);
/**
 * @brief Checks that a given table is valid for a specific state
 *
 * @param state The bruteforce state to check for
 * @param table The table to validate
 *
 * @returns 1 if the table is valid, 0 otherwise
 *
 * Note that in order to be valid, the table must verify the puzzle constraints
 * (as defined in the bruteforce state). And also be a valid latin square.
 */
int					is_valid(t_bruteforce_state *state, int *table);

/**
 * @brief Checks whether table is a valid latin square
 *
 * @param state The bruteforce state to check for
 * @param table The table to check
 *
 * @returns 1 if table is a valid latin square, 0 otherwise
 */
int					valid_latin_square(t_bruteforce_state *state, int *table);

/**
 * @brief Checks whether table is a valid partial latin square
 *
 * @param state The bruteforce state to check for
 * @param table The table to check
 * @param i The index to stop validating after
 *
 * @returns 1 if table is a valid partial latin square, 0 otherwise
 */
int					valid_partial_latin_square(t_bruteforce_state *state,
						int *table, int i);

#endif // RUSH_H
