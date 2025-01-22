/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:09:00 by fpetit            #+#    #+#             */
/*   Updated: 2025/01/22 17:52:24 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "splitter.h"

void	add_sep(t_splitter *splitter, char **seps, size_t *i, char **splitted)
{
	int 	j;
	int		e;
	size_t	len_sep;
	char	*s;

	s = splitter->s;
	j = 0;
	while (seps[j])
	{
		len_sep = ft_strlen(seps[j]);
		if (!ft_strncmp(&s[*i], seps[j], len_sep))
		{
			if (!ft_isemptystr(seps[j]))
			{
				e = ft_count_2dchar_null_ended(splitted);
				ft_printf("adding at index #%d\t%s\n", e, seps[j]);
				splitted[e] = ft_strdup(seps[j]);
				check_malloc(splitter, splitted, splitted[e]);
			}
			*i += len_sep;
		}
		j++;
	}
}

void	count_sep(char *sep, size_t *i, int *count)
{
	size_t	len;

	if (!ft_isemptystr(sep))
		*count += 1;
	len = ft_strlen(sep);
	*i += len;
}

char	*get_sep(char *s, char **seps)
{
	int		j;
	size_t	len_sep;

	j = 0;
	while (seps[j])
	{
		len_sep = ft_strlen(seps[j]);
		if (!ft_strncmp(s, seps[j], len_sep))
			return (seps[j]);
		j++;
	}
	return (NULL);
}
