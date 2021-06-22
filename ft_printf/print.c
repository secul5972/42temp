/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:17:22 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/22 22:23:13 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_c(va_list ap, t_cond *status)
{
	char	c;
	char	*ret;
	int		len;
	int		offset;
	int		i;

	i = 0;
	len = ft_max(status->width, 1);
	offset = (status->flag & (1 << 1)) ? 0 :len - 1;
	c = va_arg(ap, int);
	if (!(ret = (char *)malloc(sizeof(char)*(len + 1))))
		return (0);
	while (i < offset)
		ret[i++] = ' ';
	ret[i++] = c;
	while (i < len)
		ret[i++] = ' ';
	ret[i] = 0;
	return (ret);
}

char	*print_s(va_list ap, t_cond *status)
{
	char	*s;
	char	*ret;
	int		len;
	int		offset;
	int		i;

	s = va_arg(ap, char *);
	len = ft_max(status->width, ft_min(ft_strlen(s), status->precision));
	offset = (status->flag & (1 << 1)) ? 0 : len - ft_min(ft_strlen(s), status->precision);
	if (!(ret = (char *)malloc(sizeof(char)*(len + 1))))
		return (0);
	i = 0;
	while (i < offset)
		ret[i++] = ' ';
	offset = ft_min(ft_strlen(s), status->precision);
	while (offset--)
		ret[i++] = *(s++);
	while (i < len)
		ret[i++] = ' ';
	ret[i] = 0;
	return (ret);
}