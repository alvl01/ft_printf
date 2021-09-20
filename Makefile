SRCS	= ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbrU.c ft_detector.c
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
			gcc -o exe ${OBJS} main.o
all:		${NAME}
clean:
			${RM} ${OBJS} ${OBJS_B}
fclean:		clean
			${RM} ${NAME}
re:			fclean all bonus
.PHONY: bonus all clean fclean re
