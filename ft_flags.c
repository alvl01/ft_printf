#include "ft_printf.h"

static char	*flags_interaction(char *flags, char *arg, char *c)
{
	if (ft_strchr(flags, '.'))
		arg = ft_dot(arg, flags);
	if (iszero(flags) && ft_strchr(flags, '+') && !ft_strchr(flags, '.'))
		return (ft_plus_space(ft_number(arg, flags, "0", 0), flags, "+"));
	if (ft_strchr(flags, '+'))
		return (ft_plus_space(arg, flags, "+"));
	if (c[0] == '0' && !ft_strchr(flags, '-'))
		return (ft_number(arg, flags, "0", 0));
	return (arg);
}

void	ft_flags(char *arg, char *flags, int *len)
{
	char	*c;
	int		i;

	i = ft_strlen(arg);
	c = " ";
	if (!arg)
		arg = ft_strdup("(null)");
	if (iszero(flags) && !ft_strchr(flags, '.'))
		c = "0";
	arg = flags_interaction(flags, arg, c);
	if (ft_strchr(flags, '#'))
		arg = ft_hash(arg, flags);
	if (ft_strchr(flags, ' ') && !ft_strchr(flags, '+'))
		arg = ft_plus_space(arg, flags, " ");
	if (ft_strchr(flags, 'c') && ft_strlen(arg) == 0 && ft_strchr(flags, '-'))
		ft_putchar(arg[0], len);
	if (ft_strchr(flags, '-'))
		arg = ft_number(arg, flags, " ", 1);
	else if (c[0] != '0')
		arg = ft_number(arg, flags, c, 0);
	if (ft_strchr(flags, 'c') && i == 0 && !ft_strchr(flags, '-'))
		ft_putchar(arg[0], len);
	ft_putstr(arg, len);
	free(arg);
}
