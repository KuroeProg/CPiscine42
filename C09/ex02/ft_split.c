/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:00:47 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/24 14:29:05 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ischarset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_countword(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (ft_ischarset(str[i], charset) == 1))
			i++;
		if (str[i] && (ft_ischarset(str[i], charset) == 0))
		{
			count++;
			while (str[i] && (ft_ischarset(str[i], charset) == 0))
				i++;
		}
	}
	return (count);
}

int	ft_countlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && (ft_ischarset(str[i], charset) == 0))
		i++;
	return (i);
}

char	*mallocworld(char *str, int size)
{
	int		i;
	char	*tab;

	i = 0;
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	while (str[i] && i < size)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**tab;
	int		nline;
	int		y;
	int		word_len;

	i = 0;
	y = 0;
	nline = ft_countword(str, charset);
	tab = (char **)malloc(sizeof(char *) * (nline + 1));
	if (tab == NULL)
		return (tab);
	while (str[i])
	{
		while (str[i] && (ft_ischarset(str[i], charset) == 1))
			i++;
		word_len = ft_countlen(str + i, charset);
		if (word_len)
			tab[y++] = mallocworld(str + i, word_len);
		i = i + word_len;
	}
	tab[y] = NULL;
	return (tab);
}

/*int main(void)
{

	int	i = 0;
	char str[] = "bon64jour6464cl64oclo";
	char charset[] = "64";
	char **res = ft_split(str, charset);
   	while (res[i])
	{
		printf("%d : %s\n", i,res[i]);
		i++;	
	}

}*/
