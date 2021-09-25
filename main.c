#include "ft_printf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*c;

	(void)argc;
	c = "|abcdefg|";
	if (ft_printf("|%010s|", NULL) == printf("|%010s|", NULL))
		ft_printf("%s\n", "ok");
}
