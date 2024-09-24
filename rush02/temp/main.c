/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:46:08 by lefoffan          #+#    #+#             */
/*   Updated: 2024/09/21 16:50:55 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_nowhatwesearched(char *str, int *nbtrueptr)
{
	int	i;
	
	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] == '+' || str[i] == '-'))
	{
		i++;
		if(str[i] == '\0')
			*nbtrueptr = 1;
	}
	*nbtrueptr = 0;
}

void	ft_isnegatif(int *signptr)
{
	if (*signptr % 2 == 0)
		*signptr = 0;
	else
		*signptr = 1;
}

char	*ft_clean(char *str, int *signptr)
{
	int	i;
	char	*clean_str;
	int	j;

	i = 0;
	j = 0;
	while (str[i] <= 32)
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			*signptr++;
		else
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		clean_str[j] = str[i];
		j++;
		i++;
	}
	clean_str[j] = '\0';
	ft_isnegatif(signptr);
	return (clean_str);
}

int	main(int argc, char **argv)
{
	int	sign;
	int	nbtrue;
	int	*signptr;
	int	*nbtrueptr;

	sign = 0;
	nbtrue = 0;
	signptr = &sign;
	nbtrueptr = &nbtrue;
	if (argc < 2)
		ft_error(1);
	if (argc > 3)
		ft_error(2);
	ft_nowhatwesearched(argv[1], nbtrueptr); 
	if (nbtrue == 0) 
		ft_error(3);
	ft_clean(argv[1], signptr);
	if (sign == 1)
		ft_error(4);
}
