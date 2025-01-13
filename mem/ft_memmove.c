/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:45:29 by fpetit            #+#    #+#             */
/*   Updated: 2024/11/27 12:32:22 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * in case dest address overlaps src content,
 * we start copying from the end in order to keep src data available
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_cast;
	char	*src_cast;

	if (!dest && !src)
		return (0);
	dest_cast = (char *) dest;
	src_cast = (char *) src;
	if (dest <= src)
	{
		while (n--)
		{
			*dest_cast++ = *src_cast++;
		}
	}
	else if (dest > src)
	{
		dest_cast += n - 1;
		src_cast += n - 1;
		while (n--)
		{
			*dest_cast-- = *src_cast--;
		}
	}
	return (dest);
}
