#ifndef HASH_H
# define HASH_H

typedef struct s_keyval
{
	char			*key;
	void			*value;
	struct s_keyval	*next;
}	t_keyval;

typedef struct s_hash
{
	t_keyval	**keyvals;
	int			capacity;
	int			elements_nb;
}	t_hash;

unsigned int		hashcode(t_hash *hash, char *key);
t_keyval			*new_node(char *key, void *value);
void				ft_print_hashstr(t_hash *hash);
void				ft_hash_reset(t_hash *hash);

t_hash				*ft_hash_init(int size);
int					ft_hash_insert(t_hash *hash, char *key, void *value);
int					ft_hash_update(t_hash *hash, char *key, void *new_value);
void				*ft_hash_get(t_hash *hash, char *key);
int					ft_hash_remove(t_hash *hash, char *key);

# endif
