CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_util.c ft_itoa.c ft_itoah.c
OBJS = $(SRCS:.c=.o)
INC = ft_printf.h

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar -cr $(NAME) $(OBJS)

%.o : %.c
	cc $(CFLAGS) -o $@ -c $^ -I $(INC)

clean :
	rm -f $(OBJS)

fclean : 
	make clean
	rm -f $(NAME)

re : 
	make fclean
	make all
