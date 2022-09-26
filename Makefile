NAME = so_long

FT_PRINTF = ft_printf/libftprintf.a
FT_PRINTF_DIR = ft_printf/

CC = cc

CFLAGS = -Wall -Wextra -Werror

LINKS = -l mlx -framework OpenGL -framework Appkit

SRCS = $(wildcard *.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(FT_PRINTF) $(NAME)


$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LINKS) -o $(NAME) $(OBJS) $(FT_PRINTF)

clean:
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re