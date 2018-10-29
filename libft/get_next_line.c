/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:40:11 by amasol            #+#    #+#             */
/*   Updated: 2018/09/14 12:40:16 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_join_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	tmp = (char*)ft_memalloc(sizeof(char) * (i + j + 1));
	i = -1;
	while (s1 && s1[++i])
		tmp[i] = s1[i];
	if (s1)
		free(s1);
	j = -1;
	while (s2 && s2[++j])
		tmp[i + j] = s2[j];
	return (tmp);
}

static int		ft_check_line(char **stock, char **line)
{
	char	*str;
	char	*tmp;

	tmp = *stock;
	str = ft_strchr(*stock, '\n');
	if (!str)
		return (0);
	*str = '\0';
	*line = ft_strdup(*stock);
	*stock = ft_strdup(str + 1);
	free(tmp);
	return (1);
}

static int		ft_last_line(char **stock, char **line)
{
	*line = ft_strdup(*stock);
	free(*stock);
	*stock = NULL;
	if (*line[0] == '\0')
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char	*s[2048];
	char		buff[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || fd > 2048 || !line || BUFF_SIZE < 0)
		return (-1);
	if (s[fd] && ft_check_line(&(s[fd]), line))
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd])
			s[fd] = ft_join_free(s[fd], buff);
		else
			s[fd] = ft_strdup(buff);
		if (ft_check_line(&(s[fd]), line))
			return (1);
	}
	if (s[fd] && ret >= 0)
		return (ft_last_line(&(s[fd]), line));
	if (ret > 0)
		return (1);
	else
		return (ret);
}
