/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:50:47 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/07 14:02:57 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	else if (c >= '0' && c <= '9')
		return (3);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is(str[i - 1]) == 0 && (is(str[i]) == 1 || is(str[i]) == 2))
		{
			if (is(str[i]) == 1)
				str[i] -= 32;
		}
		else if (is(str[i]) == 2)
			str[i] += 32;
		i++;
	}
	return (str);
}
