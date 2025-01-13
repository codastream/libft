/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:28:20 by fpetit            #+#    #+#             */
/*   Updated: 2024/12/16 16:34:19 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_is_prime(int n)
{
	int	i;

	if (n == 1 || n == 0)
		return (false);
	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (false);
		i++;
	}
	return (true);
}
