/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:50:02 by fpetit            #+#    #+#             */
/*   Updated: 2024/12/12 18:11:18 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_integer_fd(int fd, int n)
{
	char	*s;
	int		count;

	s = ft_itoa(n);
	count = ft_print_str_fd(fd, s);
	free(s);
	return (count);
}
