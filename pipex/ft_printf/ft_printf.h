/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:14:48 by yait-oul          #+#    #+#             */
/*   Updated: 2023/03/17 02:33:10 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_print_ptr_int(long num);
int		ft_print_ptr(unsigned long long int num);

int		check_cases(va_list ap, const char format);

void	ft_putnbr_pos(long long nb);

int		to_hex_add(unsigned int nb);
void	to_hex_maj(unsigned int nb);
void	to_hex(unsigned int nb);
int		ft_cut(char *s, int index);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		to_hex_address_ptr(unsigned long nb);
int		afficher_num(long long nb);
void	to_hexs_ptr(unsigned long nb);

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printt_ptr(unsigned int ptr);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, const char format);
int		ft_printpercent(void);

void	ft_put_ptr(unsigned int num);
int		ft_ptr_len(unsigned int num);
char	*ft_uitoa(unsigned int n);
int		ft_num_len(unsigned int num);
void	ft_put_hex(unsigned int num, const char format);
int		ft_hex_len(unsigned int num);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
//char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
//char	*ft_strstr(char *str, char *to_find);
char	*ft_strnstr(const char *big, const char *little, size_t len);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_atoi(const char *str);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		to_hex_address(unsigned int nb);

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);

void	ft_strdel(char **as);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);

void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char const *s);
void	ft_putnbr(long long n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int		ft_abs(int nb);
int		ft_islower(int c);
int		ft_isupper(int c);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbrdl(int n);
char	*ft_strnew(size_t size);
char	**ft_split(const char *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int nb);

#endif
