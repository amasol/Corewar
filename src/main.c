/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:41:46 by amasol            #+#    #+#             */
/*   Updated: 2018/10/31 15:41:47 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void		s_file()
{
	t_val	vl;
//	unsigned char	tmp[1];
//	char 	tmp2[129];
	int		i;

	i = 0;
	vl.fd = open("Gagnant.cor", O_RDONLY);

	if (read(vl.fd, vl.m_header, 4) != 4)
		error();
	if (read(vl.fd, vl.bot_name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		error();
	if (read(vl.fd, vl.n_null, 4) != 4)
		error();
	if (read(vl.fd, vl.b_size, 4) != 4)
		error();

	if (read(vl.fd, vl.b_comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		error();
	if (read(vl.fd, vl.n_null_two, 4) != 4)
		error();


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
		printf("%d", vl.b_size[i++]);
	printf("\n");
	i = 0;
	while (i < COMMENT_LENGTH)
		printf("%x", vl.b_comment[i++]);
	printf("\n");
	i = 0;
	while (i < 4)
		printf("%x", vl.n_null_two[i++]);


}



int			main(void)
{
	s_file();

	return (0);
}


/**
 * hex2int
 * take a hex string and convert it to a 32bit number (max 8 hex digits)
 */

/*
uint32_t hex2int(char *hex)
{
	uint32_t val = 0;
	while (*hex)
	{
		// get current character then increment
		uint8_t byte = *hex++;
		// transform hex character to the 4bit equivalent number, using the ascii table indexes
		if (byte >= '0' && byte <= '9') byte = byte - '0';
		else if (byte >= 'a' && byte <='f') byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <='F') byte = byte - 'A' + 10;
		// shift 4 to make space for new digit, and add the 4 bits of the new digit
		val = (val << 4) | (byte & 0xF);
	}
	return val;
}
*/