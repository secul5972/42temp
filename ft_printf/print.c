/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:17:22 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/23 20:12:35 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_c(va_list ap, t_cond *status)
{
	char	c;
	char	*ret;
	t_idx	idx;

	idx.i = 0;
	idx.width = ft_max(status->width, 1);
	idx.offset = (status->flag & (1 << 1)) ? 0 : idx.width - 1;
	c = va_arg(ap, int);
	if (!(ret = (char *)malloc(sizeof(char)*(idx.width + 1))))
		return (0);
	while (idx.i < idx.offset)
		ret[idx.i++] = ' ';
	ret[idx.i++] = c;
	while (idx.i < idx.width)
		ret[idx.i++] = ' ';
	ret[idx.i] = 0;
	return (ret);
}

char	*print_s(va_list ap, t_cond *status)
{
	char	*s;
	char	*ret;
	t_idx	idx;
	
	idx.prec = ft_min(idx.len = ft_strlen(s = va_arg(ap, char *)), status->prec);
	idx.width = ft_max(status->width, idx.prec);
	idx.offset = (status->flag & (1 << 1)) ? 0 : idx.width - idx.prec;
	if (!(ret = (char *)malloc(sizeof(char)*(idx.width + 1))))
		return (0);
	idx.i = 0;
	while (idx.i < idx.offset)
		ret[idx.i++] = ' ';
	while (idx.prec--)
		ret[idx.i++] = *(s++);
	while (idx.i <idx.width)
		ret[idx.i++] = ' ';
	ret[idx.prec] = 0;
	return (ret);
}

char	*get_c_arr(va_list ap, t_cond *status)
{
	if (status->spec == 'd' || status->spec == 'i')
		return (ft_ntoa(va_arg(ap, int), 10, status));
	else if(status->spec == 'u')
		return (ft_ntoa(va_arg(ap, unsigned int), 10, status));
	else if(status->spec == 'x' || status->spec == 'X')
		return (ft_ntoa(va_arg(ap, unsigned int), 16, status));
	else if(status->spec == 'p')
		return (ft_ntoa(va_arg(ap, long long), 16, status));
	return (0);
}

void	fill_prec(char **ret, int *i, int len, char **ch_d)
{
	if (**ch_d == '-')
		(*ret)[(*i)++] = *((*ch_d)++);
	if (**ch_d == '0' && *(*ch_d + 1) == 'x')
	{
		(*ret)[(*i)++] = *((*ch_d)++);
		(*ret)[(*i)++] = *((*ch_d)++);
	}
	while (len--)
		(*ret)[(*i)++] = '0';
}

char	*print_diuxp(va_list ap, t_cond *status)
{
	char	*ret;
	char	*ch_d;
	char	width_c;
	t_idx	idx;

	if (status->prec == 2147483648)
		status->prec = -1;
	if (!(idx.len = ft_strlen(ch_d = get_c_arr(ap, status))))
		return (0);
	idx.prec = ft_max(idx.len - status->m_flag - status->hex_flag, status->prec) + status->m_flag + status->hex_flag;
	idx.width = ft_max(status->width, idx.prec);
	idx.offset = (status->flag & (1 << 1)) ? 0 : idx.width - idx.prec;
	if (!(ret = (char *)malloc(sizeof(char)*(idx.width + 1))))
		return (0);
	idx.i = 0;
	width_c = (status->flag & (1 << 0)) ? '0' : ' ';
	while (idx.i < idx.offset)
		ret[idx.i++] = width_c;
	fill_prec(&ret, &idx.i, idx.prec - idx.len, &ch_d);
	while (idx.len--)
		ret[idx.i++] = *(ch_d++);
	while (idx.i < idx.width)
		ret[idx.i++] = ' ';
	ret[idx.i] = 0;
	return (ret);
}