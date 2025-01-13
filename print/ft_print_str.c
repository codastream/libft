/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:24:27 by fpetit            #+#    #+#             */
/*   Updated: 2024/11/27 12:34:54 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_str(const char *s)
{
	int		count;

	count = 0;
	if (!s)
	{
		count += ft_print_str("(null)");
	}
	else
	{
		if (!*s)
			return (0);
		while (s[count])
		{
			write(1, &s[count], 1);
			count++;
		}
	}
	return (count);
}
