#include <unistd.h>

int	is_present(char *str1, char *str2, char c, int str1len, int str2len)
{
	int i = 0;
	int y = 0;
	while (str1[i] && i < str1len)
	{
		if (c == str1[i])
			return (1);
		i++;
	}
	while (str2[y] && y < str2len)
	{
		if (c == str2[y])
			return (1);
		y++;
	}
	return (0);
}


int	main(int argc, char **argv)
{

	int i = 0;
	int y = 0;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] && is_present(argv[1], argv[2], argv[1][i], i, y) == 0)
		{
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	while (argv[2][y])
	{
		if (argv[2][y] && is_present(argv[1], argv[2], argv[2][y], i, y) == 0)
		{
			write(1, &argv[2][y], 1);
		}
		y++;
	}
	write(1, "\n", 1);
}

