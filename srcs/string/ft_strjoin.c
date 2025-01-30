/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:48:23 by fpetit            #+#    #+#             */
/*   Updated: 2025/01/29 19:08:38 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strslen(char **tab, int size)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(tab[i]);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		i;
	size_t	len;

	len = 0;
	if (size > 0)
		len = ft_strslen(strs, size) + (size -1) * ft_strlen(sep);
	joined = ft_calloc((len + 1), sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (i < size)
	{
		joined = ft_strcat(joined, strs[i]);
		if (i < size - 1)
			joined = ft_strcat(joined, sep);
		i++;
	}
	return (joined);
}
