#include <stdlib.h>

int	is_present(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	else
		return (0);
}

int     ft_strlen(char *str)
{
        int i = 0;
        while (str[i] && is_present(str[i]) == 0)
                i++;
        return (i);
}

int	ft_countword(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		while (str[i] && is_present(str[i]) == 1)
			i++;
		if (str[i] && is_present(str[i]) == 0)
		{
			count++;
			while(str[i] && is_present(str[i]) == 0)
				i++;
		}
	}
	return (count);
}

char	*ft_malloc(char *str, int strlen)
{
	int i = 0;
	char *str2 = NULL;
	str2 = (char *)malloc(sizeof(char *) * (strlen + 1));
	if (str == NULL)
		return NULL;
	while (i < strlen)
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

#include <stdio.h>

char	**ft_split(char *str)
{
	if (str == NULL)
		return NULL;
	int i = 0;
	char **tab = NULL;
	int wordnbr;
	int strlen = 0;
	int y = 0;

	wordnbr = ft_countword(str);
	tab = (char **)malloc(sizeof(char **) * (wordnbr + 1));
	if (tab == NULL)
		return (tab);
	while (str[i])
	{
		while (is_present(str[i]) == 1)
			i++;
		if (str[i])
		{
			strlen = ft_strlen(str + i);
			tab[y] = ft_malloc(str + i, strlen);
			if (tab[y] == NULL)
				return (tab);
			i = i + strlen;
			y++;
		}
	}
	tab[y] = 0;
	return (tab);
}

int main(void)
{

        int     i = 0;
        char str[] = " Ceci est un test     ";
        char **res = ft_split(str);
        while (i <= ft_countword(str))
        {
                printf("%d : %s\n", i,res[i]);
                i++;
        }

}
