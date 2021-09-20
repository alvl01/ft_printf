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

int	ft_putnbrU(unsigned int nbr)
{
	if (nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
  return (nbr_length(nbr));
}
