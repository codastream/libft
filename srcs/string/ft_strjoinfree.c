
#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int	value)
{
	char	*result;
	result = ft_strjoin(s1, s2);
	if (!result)
		return (NULL);
	if (value == 1 || value == 3)
		free(s1);
	if (value == 2 || value == 3)
		free(s2);
	return (result);
}
