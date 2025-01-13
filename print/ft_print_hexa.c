/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:25:09 by fpetit            #+#    #+#             */
/*   Updated: 2024/11/27 12:34:47 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_hexa(unsigned long long n, int is_upper)
{
	char	*s;
	int		count;

	if (is_upper)
		s = ft_lutoa_base(n, "0123456789ABCDEF");
	else
		s = ft_lutoa_base(n, "0123456789abcdef");
	count = ft_print_str(s);
	free(s);
	return (count);
}
