/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:15:33 by fpetit            #+#    #+#             */
/*   Updated: 2024/11/27 12:39:53 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len_trim;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_calloc(sizeof(char), 1));
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	if (i > len)
		return (ft_calloc(sizeof(char), 1));
	j = len - 1;
	while (ft_strchr(set, s1[j]))
		j--;
	len_trim = j + 1 - i;
	return (ft_substr(s1, i, len_trim));
}
