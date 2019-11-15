/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 22:46:19 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/15 22:58:03 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		*str;
	static char	*grd = 0;
	int			r;
	char		*tmp;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (grd == 0)
		grd = ft_strdup("");
	while (!(check_line(grd)))
	{
		r = read(fd, str, BUFFER_SIZE);
		str[r] = '\0';
		tmp = grd;
		grd = ft_resize(str, grd);
		free(tmp);
		tmp = NULL;
		if (r == 0)
			break ;
	}
	free(str);
	str = NULL;
	return (make_line(&grd, line));
}

int		make_line(char **grd, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	if (check_line(*grd) != 0)
	{
		while ((*grd)[i] != '\n')
			i++;
	}
	if (check_line(*grd))
	{
		tmp = *line;
		*line = ft_substr(*grd, 0, i);
		tmp = *grd;
		*grd = ft_strdup(*grd + i + 1);
		free(tmp);
		return (1);
	}
	*line = ft_strdup(*grd);
	free(*grd);
	*grd = NULL;
	return (0);
}
