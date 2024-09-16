/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:21:18 by cfiachet          #+#    #+#             */
/*   Updated: 2024/09/16 18:39:05 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char *ft_strcpy(char *dest, char *src)
{
	int	i;
	i = 0;

	dest = malloc(sizeof(char *) * (ft_strlen(src)));
	if (dest == NULL)
		return NULL;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';


int	ft_strlen(char *str)
{
	int	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int	i;

	i = 0;
	t_stock_str *tab;
	tab = malloc(sizeof(t_stock_str) * ac);
	if (tab == NULL)
		return NULL;
	while (str[i])
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strcpy(tab[i], av[i]);
		i++;
	}
	tab[i].str = 0;
	
	return (tab);
}
