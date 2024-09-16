/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:45:12 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/15 14:45:14 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	ft_putstr(int fd, char *s)
{
	while (*s)
		write(fd, s++, 1);
}

int	abs(int x)
{
	return ((x < 0) * (-x) + (x >= 0) * x);
}

void	putnbrull(unsigned long long n)
{
	char	c;

	if (n >= 10)
		putnbrull(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

void	putarray(int *arr, int n, char *sep)
{
	int	i;

	i = 0;
	write(1, sep, 1);
	while (i < n)
	{
		if (i != 0)
			write(1, sep + 2, ft_strlen(sep + 2));
		putnbrull(arr[i]);
		++i;
	}
	write(1, sep + 1, 1);
}
