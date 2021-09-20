#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbrU(unsigned int nbr);
int ft_printf(const char *to_print, ...);
typedef struct s_int
{
  int size;
  int i;
} t_int;
t_int ft_detector(va_list parameters, const char *type, int i, int size);
#endif
