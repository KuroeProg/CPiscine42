#include <stdio.h>
#include <limits.h>

int	ft_atoi(char *str)
{
	int i;
	int sign = 1;
	int result = 0;

	i = 0;
	if (!str || !str[0])
		return 0;
	while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0'&& str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	main()
{
	printf("%s\n", ft_atoi("=875469-879854woe8pigyhlfba;kwdjn]jh8[w94gpuirbjeofj0hqg8wvoteUAGdj3e]") == atoi("=875469-879854woe8pigyhlfba;kwdjn]jh8[w94gpuirbjeofj0hqg8wvoteUAGdj3e]") ? "SUCCESS" : "FAILURE");
}
