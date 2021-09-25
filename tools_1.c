#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	if (!str)
		return (0);
	while (*str)
	{
		str++;
		x++;
	}
	return (x);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c2;

	c2 = (unsigned char)c;
	while (*s)
	{
		if (*s == c2)
			return ((char *)s);
		s++;
	}
	if (!c2)
		return ((char *)s);
	return (NULL);
}

int	check_prcnt(const char *to_print, int *i)
{
	if (to_print[*i] != '%')
	{
		return (0);
	}
	(*i)++;
	return (1);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;
	int		len;

	len = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	cpy = (char *)malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (NULL);
	while (len--)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s) - 1)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start - 1)
		len = ft_strlen(s) - start ;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (len-- > 0)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
