/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:50:50 by fpetit            #+#    #+#             */
/*   Updated: 2024/12/22 15:37:11 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	count_nb_of_to_replace(char *s, char *to_replace)
{
	int		count;
	char	*found;
	size_t	len_to_r;

	count = 0;
	len_to_r = ft_strlen(to_replace);
	while (ft_strnstr(found, to_replace, len_to_r))
	{
		found = ft_strnstr(found, to_replace, len_to_r);
		count++;
	}
	return (count);
}

void	replace_str(char *s, char *replaced, char *to_replace, \
		char *replacement)
{
	int		i;
	size_t	len_to_r;

	len_to_r = ft_strlen(to_replace);
	while (!ft_strncmp(s, to_replace, len_to_r))
	{
		ft_strcat(replaced, replacement);
		s += len_to_r;
	}
	i = 0;
	while (ft_strncmp(s, to_replace, len_to_r))
		i++;
	ft_strlcat(replaced, s, i);
}

char	*ft_subst(char *s, char *to_replace, char *replacement)
{
	size_t	len_to_r;
	size_t	len_r;
	size_t	len_s;
	int		count_occ;
	char	*replaced;

	len_to_r = ft_strlen(to_replace);
	len_r = ft_strlen(replacement);
	len_s = ft_strlen(s);
	count_occ = count_nb_of_to_replace(s, to_replace);
	replaced = ft_calloc(len_s - (len_to_r * count_occ) + \
		(len_r * count_occ) + 1, sizeof(char));
	if (!replaced)
		return (NULL);
	while (*s)
	{
		replace_str(s, replaced, to_replace, replacement);
	}
	*replaced = '\0';
	return (replaced);
}
