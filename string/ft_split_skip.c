/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_skip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:27:06 by fpetit            #+#    #+#             */
/*   Updated: 2025/01/21 18:26:15 by fpetit           ###   ########.fr       */
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

t_delimiter	*get_delimiter(char *s, t_delimiter **delims, char delim_type)
{
	int		i;
	size_t	len_open;
	size_t	len_close;

	i = 0;
	while (delims[i])
	{
		len_open = ft_strlen(delims[i]->opening);
		len_close = ft_strlen(delims[i]->closing);

		if (delim_type == 'o' && !ft_strncmp(s, delims[i]->opening, len_open))
			return (delims[i]);
		if (delim_type == 'c' && !ft_strncmp(s, delims[i]->closing, len_close))
			return (delims[i]);
		if (delim_type == 'a' && (!ft_strncmp(s, delims[i]->opening, len_open) \
			|| !ft_strncmp(s, delims[i]->closing, len_close)))
			return (delims[i]);
		i++;
	}
	return (NULL);
}

void	add_sep(char *s, char **seps, size_t *i, char **splitted)
{
	int 	j;
	int		e;
	size_t	len_sep;

	j = 0;
	while (seps[j])
	{
		len_sep = ft_strlen(seps[j]);
		if (!ft_strncmp(&s[*i], seps[j], len_sep))
		{
			e = ft_count_2dchar_null_ended(splitted);
			splitted[e] = ft_strdup(seps[j]);
			if (!splitted[e])
				ft_free(splitted, e);
			*i += len_sep;
		}
		j++;
	}
}

void	count_sep(char *sep, size_t *i, int *count)
{
	size_t	len;

	*count += 1;
	len = ft_strlen(sep);
	*i += len;
}

char	*get_sep(char *s, char **seps)
{
	int		j;
	size_t	len_sep;

	j = 0;
	while (seps[j])
	{
		len_sep = ft_strlen(seps[j]);
		if (!ft_strncmp(s, seps[j], len_sep))
			return (seps[j]);
		j++;
	}
	return (NULL);
}

bool	can_split_delim(t_delimiter **delims, t_delimiter *delim)
{
	int		i;

	i = 0;
	if (delim->is_closed)
	while (delims[i])
	{
		if (delims[i] != delim && !delims[i]->is_closed)
			return (false);
		i++;
	}
	return (false);
}

bool	is_outside_delims(t_delimiter **delims)
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

int	count_len_till_closing_delim(char *s, t_delimiter *delim)
{
	int len;

	len = 1;
	while (s[len] && ft_strncmp(&s[len], delim->closing, ft_strlen(delim->closing)))
		len++;
	if (!ft_strncmp(&s[len], delim->closing, ft_strlen(delim->closing)))
		return (len);
	else
		return (-1);
}

void	add_if_new_delim(char *s, t_delimiter **delims, size_t *i, char **splitted)
{
	t_delimiter *opening_delim;
	t_delimiter *closing_delim;
	int			e;
	int			len_delim_token;

	opening_delim = get_delimiter(&s[*i], delims, 'o');
	closing_delim = get_delimiter(&s[*i], delims, 'c');
	if (opening_delim)
	{
		if (is_outside_delims(delims))
		{
			opening_delim->is_closed = false;
			e = ft_count_2dchar_null_ended(splitted);
			len_delim_token = count_len_till_closing_delim(&s[*i], opening_delim);
			if (len_delim_token > 0)
			{
				splitted[e] = ft_substr(s, *i, len_delim_token);
				if (!splitted[e])
					ft_free(splitted, e);
			}
		}
		*i += ft_strlen(opening_delim->opening);
	}
	else if (closing_delim)
	{
		if (!closing_delim->is_closed)
			closing_delim->is_closed = true;
		*i += ft_strlen(closing_delim->closing);
	}
}

void	count_if_delim_closed(char *s, t_delimiter **delims, size_t *i, int *count)
{
	int		index_opening;
	int		index_closing;
	if (!s)
		return ;
	index_closing = get_index_of_delimiter(is_closing, s, delims);
	index_opening = get_index_of_delimiter(is_opening, s, delims);
	if (index_closing != -1 && delims[index_closing]->is_closed == false)
	{
		delims[index_closing]->is_closed = true;
	}
	else if (index_opening != -1 && delims[index_opening]->is_closed == true)
	{
		delims[index_opening]->is_closed = false;
		*count += 1;
	}
	*i += ft_strlen(s);
}

// update count - i - toggle is_closed
void update_count_and_toggle_delim(char *s, t_delimiter **delims, size_t *i, int *count)
{
	t_delimiter *opening_delim;
	t_delimiter *closing_delim;
	int			len_delim_token;

	opening_delim = get_delimiter(&s[*i], delims, 'o');
	closing_delim = get_delimiter(&s[*i], delims, 'c');
	if (opening_delim)
	{
		if (is_outside_delims(delims))
		{
			opening_delim->is_closed = false;
			len_delim_token = count_len_till_closing_delim(&s[*i], opening_delim);
			if (len_delim_token > 0) // if closing delim found we count 1 space for the split
			{
				*count += 1;
				*i += len_delim_token + 1;
			}
			opening_delim->is_closed = true;
		}
		else
			*i += ft_strlen(opening_delim->opening);
	}
	else if (closing_delim)
	{
		if (!closing_delim->is_closed)
			closing_delim->is_closed = true;
		*i += ft_strlen(closing_delim->closing);
	}
}

static char	**init_splitted(char *s, char **seps, t_delimiter **delims)
{
	int			count;
	size_t		i;
	char		**splitted;
	char		*test;

	if (!s)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i])
	{
		test = get_sep(&s[i], seps);
		while (is_outside_delims(delims) && test)
		{
			count_sep(test, &i, &count);
			test = get_sep(&s[i], seps);
		}
		while (s[i] && get_delimiter(&s[i], delims, 'a'))
			update_count_and_toggle_delim(s, delims, &i, &count);
		while (s[i] && !is_outside_delims(delims))
			i++;
		while (s[i] && is_outside_delims(delims) && !get_sep(&s[i], seps))
			i++;
	}
	ft_printf("count: %d\n", count);
	splitted = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!splitted)
		return (NULL);
	return (splitted);
}


static void	*fill_splitted(char *s, char **seps, t_delimiter **delims, char **splitted)
{
	int		e;
	size_t	i;
	char	*test;

	i = 0;
	e = 0;

	while (s[i])
	{
		test = get_sep(&s[i], seps);
		while (is_outside_delims(delims) && test)
		{
			add_sep(test, seps, &i, splitted);
			test = get_sep(&s[i], seps);
		}
		while (s[i] && get_delimiter(&s[i], delims, 'a'))
			add_if_new_delim(s, delims, &i, splitted);
		while (s[i] && is_outside_delims(delims) && !get_sep(&s[i], seps))
			i++;
	}
	splitted[e] = NULL;
	return (splitted);
}

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
	delims[1] = new_delimiter("1", "1");
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

void	free_delimiters(t_delimiter **delims)
{
	int		i;

	i = 0;
	while (delims[i])
	{
		free(delims[i]->opening);
		free(delims[i]->closing);
		free(delims[i]);
		i++;
	}
	free(delims);
}

/*
 * requires that all literal delimiters (quotes) are closed
 */
char	**ft_split_skip(const char *str, char **seps)
{
	char		*s;
	t_delimiter	**delims;
	char		**splitted;

	s = (char *)str;
	delims = init_quote_delimiters();
	splitted = init_splitted(s, seps, delims);
	if (!splitted)
		return (NULL);
	reset_delim_close_status(delims);
	fill_splitted(s, seps, delims, splitted);
	free_delimiters(delims);
	return (splitted);
}

