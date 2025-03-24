NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c \
	   map_parse.c \
	   map_validate.c \
	   utils.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@$(RM) $(OBJS)
fclean: clean
	@$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re