/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:21:23 by revanite          #+#    #+#             */
/*   Updated: 2023/07/07 02:19:21 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<unistd.h>
# include	<stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	(42)
# endif

typedef struct s_spec
{
	unsigned char	left_justify;
	unsigned char	zero_pad;
	unsigned long	precision;
	unsigned long	field;
	unsigned char	hash;
	unsigned char	space;
	unsigned char	plus;
	unsigned char	length;
	unsigned char	specifier;
	unsigned char	dot;
}	t_spec;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t nmemb, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);

int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char	*dest, char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
int		ft_isspace(int c);
void	ft_putstr(char *s);
void	ft_putnbr_ll(long long int n);
void	ft_putnbr_ull(unsigned long long int n);
char	*ft_itoa_ll(long long int n);
char	*ft_itoa_ull(unsigned long long int n);
char	*ft_itoa_oct(unsigned long long int n);
char	*ft_itoa_hex(unsigned long long int n);
void	ft_str_tolower(char *s);
void	ft_str_toupper(char *s);
long	ft_atoi_l(const char *str);
char	**ft_split_quotes(char const *s, char c);

int		ft_printf(const char *s, ...);
void	ft_printf_c(t_spec *spec, int *count, va_list list);
void	ft_printf_s(t_spec *spec, int *count, va_list list);
void	sign(t_spec *spec, int *c, va_list l, char *(*f)(long long));
void	usgn(t_spec *spec, int *c, va_list l, char *(*f)(unsigned long long));
void	pntr(t_spec *spec, int *c, va_list l, char *(*f)(unsigned long long));
void	handle_specifier(const char **s, int *count, va_list list);
void	null_spec(t_spec *spec);
void	print_specifier(t_spec *spec, int *count, va_list list);
void	putchar_counter(char c, int *counter);
void	print_prefix(t_spec *s, int *c);
void	print_field(t_spec *s, int *c, long long *f);
void	zeroes(t_spec *spec, int *c, unsigned long len);
void	hash(t_spec *spec, int *c, unsigned long len, unsigned long long d);
void	ft_putnstr(const char *s, size_t n);
void	prcnt(t_spec *spec, int *count);

char	*get_next_line(int fd);
char	*ft_recalloc(char **line, size_t size);
char	*ft_strncat(char *dest, char *src, size_t n);
long	find_nl(const char *buffer, int opt);
int		ft_mem(char **s, int c, size_t n, int opt);
void	leftovers(char **buffer, char **line, int opt, size_t len);
void	shift_buffer(char **buffer);

#endif  //      LIBFT_H