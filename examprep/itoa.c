#include <stdlib.h>

char	*ft_recursif(int nbr, char *tab)
{
	if (nbr > 9)
	{
		tab = ft_recursif(nbr / 10, tab);
		tab = ft_recursif(nbr % 10, tab);
	}
	else
	{
		*tab = nbr + '0';
		tab++;
	}
	return (tab);
}

char	*ft_itoa(int nbr)
{
	char *tab;
	int i = 0;
	int size = 0;


	if (nbr == -2147483648)
	{
		tab = (char *)malloc(sizeof(char *) * 12);
		tab = "-2147483648";
		return (tab);
	}
	int copie = nbr;
	while (copie != 0)
	{
		copie = copie / 10;
		size++;
	}
	if (nbr < 0)
	{
		nbr = nbr * - 1;
		size++;
		tab = malloc(sizeof(char *) * size + 1);
		tab[0] = '-';
		ft_recursif(nbr, tab + 1);
	}
	else
	{
		tab = malloc(sizeof(char *) * size + 1);
		ft_recursif(nbr, tab);
	}
	tab[size] = '\0';
	return (tab);


}

#include <stdio.h>

int	main(void)
{
	printf("%s", ft_itoa(42));
}
