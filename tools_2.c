#include "ft_printf.h"

void	ft_lstlast(t_tab *lst, char *arg, char *flags)
{
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = ft_lstnew(arg, flags);
}

t_tab	*ft_lstnew(char *arg, char *flags)
{
	t_tab	*element;

	element = malloc(sizeof(t_tab));
	if (!element)
		return (NULL);
	element->flags = flags;
	element->arg = arg;
	element->next = NULL;
	return (element);
}

char	*ft_intarg(int arg, char format)
{
	char	*c;

	c = NULL;
	if (format == 'c')
	{
		c = malloc(sizeof(char));
		c[0] = arg;
		c[1] = 0;
		return (c);
	}
	else
		return (ft_itoa(arg));
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*c;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	c = NULL;
	c = malloc(sizeof(char) * (i + 1));
	if (!c)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[j])
		c[i++] = s2[j++];
	c[i] = '\0';
	free(s1);
	free(s2);
	return (c);
}

char	*ft_xarg(unsigned int arg, int f)
{
	char	*h;

	if (f == 'x')
		h = "0123456789abcdef";
	else
		h = "0123456789ABCDEF";
	if (arg >= 16)
		return (ft_strjoin(ft_xarg(arg / 16, f), ft_intarg(h[arg % 16], 'c')));
	else
		return (ft_intarg(h[arg % 16], 'c'));
}
