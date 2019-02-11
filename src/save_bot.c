/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:45:42 by amasol            #+#    #+#             */
/*   Updated: 2018/12/05 18:58:19 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"



t_bot			read_file(char *bot, int bot_id)
{
	t_bot			*vl;
	unsigned char	chlak[4];
	int				i;
	int 			fd;

	i = 0;
	vl = (t_bot *)malloc(sizeof(t_bot));
	fd = open(bot, O_RDONLY);

	if (read(fd, vl->m_header, 4) != 4)
		ft_error("Error validation1\n");
	if (read(fd, vl->bot_name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		ft_error("Error validation2\n");
	if (read(fd, chlak, 4) != 4)
		ft_error("Error validation3\n");
	if (read(fd, vl->b_size, 4) != 4)
		ft_error("Error validation4\n");
	else
		vl->size = bot_size(vl->b_size);
	if (read(fd, vl->b_comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		ft_error("Error validation5\n");
	if (read(fd, chlak, 4) != 4)
		ft_error("Error validation6\n");

	vl->exec_code = (UC *)malloc(sizeof(UC) * vl->size + 1);
	vl->id = bot_id;
	if (read(fd, vl->exec_code, vl->size) != vl->size)
		ft_error("Error validation7\n");
	//free(vl->exec_code);
	//free(vl);

	/*i = 0;
	while (i < 4)
		printf("%x", vl->m_header[i++]);
	i = 0;
	printf("\n");
	while (i < PROG_NAME_LENGTH)
		printf("%x", vl->bot_name[i++]);
	printf("\n");*/
	// int j = 0;
	// while (j < 4)
	// 	printf("test ->> %x\n", vl->b_size[j++]);
	// printf("\n");
	// i = 0;
	// while (i < COMMENT_LENGTH)
	// 	printf("%x", vl->b_comment[i++]);
	// printf("\n");
	// i = 0;
	// while (i < vl->size)
	// 	printf("%x", vl->exec_code[i++]);
	// printf("\n");

	return (vl[i]);
}









//t_val			s_file(char *bot)
//{
/*	t_val	vl;
	unsigned char 	buff[4];
	unsigned char 	mysar[4];
	//	vl->next = NULL;

//	fd = open("zork.cor", O_RDONLY);

	vl.fd = open(bot, O_RDONLY);
	if (read(vl.fd, vl.m_header, 4) != 4)
		error("Error validation\n");
	if (read(vl.fd, vl.bot_name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		error("Error validation\n");
	if (read(vl.fd, mysar, 4) != 4)
		error("Error validation\n");
	if (read(vl.fd, buff, 4) != 4)
		error("Error validation\n");
	else
		vl.b_size_int = shift_bit(buff);
	if (read(vl.fd, vl.b_comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		error("Error validation\n");
	if (read(vl.fd, buff, 4) != 4)
		error("Error validation\n");
	vl.executable_code = (unsigned char *)malloc(sizeof(unsigned char) * (vl.b_size_int + 1));
	vl.executable_code[vl.b_size_int] = 0;
	if (read(vl.fd, vl.executable_code, vl.b_size_int + 1) != vl.b_size_int + 1)
		error("Error validation\n");


 	int	i = 0;

	while (i < 4)
		printf("%x", vl.m_header[i++]);
	i = 0;
	printf("\n");
	while (i < PROG_NAME_LENGTH)
		printf("%x", vl.bot_name[i++]);
	printf("\n");
	i = 0;
	while (i < 4)
		printf("%x", vl.n_null[i++]);
	printf("\n");
	i = 0;
	while (i < 4)
		printf("%x", vl.b_size[i++]);
	printf("\n");
	i = 0;
	while (i < COMMENT_LENGTH)
		printf("%x", vl.b_comment[i++]);
	printf("\n");

	i = 0;
	while (i < 4)
		printf("%x", vl.n_null_two[i++]);

	printf("\n");
	i = 0;
	while (i < vl.b_size_int + 1)
		printf("%x", vl.executable_code[i++]);
	printf("\n");
	printf("\n");

	return (vl);*/
//}
