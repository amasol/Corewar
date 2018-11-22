/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:45:42 by amasol            #+#    #+#             */
/*   Updated: 2018/11/11 14:45:44 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

t_val			*s_file()
{
	t_val	*vl;
	t_val	*tmp;
	int		i;

	i = 0;
	vl = (t_val *)malloc(sizeof(t_val));
	tmp = vl;
	vl->next = NULL;
	vl->fd = open("zork.cor", O_RDONLY);

	if (read(vl->fd, vl->m_header, 4) != 4)
		error();
	if (read(vl->fd, vl->bot_name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		error();
	if (read(vl->fd, vl->n_null, 4) != 4)
		error();
	if (read(vl->fd, vl->b_size, 4) != 4)
		error();
	else
		vl->b_size_int = shift_bit(vl->b_size[2], vl->b_size[3]);
	if (read(vl->fd, vl->b_comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		error();
	if (read(vl->fd, vl->n_null_two, 4) != 4)
		error();
	vl->executable_code = (unsigned char *)malloc(sizeof(unsigned char) * vl->b_size_int);
	if (read(vl->fd, vl->executable_code, vl->b_size_int) != vl->b_size_int)
		error();
	free(vl->executable_code);
	vl->next = (t_val *)malloc(sizeof(t_val));
	vl = vl->next;
	free(vl);
	free(tmp);
//	return (tmp);


	while (i < 4)
		printf("%x", tmp->m_header[i++]);
	i = 0;
	printf("\n");
	while (i < PROG_NAME_LENGTH)
		printf("%x", tmp->bot_name[i++]);
	printf("\n");
	i = 0;
	while (i < 4)
		printf("%x", tmp->n_null[i++]);
	printf("\n");
	i = 0;
	while (i < 4)
		printf("%x", tmp->b_size[i++]);
	printf("\n");
	i = 0;
	while (i < COMMENT_LENGTH)
		printf("%x", tmp->b_comment[i++]);
	printf("\n");
	i = 0;
	while (i < 4)
		printf("%x", tmp->n_null_two[i++]);
	printf("\n");
	i = 0;
	while (i < tmp->b_size_int)
		printf("%x", tmp->executable_code[i++]);
	printf("\n");

	return (tmp);
}