/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:37:17 by fpetit            #+#    #+#             */
/*   Updated: 2024/11/27 12:2 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
# include <limits.h>
# include "gnl/get_next_line.h"
# include "colors.h"

# define PRINTF_ERROR -1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_keyval
{
	int		key;
	void	*value;
}	t_keyval;

typedef struct s_hash
{
	t_keyval	*keyvals;
	int			capacity;
	int			elements_nb;
}	t_hash;

bool				ft_has_unique_values_array(int *values, int size);
void				ft_quick_sort_tab(int *tab, int from, int to);
int					ft_count_2dchar_null_ended(char **tab);

int					ft_atoi_base(char *nbr, char *base);
int					ft_atoi(const char *nptr);
long				ft_atol(const char *nptr);
unsigned long long	ft_atoull(const char *nptr);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
bool				ft_is_out_of_int_range(char *nb);
char				*ft_itoa(int n);
char				*ft_ltoa(long n);
char				*ft_lutoa_base(unsigned long long n, char *base);
bool				is_valid_number_for_base(char *nbr, char *base);
bool				is_valid_base(char *base);
int					ft_hextoi(const char *nb);

void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);

t_hash				*ft_init_hash(int size);
void				ft_hash_insert_if_noval(t_hash *hash, int key, void *value);
int					ft_hash_remove(t_hash *hash, int key);
void				ft_print_hashstr(t_hash *hash);

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_free_2d_char_null_ended(char **tab);
void				ft_free_2d_generic(void **tab, int size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);

int					ft_print_address(intptr_t address);
void				print_array_int(int *tab, int size);
int					ft_print_char(int c);
int					ft_print_hexa(unsigned long long n, int is_upper);
int					ft_print_integer(int n);
int					ft_print_str(const char *s);
int					ft_print_unsigned(unsigned int n);
int					ft_printf(const char *s, ...);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_puterr(char *s);
void				ft_put_pink(char *msg);
void				ft_put_green(char *msg);
void				ft_put_yellow(char *msg);

int					ft_print_address_fd(int fd, intptr_t address);
int					ft_print_char_fd(int fd, int c);
int					ft_print_hexa_fd(int fd, unsigned long long n, \
						int is_upper);
int					ft_print_integer_fd(int fd, int n);
int					ft_print_str_fd(int fd, const char *s);
int					ft_print_unsigned_fd(int fd, unsigned int n);
int					ft_printfd(int fd, const char *s, ...);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
bool				ft_isemptychar(char c);
bool				ft_isemptystr(char *s);
bool				ft_isnumstr(char *s);
int					ft_isprint(int c);
char				**ft_split(char const *s, char c);
char				**ft_split_str(char const *s, char *charset);
char				*ft_strcat(char *dest, char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strchri(const char *s, unsigned char c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strjoin(int size, char **strs, char *sep);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little, \
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_subst(char *s, char *to_replace, char *replacement);

bool				ft_is_prime(int n);
bool				ft_is_even(int n);

#endif
