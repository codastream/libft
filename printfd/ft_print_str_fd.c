/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:24:27 by fpetit            #+#    #+#             */
/*   Updated: 2024/12/12 18:11:38 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_str_fd(int fd, const char *s)
{
	int		count;

	count = 0;
	if (!s)
	{
		count += ft_print_str_fd(fd, "(null)");
	}
	else
	{
		if (!*s)
			return (0);
		while (s[count])
		{
			write(fd, &s[count], 1);
			count++;
		}
	}
	return (count);
}
