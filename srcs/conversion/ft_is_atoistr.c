#include "libft.h"

/*
 * returns false if
 * - has other characters than digits, +, - or space
 * - has more than one consecutive + or -
 * - has non-digit characters after the digits
 * - exceeds INT_MIN or INT_MAX
 */
bool	is_atoi_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isnumstr(&str[i]))
		return (false);
	if (i > 0 && str[i - 1] == '-')
		return (true);
	else
		return (true);
}

/*
 * imperfect for negative numb
 */
bool	is_atoll_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isnumstr(&str[i]))
		return (false);
	if (i > 0 && str[i - 1] == '-')
		return (ft_atoull(&str[i]) <= (unsigned long long)LLONG_MAX + 1);
	else
		return (ft_atoull(&str[i]) <= LLONG_MAX);
}
