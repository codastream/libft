/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:45:29 by fpetit            #+#    #+#             */
/*   Updated: 2024/11/27 12:39:47 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	len_little = ft_strlen(little);
	i = 0;
	if (!big && len == 0)
		return (NULL);
	if (len_little == 0)
		return ((char *)(big));
	while (*big && i < len)
	{
		if (i + len_little <= len && ft_strncmp(big, little, len_little) == 0)
			return ((char *)(big));
		big++;
		i++;
	}
	return (NULL);
}
