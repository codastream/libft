/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:24:27 by fpetit            #+#    #+#             */
/*   Updated: 2025/01/29 19:08:38 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
