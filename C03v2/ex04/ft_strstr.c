/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:06:50 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/08 19:49:43 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (to_find[y] == '\0')
		return (str);
	while (str[i])
	{
		y = 0;
		while ((str[i + y] == to_find[y]) && to_find[y])
		{
			y++;
			if (to_find[y] == '\0')
				return (str + i);
		}
		i++;
	}
	return (0);
}
