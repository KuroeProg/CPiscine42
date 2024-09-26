#include <stdlib.h>

int	ft_strlen(int min, int max)
{
	int size = max - min;
	return (size);
}

int	*ft_positif(int start, int end)
{
	int i = 0;
	int size = 0;
	int *tab;

	while (end + size != start)
		size++;
	tab = (int *)malloc(sizeof(int *) * size + 5);
	while (end != start)
	{
		tab[i] = end;
		end++;
		i++;
	}
	tab[i] = start;
	return (tab);
}

int	*ft_negatif(int start, int end)
{
	int i = 0;
	int size = 0;
	int *tab;

	while (end - size != start)
		size++;
	tab = (int *)malloc(sizeof(int *) * size + 5);
	while (end != start)
	{
		tab[i] = end;
		end--;
		i++;
	}
	tab[i] = start;
	return (tab);
}


int     *ft_rrange(int start, int end)
{
	int	*tab;
	int i = 0;
	int size = 0;

	if (start > end)
		tab = ft_positif(start, end);
	else if (start < end)
		tab = ft_negatif(start, end);
	else if (start == end)
	{
		tab = malloc(sizeof(int *) * 1);
		tab[i] = end;
	}
	return (tab);
}

#include <stdio.h>
int	main(void)
{
	int i = 0;

	int start = 10;
	int end = 10;

	int	*tab;
	tab = ft_rrange(start, end);

	while(i < 15)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}
