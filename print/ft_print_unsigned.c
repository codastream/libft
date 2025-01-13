/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:36:44 by fpetit            #+#    #+#             */
/*   Updated: 2024/11/27 12:34:57 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_unsigned(unsigned int n)
{
	char	*s;
	int		count;

	s = ft_ltoa(n);
	count = ft_print_str(s);
	free(s);
	return (count);
}
