#include <stdlib.h>
#include <stdio.h>

char	*ft_wordplace(char *str, int end, int start)
{
	int i = 0;
	char *s2  = malloc(sizeof(char) * (end - start) + 2);
	while(start <= end)
	{
		s2[i] = str[start];
		i++;
		start++;
	}
	s2[i] = '\0';

	return (s2);

}

int	ft_countword(char *str, char charset)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while(str[i])
	{
		if (str[i] != charset)
		{
			count++;
		}
		i++;
	}
	return (count + 1);
}




char	**ft_split(char *str, char charset)
{
	char **tab;
	int	line;
	int	i = 0;
	line = 0;
	int y = 0;	
	
	if (str[0] == '\0' || str == NULL)
	{
		tab = malloc(sizeof(char *));
		tab[0] = malloc(1);
		tab[0][0] = '\0';
		return (tab);
	}
	line = ft_countword(str, charset);
	tab = malloc(sizeof(char *) * (line + 1));
	if (tab == NULL)
		return (tab);

	int start = 0;
	int end = 0;
	while(str[i])
	{
		if (str[i] == charset)
		{
			end = i - 1;
			tab[y] = ft_wordplace(str, end, start);
			start = i + 1;
			y++;
		}
		i++;
	}
	tab[y] = ft_wordplace(str, i - 1, start);
	y++;
	tab[y] = NULL;

	return (tab);

}
#include <stdio.h>
int	main()
{
	char *str= "     ";
	char **tab;
	int i = 0;
	tab = ft_split(str, ' ');

		while (tab[i] != NULL)
		{
			printf("%s\n", tab[i]);
			i++;
		}
	return (0);
}
