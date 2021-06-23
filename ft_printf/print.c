/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:17:22 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/23 16:03:46 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_c(va_list ap, t_cond *status, int offset, int width)
{
	char	c;
	char	*ret;
	int		i;

	i = 0;
	width = ft_max(status->width, 1);
	offset = (status->flag & (1 << 1)) ? 0 :width - 1;
	c = va_arg(ap, int);
	if (!(ret = (char *)malloc(sizeof(char)*(width + 1))))
		return (0);
	while (i < offset)
		ret[i++] = ' ';
	ret[i++] = c;
	while (i < width)
		ret[i++] = ' ';
	ret[i] = 0;
	return (ret);
}

char	*print_s(va_list ap, t_cond *status, int offset, int width)
{
	char	*s;
	char	*ret;
	int		len;
	int		sub_len;
	int		i;

	
	sub_len = ft_min(len = ft_strlen(s = va_arg(ap, char *)), status->prec);
	width = ft_max(status->width, ft_min(sub_len, status->prec));
	offset = (status->flag & (1 << 1)) ? 0 : width - ft_min(sub_len, status->prec);
	if (!(ret = (char *)malloc(sizeof(char)*(width + 1))))
		return (0);
	i = 0;
	while (i < offset)
		ret[i++] = ' ';
	while (sub_len--)
		ret[i++] = *(s++);
	while (i < width)
		ret[i++] = ' ';
	ret[i] = 0;
	return (ret);
}

char	*get_c_arr(va_list ap, char spec)
{
	if (spec == 'd' || spec == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if(spec == 'u' || spec == 'x')
		return (ft_itoa(va_arg(ap, unsigned int)));
	else
		return (0);
}

char	*print_diux(va_list ap, t_cond *status, int offset, int width)
{
	char	*ret;
	char	*ch_d;
	char	width_c;
	int		len;
	int		i;

	if (status->prec == 2147483648)
		status->prec = -1;
	
	if (!(len = ft_strlen(ch_d = get_c_arr(ap, status->spec))))
		return (0);
	width = ft_max(status->width, ft_max(len, status->prec));
	offset = (status->flag & (1 << 1)) ? 0 : width - ft_max(len, status->prec);
	if (!(ret = (char *)malloc(sizeof(char)*(width + 1))))
		return (0);
	i = 0;
	width_c = (status->flag & (1 << 0)) ? '0' : ' ';
	while (i < offset)
		ret[i++] = width_c;
	offset = ft_max(len, status->prec) - len;
	while (offset--)
		ret[i++] = '0';
	while (len--)
		ret[i++] = *(ch_d++);
	while (i < width)
		ret[i++] = ' ';
	ret[i] = 0;
	return (ret);
}