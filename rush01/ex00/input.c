/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:43:59 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/15 14:44:00 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <stdlib.h>

int	**alloc_tab(char *s, int count, int *size)
{
	int	i;
	int	**tab;

	tab = malloc(4 * sizeof(int *));
	tab[0] = malloc((count / 4) * sizeof(int));
	tab[1] = malloc((count / 4) * sizeof(int));
	tab[2] = malloc((count / 4) * sizeof(int));
	tab[3] = malloc((count / 4) * sizeof(int));
	i = 0;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			tab[i / (count / 4)][i % (count / 4)] = *s - '0';
			++i;
		}
		++s;
	}
	*size = count / 4;
	return (tab);
}

/* Parse input from argv[1] */
int	**parse_puzzle(char *s, int *size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			++count;
		++i;
	}
	if (count % 4 || count / 4 == 0 || count / 4 > 9)
		return (NULL);
	return (alloc_tab(s, count, size));
}
