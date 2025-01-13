/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:48:18 by fpetit            #+#    #+#             */
/*   Updated: 2024/11/28 15:25:44 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*duplicated;

	len = ft_strlen(s);
	duplicated = malloc(sizeof(char) * (len + 1));
	if (!duplicated)
		return (NULL);
	ft_memcpy(duplicated, s, len);
	duplicated[len] = '\0';
	return (duplicated);
}
