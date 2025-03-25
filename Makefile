NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LFLAGS = -L/usr/include/minilibx-linux -lmlx -lX11 -lXext

SRCS = main.c \
	   map_parse.c \
	   map_validate.c \
	   map_render.c \
	   carbage_collector.c \
	   printing.c \
	   move_fct.c \
	   read_file.c \
	   set_up_game.c \
	   utils.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@$(RM) $(OBJS)
fclean: clean
	@$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
