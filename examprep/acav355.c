#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;

	if (argc != 2)
		return 0;
	while (argv[1][i])
	{
		if ( i % 5 == 0 && i % 3 == 0)
			write(1, "5", 1);
		if ( i % 5 == 0 )
			write(1, "3", 1);
		if ( i % 3 == 0)
			write(1, "5", 1);
		else
		{
			write(1, &argv[1][i], 1);
		}
		i++;
	}
}

