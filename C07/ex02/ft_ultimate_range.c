/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:53:32 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/14 09:33:03 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	i = 0;
	size = max - min;
	if (min >= max)
	{
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (size));
	if (*range == NULL)
	{
		return (-1);
	}
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (i);
}
/**
int	main(void)
{
	int min = 5;
	int max = 12;
	int *result;
	int size = ft_ultimate_range(&result, min, max);

	printf("min : %d\nmax: %d\nresult: ", min, max);
	if (result)
	{
		for (int i = 0; i < size; i++)
			printf("%d ", result[i]);
		free(result);
	}
	else
		printf("Memory allocation Failed");
	return 0;
}**/
