#include "ft_printf.h"

static int	nbr_length(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_itoa2(unsigned int n, int count, char *c)
{
	c[count] = '\0';
	while (count-- > 0)
	{
		c[count] = n % 10 + 48;
		n /= 10;
	}
	return (c);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*c;
	int		i;
	int		count;

	i = 0;
	c = NULL;
	count = nbr_length(n);
	c = malloc(sizeof(char) * (count + 1));
	if (!c)
		return (NULL);
	c = ft_itoa2(n, count, c);
	return (c);
}

static int	return_error(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	n;
	int		taille;
	long	i;
	long	sign;

	n = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
		sign = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	taille = i;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		n = n * 10 + (str[i++] - 48);
		if ((i - taille > 18
				&& (n > 9223372036854775807 || n < 1000000000000000000))
			|| i - taille > 19)
			return (return_error(sign));
	}
	return (sign * n);
}
