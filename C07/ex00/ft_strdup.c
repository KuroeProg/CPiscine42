/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:58:11 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/13 20:19:05 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <unistd.h>

/*void 	ft_putstr(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}*/

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (dest);
	else
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
/*int	main(void)
{	
	char	*ret;
	char 	*src = "Une grande une phrase";
	ret = ft_strdup(src);
	ft_putstr(ret);
	free(ret);
	return (0);
}*/
