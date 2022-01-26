/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:08:39 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/16 12:08:42 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static void	ft_move_to_start(char buffer[], int i)
{
	int		j;

	j = 0;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		j++;
		i++;
	}
	buffer[j] = 0;
}

static int	ft_update_buffer(char **line, char buffer[])
{
	int		i;
	char	*temp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		*line = ft_strjoin_f(line, buffer);
		ft_bzero(buffer, BUFFER_SIZE);
		return (0);
	}
	else
	{
		i++;
		temp = ft_strndup(buffer, i);
		if (!temp)
			*line = NULL;
		else
			*line = ft_strjoin_f(line, temp);
		ft_move_to_start(buffer, i);
		free(temp);
		return (1);
	}
}

static int	ft_free_lines(char **line)
{
	if (!*line)
		return (1);
	if (!(*line)[0])
	{
		free(*line);
		return (1);
	}
	else
		return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (0 > read(fd, buffer, 0))
		return (NULL);
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = 0;
	if (ft_update_buffer(&line, buffer))
		return (line);
	while (read(fd, buffer, BUFFER_SIZE) == BUFFER_SIZE)
	{
		buffer[BUFFER_SIZE] = 0;
		i = 0;
		while (i < BUFFER_SIZE && buffer[i] != '\n')
			i++;
		if (ft_update_buffer(&line, buffer))
			return (line);
	}
	ft_update_buffer(&line, buffer);
	if (ft_free_lines(&line))
		return (NULL);
	return (line);
}
