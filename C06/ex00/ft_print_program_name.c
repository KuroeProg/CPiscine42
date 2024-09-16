/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:22:54 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/12 08:23:51 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	y;

	y = 0;
	if (argc == 1)
	{
		while (argv[0][y])
		{
			write(1, &argv[0][y], 1);
			y++;
		}
		write(1, "\n", 1);
	}
	return (0);
}