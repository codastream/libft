/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:45:29 by fpetit            #+#    #+#             */
/*   Updated: 2024/11/27 12:39:50 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;
	int		mc;

	mc = c % 256;
	idx = ft_strlen(s);
	while (idx > 0)
	{
		if (s[idx] == mc)
			return ((char *)(&s[idx]));
		idx--;
	}
	if (idx == 0 && s[idx] == mc)
		return ((char *)(&s[idx]));
	return (NULL);
}
