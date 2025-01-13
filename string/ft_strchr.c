/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:45:29 by fpetit            #+#    #+#             */
/*   Updated: 2024/11/27 12:39:13 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*s_pointer;
	int				mc;

	mc = c % 256;
	s_pointer = (unsigned char *) s;
	while (*s_pointer)
	{
		if (*s_pointer == mc)
			return ((char *)(s_pointer));
		s_pointer++;
	}
	if (*s_pointer == mc)
		return ((char *)(s_pointer));
	return (NULL);
}
