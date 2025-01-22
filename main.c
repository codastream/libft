#include "libft/libft.h"
#include "libft/splitter/splitter.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	(void) ac;
	char **charsets = ft_calloc(2, sizeof(char *));
	if (!charsets)
		return (1);
	charsets[0] = av[2];
	charsets[1] = NULL;
	char **splitted = ft_split_skip(av[1], charsets);
	ft_print_tabstr(splitted);
	free(charsets);
	ft_free_2d_char_null_ended(splitted);
}
