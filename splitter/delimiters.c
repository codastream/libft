/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:05:35 by fpetit            #+#    #+#             */
/*   Updated: 2025/01/22 17:57:19 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "splitter.h"


// bool	is_closing(char *s, t_delimiter *delim)
// {
// 	size_t	len;

// 	len = ft_strlen(delim->closing);
// 	if (!ft_strncmp(s, delim->closing, len))
// 		return (true);
// 	return (false);
// }

// bool	is_opening(char *s, t_delimiter *delim)
// {
// 	size_t	len;

// 	len = ft_strlen(delim->opening);
// 	if (!ft_strncmp(s, delim->opening, len))
// 		return (true);
// 	return (false);
// }

// int	get_index_of_delimiter(bool (*f) (char *, t_delimiter *), char *s, t_delimiter **delims)
// {
// 	int		i;

// 	i = 0;
// 	while (delims[i])
// 	{
// 		if (f(s, delims[i]))
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// void	count_if_delim_closed(char *s, t_delimiter **delims, size_t *i, int *count)
// {
// 	int		index_opening;
// 	int		index_closing;
// 	if (!s)
// 		return ;
// 	index_closing = get_index_of_delimiter(is_closing, s, delims);
// 	index_opening = get_index_of_delimiter(is_opening, s, delims);
// 	if (index_closing != -1 && delims[index_closing]->is_closed == false)
// 	{
// 		delims[index_closing]->is_closed = true;
// 	}
// 	else if (index_opening != -1 && delims[index_opening]->is_closed == true)
// 	{
// 		delims[index_opening]->is_closed = false;
// 		*count += 1;
// 	}
// 	*i += ft_strlen(s);
// }

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
void	count_elem(size_t *i, int len, int *count)
{
	*count += 1;
	*i += len + 1;
}

// update count - i - toggle is_closed
void	count_delim(t_splitter *splitter, t_delimiter **delims, size_t *i, int *count)
{
	t_delimiter *opening_delim;
	t_delimiter *closing_delim;
	int			len_delim_token;
	char		*s;

	s = splitter->s;
	opening_delim = get_delimiter(&s[*i], delims, 'o');
	closing_delim = get_delimiter(&s[*i], delims, 'c');
	if (opening_delim)
	{
		if (is_outside_delims(delims))
		{
			opening_delim->is_closed = false;
			len_delim_token = count_len_till_closing_delim(&s[*i], opening_delim);
			if (len_delim_token > 0) // if closing delim found we count 1 space for the split
				count_elem(i, len_delim_token, count);
			opening_delim->is_closed = true;
		}
		else
			count_elem(i, ft_strlen(opening_delim->opening), count);
	}
	else if (closing_delim)
	{
		count_elem(i, ft_strlen(closing_delim->closing), count);
	}
}



void	add_if_new_delim(t_splitter *splitter, char **splitted, size_t *i)
{
	t_delimiter *opening_delim;
	t_delimiter *closing_delim;
	int			len_delim_token;

	opening_delim = get_delimiter(&splitter->s[*i], splitter->delims, 'o');
	closing_delim = get_delimiter(&splitter->s[*i], splitter->delims, 'c');
	if (opening_delim)
	{
		if (is_outside_delims(splitter->delims))
		{
			opening_delim->is_closed = false;
			len_delim_token = count_len_till_closing_delim(&splitter->s[*i], opening_delim);
			if (len_delim_token > 0)
				add_elem(splitter, splitted, len_delim_token, i);
			opening_delim->is_closed = true;
		}
		else
			add_elem(splitter, splitted, ft_strlen(opening_delim->opening), i);
	}
	else if (closing_delim)
	{
		// if (!closing_delim->is_closed)
		// 	closing_delim->is_closed = true;
		add_elem(splitter, splitted, ft_strlen(closing_delim->closing), i);
	}
}

