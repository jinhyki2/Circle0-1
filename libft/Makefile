CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRCS = ft_strdup.c ft_calloc.c ft_isalpha.c ft_itoa.c ft_memmove.c\
	   ft_putnbr_fd.c ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c\
	   ft_atoi.c ft_isascii.c ft_memchr.c ft_memset.c ft_putstr_fd.c\
	   ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_bzero.c ft_isdigit.c\
	   ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strlcat.c ft_strncmp.c\
	   ft_substr.c ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c\
	   ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
			 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
MAKE = make
ALL = mandatory
BONUS = for_bonus
INC = libft.h

.PHONY : all clean fclean re bonus

all : $(ALL)

bonus : $(BONUS)

$(NAME) : $(OBJS)
	ar -cr $(NAME) $(OBJS)

$(ALL) : $(OBJS)
	ar -cr $(NAME) $(OBJS)
	@rm -f $(BONUS)
	@touch $@

$(BONUS) : $(OBJS_BONUS)
	ar -cr $(NAME) $(OBJS_BONUS)
	@rm -f $(ALL)
	@touch $@

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I $(INC)

clean :
	rm -f $(OBJS) $(OBJS_BONUS) $(ALL) $(BONUS)

fclean :
	rm -f $(OBJS) $(OBJS_BONUS) $(NAME) $(ALL) $(BONUS)

re : 
	$(MAKE) fclean 
	$(MAKE) all
