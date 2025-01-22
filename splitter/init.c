/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:03:32 by fpetit            #+#    #+#             */
/*   Updated: 2025/01/22 16:18:01 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "splitter.h"


t_delimiter	*new_delimiter(char *opening, char *closing)
{
	t_delimiter	*new;

	new = ft_calloc(1, sizeof(t_delimiter));
	if (!new)
		return (NULL);
	new->opening = ft_strdup(opening);
	new->closing = ft_strdup(closing);
	new->level = 0;
	new->is_closed = true;
	return (new);
}

void	reset_delim_close_status(t_delimiter **delims)
{
	int		i;

	i = 0;
	while (delims[i])
	{
		delims[i]->is_closed = true;
		i++;
	}
}

t_delimiter	**init_quote_delimiters(void)
{
	t_delimiter **delims;
	int			nb_delims;
	int			i;

	nb_delims = 2;
	delims = ft_calloc(nb_delims + 1, sizeof(t_delimiter *));
	if (!delims)
		return (NULL);
	i = 0;
	delims[0] = new_delimiter("\"", "\"");
	delims[1] = new_delimiter("'", "'");
	delims[2] = NULL;
	return (delims);
}

t_splitter	*init_splitter(const char *str, char **seps)
{
	t_splitter	*splitter;

	splitter = ft_calloc(1, sizeof(t_splitter));
	if (!splitter)
		return (NULL);
	splitter->s = (char *) str;
	splitter->index = 0;
	splitter->count = 0;
	splitter->delims = NULL;
	splitter->delims = init_quote_delimiters();
	splitter->seps = seps;
	check_malloc(splitter, NULL, splitter->delims);
	return (splitter);
}
