/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:28:53 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/25 18:10:29 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>

# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

int		ft_tolower(int c);								//libft
int		ft_toupper(int c);
void	*ft_memset(void *s, int c, size_t n);
int		ft_isalpha(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
int		ft_printf(const char *str, ...);					//ft_printf
void	ft_param(va_list *arg, char type, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr(long int nbr, int *len);
void	ft_putnbrhexa(unsigned int nbr, int *len, int lowup);
void	ft_putunsigned(unsigned int nbr, int *len);
void	ft_adress(unsigned long int ad, int *len);
char	*get_next_line(int fd);								//get_next_line
char	*ft_cleaner(char *str);
int		nlcheck(char *str);
char	*splitter(char *save);
char	*ft_strjoin_gnl(char *dest, char *src, int toread);
void	saver(char *content, char *save);
char	*stringbuilder(char *content, int toread, int fd);
int		str_finder(char *s, char *c);						//others
int		matrix_finder(char **mtx, char *s);
int		coordinate_finder(char **mtx, char c, char axle);
int		matrix_sizer(char **mtx, char d);
void	matrix_printer(char **mtx);
char	**matrix_dup(char **mtx);
void	matrix_deleter(char **mtx);
char	*ft_strjoin_free(char const *s1, char const *s2, int tofree);
int		ft_intcmp(int n1, int n2);

#endif