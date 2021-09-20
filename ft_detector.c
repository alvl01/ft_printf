#include "ft_printf.h"

t_int ft_detector(va_list parameters, const char *type, int i, int size)
{
	t_int	tab;

	if(type[i] == 'c')
		size += ft_putchar(va_arg(parameters, int));
	else if(type[i] == 's')
		size += ft_putstr(va_arg(parameters, char *));
/*	else if(type[i] == 'p')
		size += ft_putpointer(va_arg(parameters, void *));*/
	else if(type[i] == 'd' || type[i] == 'i')
		size += ft_putnbr(va_arg(parameters, int));
	else if(type[i] == 'u')
		size += ft_putnbrU(va_arg(parameters, unsigned int));
/*	else if(type[i] == 'x')
		size += ft_puthexnbrlow(va_arg(parameters, int));
	else if(type[i] == 'X')
		size += ft_puthexnbrup(va_arg(parameters, int));*/
	else if(type[i] == '%')
		size += ft_putchar('%');
	i++;
	tab.i = i;
	tab.size = size;
	return (tab);
}
