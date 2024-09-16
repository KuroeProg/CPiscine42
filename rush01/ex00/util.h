/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:45:26 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/15 14:45:27 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

void	ft_strlen(char *s);
void	ft_putstr(int fd, char *s);

void	putnbrull(unsigned long long n);
/**
 * @brief Writes an array to stdout using a custom separator
 *
 * @param arr Array to write
 * @param n Array size
 * @param sep The separator string;
 *  * sep[0] Character displayed at the beginning of the array
 *  * sep[1] Character displayed at end beginning of the array
 *  * sep[2..] Characters displayed between array elements
 */
void	putarray(int *arr, int n, char *sep);

/**
 * @brief Prints a square table of size n
 *
 * @param table Table to print
 * @param n Sidelength of the table
 */
void	puttable(int *table, int n);

#endif // UTIL_H
