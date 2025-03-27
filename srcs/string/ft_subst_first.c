/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subst_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:50:50 by fpetit            #+#    #+#             */
/*   Updated: 2025/03/27 14:51:26 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy(char *dest, char *src, int *i, int *j)
{
	dest[*j] = src[*i];
	(*j)++;
	(*i)++;
}

static void	add_string_final(char *s, int i)
{
	if (s[i] != '\0')
		s[i] = '\0';
}

static void	replace_str(char *s, char *replaced, char *to_replace, \
		char *replacement)
{
	int		i;
	int		j;
	size_t	len_to_r;
	size_t	len_r;

	len_to_r = ft_strlen(to_replace);
	len_r = ft_strlen(replacement);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && ft_strncmp((const char *)&s[i], to_replace, \
			len_to_r) != 0)
			copy(replaced, s, &i, &j);
		replaced[j] = '\0';
		if (s[i] && !ft_strncmp((const char *)&s[i], to_replace, len_to_r))
		{
			ft_strcat(replaced, replacement);
			i += len_to_r;
			j += len_r;
		}
		while (s[i])
			copy(replaced, s, &i, &j);
	}
	add_string_final(replaced, j);
}

char	*ft_subst_first(char *s, char *to_replace, char *replacement)
{
	size_t	len_to_r;
	size_t	len_r;
	size_t	len_s;
	int		count_occ;
	char	*replaced;

	if (!s)
		return (NULL);
	if (!to_replace)
		return (s);
	len_s = ft_strlen(s);
	len_to_r = ft_strlen(to_replace);
	len_r = ft_strlen(replacement);
	count_occ = 1;
	replaced = ft_calloc(len_s - (len_to_r * count_occ) + \
		(len_r * count_occ) + 1, sizeof(char));
	if (!replaced)
		return (NULL);
	replace_str(s, replaced, to_replace, replacement);
	return (replaced);
}
