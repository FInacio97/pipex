NAME = pipex

LIBFT_PATH = ./libft/
LIBFT =	$(LIBFT_PATH)libft.a
FLAGS = -Wall -Werror -Wextra
OTHERFLAGS = -L$(LIBFT_PATH) -lft -o $(NAME)

SRCS = ./sources/pipex.c	./sources/parsing.c	./sources/utils.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(LIBFT)
		cc $(FLAGS) $(OBJS) $(OTHERFLAGS)
$(LIBFT):
		@make -sC $(LIBFT_PATH)

clean:
	rm -f $(OBJS)
	@make -sC $(LIBFT_PATH) clean

fclean:
	rm -f $(NAME)
	@make -sC $(LIBFT_PATH) fclean

re:
	fclean all

.PHONY: all clean fclean re