/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:45:58 by lefoffan          #+#    #+#             */
/*   Updated: 2024/09/21 13:16:37 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}



int	ft_error(int nb)
{
	//if argument is less than 1.
	if (nb == 1)
		ft_putstr(":: ERROR 1 :: LESS ARGUMENTS THAN EXPECTED.\n");
	//if there are too much arguments.
	if (nb == 2)
		ft_putstr(":: ERROR 2 :: MORE ARGUMENTS THAN EXPECTED.\n");
	//if arguments aren't valid value.
	if (nb == 3)
		ft_putstr(":: ERROR 3 :: ONE OR MORE ARGUMENT ARE NOT VALID.\n");
	//if arguments aren't a positive value.
	if (nb == 4)
		ft_putstr("Error\n");
	//Parsing Error.
	if (nb == 5)
	{
		ft_putstr("Dict Error\n");
		quit prgrm
	}
	//Unsolvable value
	if (nb == 6)
		ft_putstr("Dict Error\n");


		
