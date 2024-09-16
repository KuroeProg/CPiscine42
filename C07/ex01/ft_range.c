/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:19:14 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/13 21:42:51 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*tab;
	int	i;

	i = 0;
	size = max - min;
	if (min >= max)
	{
		return (NULL);
	}
	tab = (int *)malloc(sizeof(int) * (max - min));
	if (tab == NULL)
	{
		return (tab);
	}
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
/**#include <unistd.h>
#include <stdio.h>
int	main()
{
	int min = 27;
	int max = 20;
	int *tab = ft_range(min, max);
	int i;


	i = 0;
	while (i < max - min)
	{
		printf("%d", tab[i]);
		i++;
	}
}**/
