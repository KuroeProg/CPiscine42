/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:17:52 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/04 13:35:27 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putletter(char n)
{
	write(1, &n, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_putletter(i / 10 + '0');
			ft_putletter(i % 10 + '0');
			write(1, " ", 1);
			ft_putletter(j / 10 + '0');
			ft_putletter(j % 10 + '0');
			if (!(i == 98 && j == 99))
			{
				write(1, ", ", 2);
			}
			j++;
		}
		i++;
	}
}

/*int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
