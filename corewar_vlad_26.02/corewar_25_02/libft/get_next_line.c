/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:55:21 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/23 11:30:49 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_files	*ft_free_file(t_files *file, int fd)
{
	t_files *temp1;
	t_files *temp2;
	t_files *res;

	res = file;
	temp1 = NULL;
	while (file->fd != fd)
	{
		temp1 = file;
		file = file->next;
	}
	temp2 = file;
	if (temp1 == NULL)
		res = res->next;
	else
	{
		temp1->next = temp2->next;
		file = temp1;
	}
	temp2->next = NULL;
	free(temp2);
	temp2 = NULL;
	return (res);
}

void	ft_find_line(t_files *file, char **line)
{
	char	*temp;
	char	*str;
	size_t	i;
	size_t	k;

	i = 0;
	while (file->content[i] && file->content[i] != '\n')
		i++;
	str = (char*)malloc(i + 1);
	k = 0;
	while (k < i)
	{
		str[k] = file->content[k];
		k++;
	}
	str[k] = '\0';
	*line = (char*)str;
	if (file->content[i] == '\n')
		i++;
	temp = ft_strsub(file->content, i, ft_strlen(file->content) - i + 1);
	free(file->content);
	file->content = temp;
}

char	*ft_read(int fd, char *content)
{
	char	*buf;
	size_t	ret;
	char	*res;

	if (content && ft_strchr(content, '\n'))
		return (content);
	content = (content) ? content : ft_strnew(1);
	res = content;
	buf = (char*)malloc(BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		res = ft_strjoin(content, buf);
		free(content);
		free(buf);
		buf = (char*)malloc(BUFF_SIZE + 1);
		content = res;
		if (ft_strchr(res, '\n'))
			break ;
	}
	free(buf);
	return (res);
}

t_files	*ft_check_fd(int fd, t_files *f)
{
	t_files *res;

	res = (t_files*)malloc(sizeof(t_files));
	res->content = NULL;
	res->fd = fd;
	res->next = NULL;
	while (f)
	{
		if (f->fd == fd)
		{
			if (f->content)
				res->content = ft_strsub(f->content, 0, ft_strlen(f->content));
			if (f->content != NULL)
				free(f->content);
			f->content = NULL;
			res->content = ft_read(fd, res->content);
			return (res);
		}
		f = f->next;
	}
	res->content = ft_read(fd, NULL);
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	static t_files	*files;
	t_files			*temp;
	t_files			*start;
	char			buf[1];

	if (!line || BUFF_SIZE <= 0 || fd < 0 || read(fd, buf, 0) == -1)
		return (-1);
	start = files;
	temp = ft_check_fd(fd, files);
	if (start && files->fd == fd)
		files = ft_free_file(start, fd);
	else
		files = start;
	if (temp->content == NULL || ft_strlen(temp->content) == 0)
	{
		if (temp->content != NULL)
			free(temp->content);
		free(temp);
		return (0);
	}
	ft_find_line(temp, line);
	if (files != NULL)
		temp->next = files;
	files = temp;
	return (1);
}
