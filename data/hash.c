/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:24:27 by fpetit            #+#    #+#             */
/*   Updated: 2024/12/22 16:08:08 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_prime_above(int n)
{
	if (ft_is_even(n))
		n++;
	while (!ft_is_prime(n))
		n += 2;
	return (n);
}

t_hash	*init_hash(int size)
{
	int			i;
	int			capacity;
	t_keyval	*keyvals;
	t_hash		*hash;

	hash = malloc(sizeof(t_hash));
	if (!hash)
		return (NULL);
	capacity = get_prime_above(size);
	keyvals = ft_calloc(capacity, sizeof (t_hash));
	if (!keyvals)
		return (NULL);
	i = 0;
	while (i < capacity)
	{
		keyvals[i].key = -1;
		keyvals[i].value = NULL;
		i++;
	}
	hash->capacity = capacity;
	hash->elements_nb = 0;
	hash->keyvals = keyvals;
	return (hash);
}

int	hashcode(t_hash *hash, int key)
{
	return (key % hash->capacity);
}

void	ft_hash_insert_if_noval(t_hash *hash, int key, void *value)
{
	int			index;
	t_keyval	*keyvals;

	keyvals = hash->keyvals;
	index = hashcode(hash, key);
	if (keyvals[index].value == NULL)
	{
		keyvals[index].key = key;
		keyvals[index].value = value;
		hash->elements_nb++;
	}
}

/*
 * returns 1 if no value for this key
 * returns 0 if has been deleted
 */
int	ft_hash_remove(t_hash *hash, int key)
{
	int			index;
	t_keyval	*keyvals;

	keyvals = hash->keyvals;
	index = hashcode(hash, key);
	if (keyvals[index].value == NULL)
		return (EXIT_FAILURE);
	else
	{
		keyvals[index].key = -1;
		keyvals[index].value = NULL;
		hash->elements_nb--;
		return (EXIT_SUCCESS);
	}
}
