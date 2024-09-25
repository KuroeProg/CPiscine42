int	ft_strlen(char *str)
{	
	while (str[i])
		i++;
	return (i);
}


char	*ft_strdup(char *src)
{
	char *dest;
	int size;
	int i = 0;
	size = ft_strlen(src);
	dest = malloc(sizeof(char *) * (size + 1));
	if (dest == NULL)
	{
		return (dest);
	}
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
