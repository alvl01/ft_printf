#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_tab
{
	char			*flags;
	char			*arg;
	struct s_tab	*next;
}	t_tab;
//tool_1.c
char	*ft_strchr(const char *s, int c);
int		check_prcnt(const char *to_print, int *i);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
//tools_2.c
t_tab	*ft_lstnew(char *arg, char *flags);
void	ft_lstlast(t_tab *lst, char *arg, char *flags);
char	*ft_intarg(int arg, char format);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_xarg(unsigned int arg, int format);
//tools_3.c
char	*ft_parg(unsigned long arg);
char	*ft_itoa(int n);
int		iszero(char *flags);
//tools_4.c
char	*ft_itoa_unsigned(unsigned int n);
int		ft_atoi(const char *str);
//tools_5.c
char	*ft_hash(char *arg, char *flags);
char	*numberjoin(char *c, char *arg, int cas, int size);
char	*ft_number(char *arg, char *flags, char *c, int cas);
char	*ft_dot(char *arg, char *flags);
char	*ft_plus_space(char *arg, char *flags, char *c);
//tools_6.c
char	*ft_dot_nbr(char *arg, int n);
char	*action(char c, int a1, unsigned int a2, unsigned long a3);
int		type_need(int c);
int		count_flags(int i, const char *to_print, int *start);
int		isonly0(char *arg);
//tabedit.c
t_tab	*ft_tabedit(va_list p, const char *to_print, int i, t_tab *tab);
//ft_printf.c
int		ft_printf(const char *to_print, ...);
//ft_flags.c
void	ft_flags(char *arg, char *flags, int *len);
//ft_putchar.c
void	ft_putchar(int c, int *len);
void	ft_putstr(char *str, int *len);
#endif
