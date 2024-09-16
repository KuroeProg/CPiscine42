/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:25:02 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/12 08:28:00 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		y = 0;
		while (argv[i][y])
		{
			write(1, &argv[i][y], 1);
			y++;
		}
		write(1, "\n", 1);
		i++;
	}
}
