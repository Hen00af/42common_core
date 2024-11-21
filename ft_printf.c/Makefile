CC = cc
FLAGS = -Wall -Werror -Wextra
NAME = ft_printf.a
SRCS = ft_printf
OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME):$(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
clean: 
	rm -f *.o
fclean:
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
