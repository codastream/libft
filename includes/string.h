#ifndef STRING_H
# define STRING_H

int					ft_isalnum(int c);
int					ft_ischarforenvvar(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
bool				ft_isemptychar(char c);
bool				ft_isemptystr(char *s);
bool				ft_isnumstr(char *s);
int					ft_isprint(int c);
char				**ft_split(char const *s, char c);
char				**ft_split_str(char const *s, char *charset);
char				**ft_split_skip(char const *s, char **charsets);
char				*ft_strcat(char *dest, char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strchri(const char *s, unsigned char c);
int					ft_strcharsi(char *str, char *searchedchars);
int					ft_strstri(char *str, char **searched);
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

# endif
