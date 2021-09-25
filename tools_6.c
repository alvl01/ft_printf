#include "ft_printf.h"

char	*ft_dot_nbr(char *arg, int n)
{
	char	*nbr;

	nbr = ft_substr(arg, 0, n);
	free(arg);
	return (nbr);
}

char	*action(char c, int a1, unsigned int a2, unsigned long a3)
{
	char	*arg;

	arg = NULL;
	if (ft_strchr("dic", c))
		arg = ft_intarg(a1, c);
	else if (c == 'x' || c == 'X')
		arg = ft_xarg(a2, c);
	else if (c == 'u')
		arg = ft_itoa_unsigned(a2);
	else if (c == 'p')
		arg = ft_strjoin(ft_strdup("0x"), ft_parg(a3));
	else if (c == '%')
		arg = ft_strdup("%\0");
	return (arg);
}

int	type_need(int c)
{
	if (ft_strchr("dic", c))
		return (1);
	else if (ft_strchr("uxX", c))
		return (2);
	return (0);
}

int	count_flags(int i, const char *to_print, int *start)
{
	*start = i - 1;
	while (ft_strchr("-0.# +123456789", to_print[i]))
		i++;
	return (i);
}

int	isonly0(char *arg)
{
	while (*arg)
	{
		if (*arg != '0')
			return (0);
		arg++;
	}
	return (1);
}
