#include <stdlib.h>
#include <stdio.h>

int	count_words(char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(str[i])
	{
		if (str[i] == charset)
			count++;
		i++;
	}
	return (count + 1);
}

int	ft_checklen(char *str, char charset)
{
	int	i;
	int	len;

	i = 0;
	while (str[i])
	{
		len = 0;
		while (str[i] != charset && str[i])
		{
			len++;
			i++;
		}
		if (count_words(str, charset) != len)
			return (0);
		i++;
	}
	return (1);
}

char	**ft_split(char *str)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (count_words(str, '*') + 1));
	if (!map || ft_checklen(str, '*') == 0)
		return (NULL);

	while (i < count_words(str,'*'))
	{
		map[i] = malloc(sizeof(char) * (count_words(str, '*') + 1));
		if (!(map[i]))
			return (NULL);
		i++;
	}
	map[i] = NULL;
	
	return (map);
}

/*int	main(int argc, char **argv)
{
	int	i;
	char	**tab;
	if (argc < 2)
		return 0;
	else
		tab = ft_split(argv[1]);
	while (i < 1)
	{
		printf("%s\n", tab[i]);
		i++;
	}


}*/


