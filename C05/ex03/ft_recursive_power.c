/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:03:17 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/11 10:25:32 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	tmp;

	tmp = nb;
	if (nb == 0 && power == 0)
		return (1);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power < 0)
		return (0);
	if (power > 1)
	{
		nb = nb * ft_recursive_power(tmp, power - 1);
	}
	return (nb);
}
