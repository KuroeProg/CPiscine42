#include <unistd.h>

int	is_present(char *str, char c, int len)
{
	int i = 0;
	while (i < len)
	{
		if(str[i] == c)
			return 1;
		i++;
	}
	return 0;
}


int	main(int argc, char **argv)
{
	int i = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	while(argv[1][i])
	{
		if (argv[1][i] && is_present(argv[1], argv[1][i], i) == 0)
		{
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
}
