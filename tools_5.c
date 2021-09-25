#include "ft_printf.h"

char	*ft_hash(char *arg, char *flags)
{
	if (ft_strlen(arg) && arg[0] == '0'
		&& arg[1] == '0' && !ft_strchr(flags, '.') && !isonly0(arg))
	{
		if (ft_strchr(flags, 'x'))
			arg[1] = 'x';
		if (ft_strchr(flags, 'X'))
			arg[1] = 'X';
		return (arg);
	}
	if (ft_strchr(flags, 'x') && arg[0] && !isonly0(arg))
		arg = ft_strjoin(ft_strdup("0x"), arg);
	if (ft_strchr(flags, 'X') && arg[0] && !isonly0(arg))
		arg = ft_strjoin(ft_strdup("0X"), arg);
	return (arg);
}

char	*numberjoin(char *c, char *arg, int cas, int size)
{
	int	f;

	f = 0;
	if (!cas)
	{
		if (*c == '0' && arg[0] == '-')
		{
			arg[0] = *c;
			f = 1;
		}
		while (0 <= --size)
			arg = ft_strjoin(ft_strdup(c), arg);
		if (f)
			arg[0] = '-';
		return (arg);
	}
	while (0 <= --size)
		arg = ft_strjoin(arg, ft_strdup(c));
	return (arg);
}

char	*ft_number(char *arg, char *flags, char *c, int cas)
{
	char	*nbr;
	int		n;
	int		size;

	n = 0;
	while (cas == 1 && flags[n] != '-')
		n++;
	while ((flags[n] < '1' || flags[n] > '9') && flags[n] && flags[n] != '.')
		n++;
	nbr = ft_substr(flags, n, ft_strlen(flags) - n - 1);
	n = ft_atoi(nbr);
	free(nbr);
	size = ft_strlen(arg);
	if (n <= size)
		return (arg);
	if ((ft_strchr(flags, 'c') && arg[0] == 0)
		|| (ft_strchr(flags, '+') && c[0] == '0'))
		size++;
	arg = numberjoin(c, arg, cas, n - size);
	return (arg);
}

char	*ft_dot(char *arg, char *flags)
{
	char	*nbr;
	int		n;
	int		size;

	n = 0;
	while (flags[n] != '.')
		n++;
	while ((flags[n] < '1' || flags[n] > '9') && flags[n])
		n++;
	nbr = ft_substr(flags, n, ft_strlen(flags) - n - 1);
	n = ft_atoi(nbr);
	free(nbr);
	size = ft_strlen(arg);
	if (arg[0] == '0' && !n)
		return (ft_strdup(""));
	if ((n >= size && ft_strchr(flags, 's'))
		|| (n < size && !ft_strchr(flags, 's')))
		return (arg);
	if (ft_strchr(flags, 's'))
		return (ft_dot_nbr(arg, n));
	if (arg[0] == '-')
		n++;
	arg = numberjoin("0", arg, 0, n - size);
	return (arg);
}

char	*ft_plus_space(char *arg, char *flags, char *c)
{
	if (arg[0] == '0' && c[0] == ' ' && !ft_strchr(flags, '.') && iszero(flags))
	{
		arg[0] = ' ';
		return (arg);
	}
	if (!ft_strchr(arg, '-') && (ft_strchr(flags, 'i')
			|| ft_strchr(flags, 'd')))
		return (ft_strjoin(ft_strdup(c), arg));
	return (arg);
}
