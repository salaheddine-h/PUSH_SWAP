/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:11:41 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/10 00:04:12 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// 1st Part - libc functions
int					ft_isalpha(int arg);
int					ft_isdigit(int arg);
int					ft_isalnum(int arg);
int					ft_isascii(int arg);
int					ft_isprint(int arg);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int value, size_t n_byt);
void				ft_bzero(void *s, size_t n_bytes);
void				*ft_memcpy(void *dest, const void *src, size_t n_bytes);
void				*ft_memmove(void *dest, const void *src, size_t n_bytes);
size_t				ft_strlcpy(char *dest, const char *src, size_t len);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_toupper(int arg);
int					ft_tolower(int arg);
char				*ft_strchr(const char *s, int arg);
char				*ft_strrchr(const char *s, int arg);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t n_elm, size_t elm_size);
char				*ft_strdup(const char *str);

// 2nd Part - Additional functions
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// 3rd - Bonus Part
typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(int value);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(int));

// 4th - Recently Added
long				ft_atol(const char *str);
int					ft_isspace(int c);

#endif
