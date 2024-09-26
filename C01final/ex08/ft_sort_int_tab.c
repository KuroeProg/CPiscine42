/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:43:59 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/22 15:50:59 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp2;
	int	i;
	int	j;

	i = 0;
	temp2 = 0;
	while (i < size)
	{
		j = i;
		while (j <= size)
		{
			if (tab[i] > tab[j])
			{
				temp2 = tab[i];
				tab[i] = tab[j];
				tab[j] = temp2;
			}
			j++;
		}
		i++;
	}
}

/**
#include <stdio.h>

int	main(void)
{
	int  i;
	i = 0;

	int tab[4] = {-4, -8, 3, 0};
	ft_sort_int_tab(tab,4);
	while (i <= 3)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}
**/
