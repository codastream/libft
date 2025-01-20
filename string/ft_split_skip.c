/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_skip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:27:06 by fpetit            #+#    #+#             */
/*   Updated: 2025/01/20 20:32:00 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

typedef struct s_delimiter
{
	char	*opening;
	char	*closing;
	int		level;
	bool	is_closed;
}	t_delimiter;

/*
 * if found in s, returns the index of that string in list
 */
int	get_index_of_matching_string(char *s, char **list)
{
	int		i;
	size_t	len;

	i = 0;
	while (list[i])
	{
		len = ft_strlen(list[i]);
		if (!ft_strncmp(s, list[i], len))
			return (i);
		i++;
	}
	return (-1);
}

bool	is_closing(char *s, t_delimiter *delim)
{
	size_t	len;

	len = ft_strlen(delim->closing);
	if (!ft_strncmp(s, delim->closing, len))
		return (true);
	return (false);
}

bool	is_opening(char *s, t_delimiter *delim)
{
	size_t	len;

	len = ft_strlen(delim->opening);
	if (!ft_strncmp(s, delim->opening, len))
		return (true);
	return (false);
}

int	get_index_of_delimiter(bool (*f) (char *, t_delimiter *), char *s, t_delimiter **delims)
{
	int		i;

	i = 0;
	while (delims[i])
	{
		if (f(s, delims[i]))
			return (i);
		i++;
	}
	return (-1);
}

/*
 * we consider there is a delimiter in two cases
 * if s starts with the opening part of a delimiter pair
 * AND if that delimiter is in closed state
 * or
 * if s starts with the closing part of a delimiter pair
 * AND if that delimiter is in open state
 * otherwise, we return NULL
 */
char	*check_if_delimiter(const char *s, t_delimiter **delims)
{
	int		i;
	size_t	len;

	i = 0;
	while (delims[i])
	{
		len = ft_strlen(delims[i]->opening);
		if (!ft_strncmp(s, delims[i]->opening, len) && delims[i]->is_closed)
			return (delims[i]->opening);
		len = ft_strlen(delims[i]->closing);
		if (!ft_strncmp(s, delims[i]->closing, len) && !delims[i]->is_closed)
			return (delims[i]->closing);
		i++;
	}
	return (NULL);
}

void	move_while_seps(const char *s, char **seps, size_t *i)
{
	int		j;
	size_t	len_sep;

	j = 0;
	while (seps[j] && s[*i])
	{
		len_sep = ft_strlen(seps[j]);
		if (!ft_strncmp(&s[*i], seps[j], len_sep))
			*i += len_sep;
		j++;
	}
}

bool	is_not_sep(const char *s, char **seps)
{
	int		j;
	size_t	len_sep;

	j = 0;
	while (seps[j])
	{
		len_sep = ft_strlen(seps[j]);
		if (ft_strncmp(s, seps[j], len_sep))
			j++;
		else
			return (false);
	}
	return (true);
}

bool	can_split(t_delimiter **delims)
{
	int		i;

	i = 0;
	while (delims[i])
	{
		if (delims[i]->is_closed == false)
			return (false);
		i++;
	}
	return (true);
}

void	update_delim_status(char *s, t_delimiter **delims, size_t *i)
{
	int		index_opening;
	int		index_closing;
	if (!s)
		return ;
	index_closing = get_index_of_delimiter(is_closing, s, delims);
	index_opening = get_index_of_delimiter(is_opening, s, delims);
	if (index_closing != -1)
	{
		delims[index_closing]->is_closed = true;
	}
	else if (index_opening != -1)
	{
		delims[index_opening]->is_closed = false;
	}
	*i += ft_strlen(s);
}

static char	**init_splitted(const char *s, char **charsets, t_delimiter **delims)
{
	int		count;
	size_t	i;
	char	**splitted;

	if (!s)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i])
	{
		move_while_seps(s, charsets, &i);
		if (s[i] && can_split(delims))
			count++;
		while (s[i] && check_if_delimiter(&s[i], delims))
			update_delim_status(check_if_delimiter(&s[i], delims), delims, &i);
		while (s[i] && is_not_sep(&s[i], charsets) && !check_if_delimiter(&s[i], delims))
			i++;
	}
	splitted = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!splitted)
		return (NULL);
	return (splitted);
}

static void	*ft_free(char **splitted, int e)
{
	while (e > 0)
	{
		free(splitted[e]);
		e--;
	}
	free(splitted);
	return (NULL);
}

static void	*fill_splitted(const char *s, char **charsets, t_delimiter **delims, char **splitted)
{
	int		e;
	size_t	i;
	size_t	j;

	i = 0;
	e = 0;
	while (s[i])
	{
		move_while_seps(s, charsets, &i);
		j = 0;
		while (s[i + j] && is_not_sep(&s[i + j], charsets))
		{
			update_delim_status(check_if_delimiter(&s[i + j], delims), delims, &j);
			if (can_split(delims))
				j++;
		}
		if (j > 0)
		{
			splitted[e] = ft_substr(s, i, j);
			if (!splitted[e])
				return (ft_free(splitted, e));
			e++;
		}
		i += j;
	}
	splitted[e] = NULL;
	return (splitted);
}

// static size_t	move_to_word_end(char const *s, size_t *i, char *charset, bool _can_split)
// {
// 	size_t	j;

// 	move_while_seps(s, charset, i);
// 	while (s[i])
// 	{

// 	}
// 	j = 0;
// 	while (s[*i + j] && !get_index_of_matching_string(s[*i + j], charset))
// 		(j)++;
// 	return (j);
// }

t_delimiter	*new_delimiter(char *opening, char *closing)
{
	t_delimiter	*new;

	new = ft_calloc(1, sizeof(t_delimiter));
	if (!new)
		return (NULL);
	new->opening = ft_strdup(opening);
	new->closing = ft_strdup(closing);
	new->level = 0;
	new->is_closed = true;
	return (new);
}

t_delimiter	**init_quote_delimiters(void)
{
	t_delimiter **delims;
	int			nb_delims;
	int			i;

	nb_delims = 2;
	delims = ft_calloc(nb_delims + 1, sizeof(t_delimiter *));
	if (!delims)
		return (NULL);
	i = 0;
	delims[0] = new_delimiter("\"", "\"");
	delims[1] = new_delimiter("'", "'");
	delims[2] = NULL;
	return (delims);
}

void	reset_delim_close_status(t_delimiter **delims)
{
	int		i;

	i = 0;
	while (delims[i])
	{
		delims[i]->is_closed = true;
		i++;
	}
}

/*
 * requires that all literal delimiters (quotes) are closed
 */
char	**ft_split_skip(char const *s, char **charsets)
{
	int			e;
	size_t		i;
	size_t		j;
	t_delimiter	**delims;
	char		**splitted;

	delims = init_quote_delimiters();
	splitted = init_splitted(s, charsets, delims);
	if (!splitted)
		return (NULL);
	reset_delim_close_status(delims);
	fill_splitted(s, charsets, delims, splitted);
	return (splitted);
}

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
}
