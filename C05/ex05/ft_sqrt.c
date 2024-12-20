/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:10:34 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/16 13:47:21 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i != nb)
	{
		i++;
		if (i * i == nb)
			return (i);
		else if (i * i > nb)
			return (0);
	}
	return (0);
}

#include <stdio.h>
int	main()
{
	printf("%d", ft_sqrt(25));
}
