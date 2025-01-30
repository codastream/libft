#ifndef HASH_H
# define HASH_H

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

t_hash				*ft_init_hash(int size);
void				ft_hash_insert_if_noval(t_hash *hash, int key, void *value);
int					ft_hash_remove(t_hash *hash, int key);
void				ft_print_hashstr(t_hash *hash);

# endif
