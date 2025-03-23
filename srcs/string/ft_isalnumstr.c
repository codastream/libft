
#include "libft.h"

int	ft_isalnumstr(char *s)
{
	int	i;

	i = 0;
	if (!s || ft_strlen(s) == 0)
		return (0);
	while (s[i])
	{
		if (!ft_isalnum(s[i]))
			return (0);
		i++;
	}
	return (1);
}

bool ft_isenvvarkeystr(char *s)
{
	int	i;

	i = 0;
	if (!s || ft_strlen(s) == 0)
		return (false);
	while (s[i])
	{
		if (i == 0 && ft_isdigit(s[i]))
			return (false);
		if (!ft_ischarforenvvar(s[i]))
			return (false);
		i++;
	}
	return (true);
}
