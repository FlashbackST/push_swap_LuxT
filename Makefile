NAME	= libftprintf.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I.
SRCS	= ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunsignednbr.c ft_atoi.c ft_puthex_lower.c ft_puthex_upper.c ft_putptr.c ft_printf.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
