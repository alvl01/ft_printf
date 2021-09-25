#include "ft_printf.h"

t_tab	*ft_tabedit(va_list p, const char *to_print, int i, t_tab *tab)
{
	char	*arg;
	int		start;

	while (to_print[++i])
	{
		if (check_prcnt(to_print, &i))
		{
			i = count_flags(i, to_print, &start);
			if (type_need(to_print[i]) == 1)
				arg = action(to_print[i], va_arg(p, int), 0, 0);
			else if (to_print[i] == 's')
				arg = ft_strdup(va_arg(p, char *));
			else if (type_need(to_print[i]) == 2)
				arg = action(to_print[i], 0, va_arg(p, unsigned int), 0);
			else if (to_print[i] == 'p')
				arg = action(to_print[i], 0, 0, va_arg(p, unsigned long));
			else
				arg = action(to_print[i], 0, 0, 0);
			if (tab)
				ft_lstlast(tab, arg, ft_substr(to_print, start, i - start + 1));
			else
				tab = ft_lstnew(arg, ft_substr(to_print, start, i - start + 1));
		}
	}
	return (tab);
}
