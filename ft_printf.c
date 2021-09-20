#include "ft_printf.h"

int ft_printf(const char *to_print, ...)
{
	t_int tab;
	va_list parameters;

	va_start(parameters, to_print);
	tab.i = 0;
	tab.size = 0;
	while (to_print[tab.i])
  {
		if (to_print[tab.i] == '%')
    {
			tab.i++;
      tab = ft_detector(parameters, to_print, tab.i, tab.size);
		}
    else
		{
      	ft_putchar(to_print[tab.i]);
				tab.i++;
				tab.size++;
		}
	}
	va_end(parameters);
	return (tab.size);
}
