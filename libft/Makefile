NAME = libft.a

SRCS =	ft_toupper.c	ft_bzero.c	ft_tolower.c	ft_isalpha.c\
ft_strchr.c	ft_atoi.c	ft_isalnum.c	ft_isascii.c\
ft_isdigit.c	ft_isprint.c	ft_strncmp.c	ft_strlen.c\
ft_strrchr.c	ft_strlcpy.c	ft_strnstr.c	ft_strlcat.c\
ft_strdup.c	ft_memchr.c	ft_memmove.c	ft_calloc.c\
ft_memcmp.c	ft_memcpy.c	ft_memset.c	ft_substr.c	ft_split.c\
ft_strjoin.c	ft_strtrim.c	ft_putchar_fd.c	ft_putstr_fd.c\
ft_putendl_fd.c	ft_putnbr_fd.c	ft_strmapi.c	ft_striteri.c	ft_itoa.c\
ft_param.c	ft_adress.c	ft_printf.c	ft_putchar.c	ft_putnbr.c\
ft_putnbrhexa.c	ft_putstr.c	ft_putunsigned.c\
get_next_line.c	get_next_line_bonus.c	get_next_line_utils.c	get_next_line_utils_bonus.c\
str_finder.c	matrix_finder.c	coordinate_finder.c	matrix_sizer.c	matrix_printer.c\
matrix_dup.c	matrix_deleter.c	ft_strjoin_free.c	ft_intcmp.c


OBJS :=$(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -fPIE

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJS)
	ar -crs $@ $^

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all