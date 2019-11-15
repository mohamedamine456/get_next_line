/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 22:46:36 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/15 22:58:13 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*str;

	if (s1 == 0)
		return (0);
	len = ft_strlen(s1);
	i = 0;
	str = (char *)malloc(len * sizeof(char) + 1);
	if (str == 0)
		return (0);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = 0;
	if (s)
	{
		if (start > len && len != 0)
			len = 0;
		new_s = (char *)malloc(len + 1);
		if (new_s == 0)
			return (0);
		while (i < (int)len)
		{
			new_s[i] = s[start + i];
			i++;
		}
		new_s[i] = '\0';
	}
	return (new_s);
}

char	*ft_resize(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2 != 0)
	{
		s = malloc(ft_strlen(s2) + BUFFER_SIZE + 1);
		while (s2[i] != '\0')
		{
			s[i] = s2[i];
			i++;
		}
	}
	else
		s = malloc(BUFFER_SIZE + 1);
	while (s1[j] != '\0')
	{
		s[i] = s1[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}

int		check_line(char *str)
{
	int i;

	i = 0;
	if (str != 0)
		while (str[i] != '\0')
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
	return (0);
}
