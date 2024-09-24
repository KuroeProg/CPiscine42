/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:15:04 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/19 12:12:23 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[y])
	{
		dest[i] = src[y];
		y++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_strlalllen(char **strs, int size)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < size)
	{
		result += ft_strlen(strs[i]);
		i++;
	}
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		full_len;
	char	*finalstr;

	i = 0;
	if (size == 0)
	{
		finalstr = malloc(sizeof(char) * 1);
		finalstr[0] = '\0';
		return (finalstr);
	}
	full_len = ft_strlalllen(strs, size);
	full_len += ft_strlen(sep) * (size - 1);
	finalstr = (char *)malloc(sizeof(char *) * (full_len + 1));
	finalstr[0] = 0;
	while (i < size)
	{
		ft_strcat(finalstr, strs[i]);
		if (i < size -1)
			ft_strcat(finalstr, sep);
		i++;
	}
	return (ft_strcat(finalstr, "\0"), finalstr);
}

#include <stdio.h>
int	main()
{
	int size = 1;
	char *strs[] = {""};
	char *sep = "";
	char *s = ft_strjoin(size, strs, sep);
	printf("%s", s);
	free(s);
	return 0;
}
