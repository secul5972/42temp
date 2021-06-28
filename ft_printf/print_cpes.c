/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cpes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:42:45 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/28 21:51:08 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*print_cpe(va_list ap, t_cond *stat, int c_flag)
{
	char	c;
	char	width_c;
	char	*ret;
	t_idx	idx;

	idx.i = 0;
	idx.width = ft_max(stat->width, 1);
	stat->width = idx.width;
	idx.offset = (stat->flag & (1 << 1)) ? 0 : idx.width - 1;
	if (!(c = (c_flag > 0) ? '%' : va_arg(ap, int)))
		stat->n_flag = 1;
	if (!(ret = (char *)malloc(sizeof(char) * (idx.width + 1))))
		return (0);
	width_c = (stat->flag & (1 << 0)) ? '0' : ' ';
	while (idx.i < idx.offset)
		ret[idx.i++] = width_c;
	ret[idx.i++] = c;
	while (idx.i < idx.width)
		ret[idx.i++] = ' ';
	ret[idx.i] = 0;
	return (ret);
}

static	char	*s_check_null(va_list ap, char **temp)
{
	char	*s;

	*temp = 0;
	s = 0;
	if (!(s = va_arg(ap, char *)))
	{
		if(!(s = ft_strdup("(null)")))
			return (0);
		*temp = s;
	}
	return (s);
}

char			*print_s(va_list ap, t_cond *stat)
{
	char	*s;
	char	*ret;
	char	*temp;
	t_idx	idx;

	if(!(s = s_check_null(ap, &temp)))
		return (0);
	idx.len = ft_strlen(s);
	idx.prec = ft_min(idx.len, stat->prec);
	idx.width = ft_max(stat->width, idx.prec);
	idx.offset = (stat->flag & (1 << 1)) ? 0 : idx.width - idx.prec;
	if (!(ret = (char *)malloc(sizeof(char) * (idx.width + 1))))
		return (0);
	idx.i = 0;
	while (idx.i < idx.offset)
		ret[idx.i++] = ' ';
	while (idx.prec--)
		ret[idx.i++] = *(s++);
	while (idx.i < idx.width)
		ret[idx.i++] = ' ';
	ret[idx.i] = 0;
	if (temp)
		free(temp);
	stat->width = ft_strlen(ret);
	return (ret);
}
