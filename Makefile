CC=gcc
SRCS=main.c\
	push_swap.c\
	operation_s.c\
	operation_r.c\
	operation_rr.c\
	ft_split.c\
	ft_string.c\
	setting_num.c\
	go_error.c\
	ft_sort.c
OBJS=$(SRCS:.c=.o)
NAME=push_swap
HEADER=-I .
#CFLAG=-Wall -Werror -Wextra -fsanitize=address
CFLAG=-fsanitize=address

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $< $(HEADER)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
