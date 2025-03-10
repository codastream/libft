
#include "libft.h"

int	ft_isalnumstr(char *s)
{
	int	i;

	i = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i])
	{
		if (!ft_isalnum(s[i]))
			return (0);
		i++;
	}
	return (1);
}
