/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:24:22 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/15 13:33:06 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_base(int value, int base);
int				ft_atoi_base(const char *str, int str_base);

int				ft_printf(const char *format, ...);

void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);

char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
int				ft_strequ(const char *s1, const char *s2);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
int				ft_strnlen(char *s, int max);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char *s);
char			**ft_strsplit(const char *s, char c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s);

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);

int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_abs(int num);

void			ft_putchar(char c);
void			ft_putwchar(wchar_t c);
void			ft_putstr(const char *s);
void			ft_putnstr(const char *s, size_t len);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
void			ft_putnbrbase(size_t nbr, char *base);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(const void *content, size_t content_size);
t_list			*ft_create_elem(void *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstaddb(t_list *begin_list, void *content, size_t size);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *list, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_lstsize(t_list *begin_list);
void			ft_print_list(t_list *list);

int				ft_count_words(const char *s, char c);
int				ft_num_length(size_t n);
int				ft_num_length_base(size_t value, char *base);
int				ft_only_digit(const char *s);
int				ft_tochar(char *s, char c);
int				ft_max(int n1, int n2);

int				ft_printf(const char *format, ...);
#endif
