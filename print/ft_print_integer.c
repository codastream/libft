/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:50:02 by fpetit            #+#    #+#             */
/*   Updated: 2024/11/27 12:34:50 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_integer(int n)
{
	char	*s;
	int		count;

	s = ft_itoa(n);
	count = ft_print_str(s);
	free(s);
	return (count);
}
