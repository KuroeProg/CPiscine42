/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 08:14:52 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/11 10:16:23 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
	{
		return (1);
	}
	if (nb == 1)
		return (1);
	while (nb > 0)
	{
		result *= nb;
		nb--;
	}
	return (result);
}
