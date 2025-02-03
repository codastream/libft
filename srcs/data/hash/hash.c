/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:24:27 by fpetit            #+#    #+#             */
/*   Updated: 2025/02/03 15:25:22 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_prime_above(int n)  // NOLINT
{
	if (ft_is_even(n))  // NOLINT
		n++;
	while (!ft_is_prime(n))
		n += 2;
	return (n);
}

t_hash	*ft_hash_init(int size)
{
	int			capacity;
	t_keyval	**keyvals;
	t_hash		*hash;

	hash = ft_calloc(1, sizeof(t_hash));
	if (!hash)
		return (NULL);
	capacity = get_prime_above(size);
	hash->capacity = capacity;
	keyvals = ft_calloc(capacity, sizeof (t_keyval *));
	if (!keyvals)
		return (NULL);
	hash->keyvals = keyvals;
	hash->elements_nb = 0;
	ft_hash_reset(hash);
	return (hash);
}

int	ft_hash_update(t_hash *hash, char *key, void *new_value)
{
	unsigned int	index;
	t_keyval		*current;

	index = hashcode(hash, key);
	if (!hash->keyvals[index])
		return (EXIT_FAILURE);
	current = hash->keyvals[index];
	current->value = new_value;
}

/*
 * returns 0 if the value has been inserted for this key
 */
int	ft_hash_insert(t_hash *hash, char *key, void *value)
{
	unsigned int	index;
	t_keyval		*new_keyval;
	t_keyval		*current;

	new_keyval = new_node(key, value);
	index = hashcode(hash, key);
	if (!hash->keyvals[index])
		hash->keyvals[index] = new_keyval;
	else
	{
		current = hash->keyvals[index];
		while (current->next)
			current = current->next;
		current->next = new_keyval;
	}
	hash->elements_nb++;
	return (EXIT_SUCCESS);
}

/*
 * returns value of the node at matching hashed index
 * and with matching key
 * returns NULL if not found
 */
void	*ft_hash_get(t_hash *hash, char *key)
{
	unsigned int	index;
	t_keyval		*current;

	index = hashcode(hash, key);
	current = hash->keyvals[index];
	while (current)
	{
		if (!ft_strcmp(current->key, key))
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

void	free_keyval(t_keyval *keyval)
{
	free(keyval->key);
	free(keyval);
}

/*
 * returns 1 if no value for this key
 * returns 0 if has been deleted
 */
int	ft_hash_remove(t_hash *hash, char *key)
{
	unsigned int	index;
	t_keyval		*current;
	t_keyval		*previous;

	index = hashcode(hash, key);
	previous = NULL;
	current = hash->keyvals[index];
	if (!current)
		return (EXIT_FAILURE);
	while (current)
	{
		if (!ft_strcmp(current->key, key))
		{
			if (!previous)
				hash->keyvals[index] = current->next;
			else
				previous->next = current->next;
			free_keyval(current);
			hash->elements_nb--;
			return (EXIT_SUCCESS);
		}
		previous = current;
		current = current->next;
	}
	return (EXIT_FAILURE);
}
