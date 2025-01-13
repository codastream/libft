/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:24:27 by fpetit            #+#    #+#             */
/*   Updated: 2024/12/22 16:00:28 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_hashstr(t_hash *hash)
{
	int			i;
	t_keyval	*keyvals;

	keyvals = hash->keyvals;
	i = 0;
	while (i < hash->capacity)
	{
		if (!keyvals[i].value)
			ft_printf("#%d -> NULL\n", keyvals[i].key);
		else
			ft_printf("#%d -> %s\n", i, keyvals[i].key, \
				(char *) keyvals[i].value);
		i++;
	}
}
