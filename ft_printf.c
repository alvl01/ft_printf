#include "ft_printf.h"

static int	ft_tab_printf(const char *to_print, t_tab *tab)
{
	t_tab	*tab2;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (to_print[i])
	{
		if (to_print[i] != '%')
			ft_putchar(to_print[i], &len);
		else
		{
			i += ft_strlen(tab->flags) - 1;
			ft_flags(tab->arg, tab->flags, &len);
			tab2 = tab;
			tab = tab->next;
			free(tab2->flags);
			free(tab2);
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *to_print, ...)
{
	int		i;
	int		len;
	t_tab	*tab;
	va_list	parameters;

	tab = NULL;
	i = -1;
	va_start(parameters, to_print);
	tab = ft_tabedit(parameters, to_print, i, tab);
	va_end(parameters);
	i = 0;
	len = 0;
	return (ft_tab_printf(to_print, tab));
}
