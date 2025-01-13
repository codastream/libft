/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:45:29 by fpetit            #+#    #+#             */
/*   Updated: 2024/11/27 12:28:40 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	skip_blanks_and_sign(const char **str)
{
	while (**str && ((**str >= 9 && **str <= 13) || **str == 32 || \
	**str == '+' || **str == '-'))
		++*str;
}

unsigned long long	ft_atoull(const char *nptr)
{
	unsigned long long	result;

	skip_blanks_and_sign(&nptr);
	result = 0;
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += (*nptr - '0');
		nptr++;
	}
	return (result);
}
