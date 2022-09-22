NAME = so_long

FT_PRINTF = ft_printf/libftprintf.a
FT_PRINTF_DIR = ft_printf/

GNL = get_next_line/getnextline.a
GNL_DIR = get_next_line/


CC = cc

CFLAGS = -Wall -Wextra -Werror

LINKS = -l mlx -framework OpenGL -framework Appkit

SRCS = $(wildcard *.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(FT_PRINTF) $(GNL) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(FT_PRINTF) $(GNL) $(LINKS) -o $(NAME) $(OBJS)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

clean:
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(MAKE) clean -C $(GNL_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(MAKE) fclean -C $(GNL_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
