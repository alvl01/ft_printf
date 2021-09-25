SRCS	= ft_printf.c ft_putchar.c ft_putstr.c ft_flags.c tabedit.c tools_6.c tools_5.c tools_4.c tools_3.c tools_2.c tools_1.c
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
CC		= gcc
RM		= rm -f
FLAGS	= -Wall -Werror -Wextra
.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			ar rc  ${NAME} ${OBJS}
			ranlib ${NAME}
main:		${OBJS}
			gcc -c main.c
			gcc ${OBJS} main.o
all:		${NAME}
clean:
			${RM} ${OBJS} ${OBJS_B}
fclean:		clean
			${RM} ${NAME}
re:			fclean all bonus
.PHONY: bonus all clean fclean re
