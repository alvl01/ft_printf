#include "ft_printf.h"

static int	nbr_length(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nbr;
  long  nbr2;

	nbr = n;
  nbr2 = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	if (nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
  return (nbr_length(nbr2));
}
