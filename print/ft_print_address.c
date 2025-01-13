/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:27:44 by fpetit            #+#    #+#             */
/*   Updated: 2024/11/27 12:34:39 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_address(intptr_t address)
{
	int		count;

	count = 0;
	if (address == 0)
	{
		count += ft_print_str("(nil)");
	}
	else
	{
		count = ft_print_str("0x");
		count += ft_print_hexa(address, 0);
	}
	return (count);
}
