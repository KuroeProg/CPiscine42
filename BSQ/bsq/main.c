#include <unistd.h>
#include <fcntl.h>

int	ft_countline(char *buf)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			count++;
		i++;
	}
	return (count);
}



int	main(int argc, char **argv)
{
	int	fd;
	char	buf[2000];
	int	size;
	int	i;
	char	**map;
	int	line;
	int	j;

	i = 1;
	if (argc < 2)
	{
		return 0;
	}
	while (i < argc)
	{
		j = 0;
		fd = open(argv[i], O_RDONLY);
		if(fd == -1)
			return (1);
		size = read (fd, buf, 2000);
		line = ft_countline(buf);
		map = malloc((char *) * line + 1);
		while (j < buf)
		{
			map[j] = malloc(sizeof(char) * buf + 1);
			j++;
		}
			


		write(1, buf, size);
		close(fd);
		i++;
	}
		return 0;
}
