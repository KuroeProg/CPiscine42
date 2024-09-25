#include <unistd.h>


int	ft_strlen(char *str)
{
	int	i;
	i = 0;
	while(str[i])
		i++;
	return i;
}


char	*rev_print(char *str)
{
	int size = 0;
	size = ft_strlen(str);
	size--;
	while(size >= 0)
	{
		write(1, &str[size], 1);
		size--;
	}
	write(1, "\n", 1);
	return (str);
}


int	main()
{
	char *str[100];
       rev_print("Will never fade away");
}

