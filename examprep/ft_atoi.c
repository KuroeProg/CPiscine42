#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	i = 0;
	int result = 0;
	int sign = 0;
	while((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
	{
		i++;
	}
	if (str[i] == '-' && str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}

	return (result * sign);


}
