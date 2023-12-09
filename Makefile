NAME = pipex

LIBFT_PATH = ./libft/
LIBFT =	$(LIBFT_PATH)libft.a
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address (commented out for now)
OTHERFLAGS = -L$(LIBFT_PATH) -lft -o $(NAME)

SRCS = ./sources/pipex.c	./sources/parsing.c	./sources/utils.c\
		./sources/process_generator.c	./sources/path_handeling.c\
		./sources/redirections.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus : CFLAGS:= $(CFLAGS) -DLIMIT_ARGS=0
bonus : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		cc $(CFLAGS) $(ARGS) $(OBJS) $(OTHERFLAGS)

$(LIBFT):
		@make -sC $(LIBFT_PATH)

clean:
	rm -f $(OBJS)
	@make -sC $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	@make -sC $(LIBFT_PATH) fclean
	

re: fclean all

.PHONY: all clean fclean re bonus