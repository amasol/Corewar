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

t_val			s_file()
{
	t_val	vl[4];
//	t_val	tmp[4];
	int		i;

	i = 0;
//	vl = (t_val *)malloc(sizeof(t_val));
//	tmp = vl;
//	vl->next = NULL;
	vl[i].fd = open("zork.cor", O_RDONLY);


	if (read(vl[i].fd, vl[i].m_header, 4) != 4)
		error();
	if (read(vl[i].fd, vl[i].bot_name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		error();
	if (read(vl[i].fd, vl[i].n_null, 4) != 4)
		error();
	if (read(vl[i].fd, vl[i].b_size, 4) != 4)
		error();
	else
		vl[i].b_size_int = shift_bit(vl[i].b_size[2], vl[i].b_size[3]);
	if (read(vl[i].fd, vl[i].b_comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		error();
	if (read(vl[i].fd, vl[i].n_null_two, 4) != 4)
		error();
//	vl[i].executable_code = (unsigned char *)malloc(sizeof(unsigned char) * vl[i].b_size_int);
	if (read(vl[i].fd, vl[i].executable_code, vl[i].b_size_int) != vl[i].b_size_int)
		error();
//	free(vl[i].executable_code);
//	vl->next = (t_val *)malloc(sizeof(t_val));
//	vl = vl->next;

//	free(vl);
//	i++;


//	free(tmp);
//	return (tmp);



//	while (i < 4)
//		printf("%x", tmp->m_header[i++]);
//	i = 0;
//	printf("\n");
//	while (i < PROG_NAME_LENGTH)
//		printf("%x", tmp->bot_name[i++]);
//	printf("\n");
//	i = 0;
//	while (i < 4)
//		printf("%x", tmp->n_null[i++]);
//	printf("\n");
//	i = 0;
//	while (i < 4)
//		printf("%x", tmp->b_size[i++]);
//	printf("\n");
//	i = 0;
//	while (i < COMMENT_LENGTH)
//		printf("%x", tmp->b_comment[i++]);
//	printf("\n");
//	i = 0;
//	while (i < 4)
//		printf("%x", tmp->n_null_two[i++]);
//	printf("\n");
//	i = 0;
//	while (i < tmp->b_size_int)
//		printf("%x", tmp->executable_code[i++]);
//	printf("\n");


	i = 0;
	while (i < 4)
		printf("%x", vl[1].m_header[i++]);
	i = 0;
	printf("\n");
	while (i < PROG_NAME_LENGTH)
		printf("%x", vl[1].bot_name[i++]);
	printf("\n");
	i = 0;
	while (i < 4)
		printf("%x", vl[1].n_null[i++]);
	printf("\n");
	i = 0;
	while (i < 4)
		printf("%x", vl[1].b_size[i++]);
	printf("\n");
	i = 0;
	while (i < COMMENT_LENGTH)
		printf("%x", vl[1].b_comment[i++]);
	printf("\n");
	i = 0;
	while (i < 4)
		printf("%x", vl[1].n_null_two[i++]);
	printf("\n");
	i = 0;
	while (i < vl[1].b_size_int)
		printf("%x", vl[1].executable_code[i++]);
	printf("\n");


	return (vl[i]);
}