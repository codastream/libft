/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:27:06 by fpetit            #+#    #+#             */
/*   Updated: 2025/01/22 16:14:37 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "splitter.h"

void	add_elem(t_splitter *splitter, char **splitted, int len, size_t *i)
{
	int	e;

	e = ft_count_2dchar_null_ended(splitted);
	splitted[e] = ft_substr(splitter->s, *i, len);
	check_malloc(splitter, splitted, splitted[e]);
	*i += len + 1;
}
void	count_word(t_splitter *splitter, size_t *i, int *count)
{
	size_t	len;
	char	*s;

	s = splitter->s;
	len = 0;
	while (s[*i + len] && is_outside_delims(splitter->delims) \
		&& !get_delimiter(&s[*i + len], splitter->delims, 'a') \
		&& !get_sep(&s[*i + len], splitter->seps))
		len++;
	if (len > 0)
	{
		*count += 1;
		ft_printf("word outside "" and sep : new count: %d @ %s\n", *count, &s[*i]);
		*i += len;
	}
}
void	add_word_outside_delims(t_splitter *splitter, size_t *i, char **splitted)
{
	size_t	len;
	char	*s;

	s = splitter->s;
	len = 0;
	while (s[*i + len] && is_outside_delims(splitter->delims) \
		&& !get_delimiter(&s[*i], splitter->delims, 'a') \
		&& !get_sep(&s[*i], splitter->seps))
		len++;
	if (len > 0)
	{
		add_elem(splitter, splitted, len, i);
	}
}

static char	**init_splitted(t_splitter *splitter, char *s, char **seps, t_delimiter **delims)
{
	int			count;
	size_t		i;
	char		**splitted;

	if (!s)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && get_sep(&s[i], seps))
		{
			ft_printf("count_sep - new count %d @ %s\n", count + 1, &s[i]);
			count_sep(get_sep(&s[i], seps), &i, &count);
		}
		while (s[i] && get_delimiter(&s[i], delims, 'a'))
			count_delim(splitter, delims, &i, &count);
		// while (s[i] && get_sep(&s[i], seps))
		// 	count_sep(get_sep(&s[i], seps), &i, &count);
		count_word(splitter, &i, &count);
	}
	ft_printf("count: %d\n", count);
	splitted = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!splitted)
		return (NULL);
	return (splitted);
}

static void	*fill_splitted(t_splitter *splitter, char **seps, t_delimiter **delims, char **splitted)
{
	int		e;
	size_t	i;
	char	*test;
	char	*s;

	i = 0;
	e = 0;
	s = splitter->s;
	while (s[i])
	{
		test = get_sep(&s[i], seps);
		while (is_outside_delims(delims) && test)
		{
			add_sep(splitter, seps, &i, splitted);
			test = get_sep(&s[i], seps);
		}
		while (s[i] && get_delimiter(&s[i], delims, 'a'))
			add_if_new_delim(splitter, splitted, &i);
		while (s[i] && is_outside_delims(delims) && !get_sep(&s[i], seps))
			i++;
	}
	splitted[e] = NULL;
	return (splitted);
}

/*
 * requires that all literal delimiters (quotes) are closed
 */
char	**ft_split_skip(const char *str, char **seps)
{
	t_splitter 	*splitter;
	char		**splitted;

	splitter = init_splitter(str, seps);
	splitted = init_splitted(splitter, splitter->s, splitter->seps, splitter->delims);
	check_malloc(splitter, splitted, splitted);
	reset_delim_close_status(splitter->delims);
	fill_splitted(splitter, splitter->seps, splitter->delims, splitted);
	splitted = splitter->splitted;
	free_splitter(splitter);
	return (splitted);
}

