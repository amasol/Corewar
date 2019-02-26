/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:56:56 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/24 14:26:57 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_specifiers
{
	int		accuracy;
	int		minus;
	int		plus;
	int		space;
	int		sharp;
	int		zero;
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		j;
	int		z;
	int		width;
	int		accuracy_value;
	int		error_flag;
	char	type;
}				t_specifiers;

t_specifiers	*ft_find_specifiers(const char *f, int *i);

int				ft_printf(const char *format, ...);

char			*ft_select_type(t_specifiers *specifiers, va_list ap, int *k);
char			*ft_uitoa(uintmax_t digit, t_specifiers *s);

char			*ft_putc(t_specifiers *s, int ch, int *k);
char			*ft_puts(t_specifiers *s, char *part, int *k);
char			*ft_putd(t_specifiers *s, intmax_t digit, int *k);
char			*ft_putoux(t_specifiers *s, uintmax_t digit, int *k);
char			*ft_unicode_check(int c, int *len);
char			*ft_put_bigs(t_specifiers *s, int *str, int *k);

#endif
