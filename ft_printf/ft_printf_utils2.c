/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:57:25 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/23 20:04:42 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	long	ft_abs(long long n)
{
	if (n < 0)
		n = -1 * n;
	return (n);
}

static	char	*fill_num(int size, long long temp, t_cond *status, int digit)
{
	char	*ret;
	int		val;
	int		hex;

	hex = 0;
	if (status->spec == 'p')
		hex = 2;
	if (!(ret = (char*)malloc(sizeof(char) * (size + hex + 1))))
		return (0);
	ret[size-- + hex] = 0;
	while (size - status->m_flag >= 0)
	{
		val = temp % digit;
		if((val = temp % digit + '0') > 9 + '0')
			val += 'a' - 10 - '0';
		ret[size-- + hex] = val;
		temp /= digit;
	}
	if (status->m_flag == 1)
		ret[0] = '-';
	if (status->spec == 'p')
	{
		ret[0] = '0';
		ret[1] = 'x';
	}
	return (ret);
}

char			*ft_ntoa(long long n, int digit, t_cond *status)
{
	int			size;
	char		*ret;
	long long	temp;
	int			i;

	temp = n;
	size = 1;
	if (temp < 0)
	{
		temp *= -1;
		status->m_flag = 1;
	}
	while (temp /= digit)
		size++;
	temp = ft_abs(n);
	ret = fill_num(size + status->m_flag, temp, status, digit);
	i = -1;
	if ('X' == status->spec)
		while (++i < size)
			if ('a' <= ret[i] && ret[i] <= 'f')
				ret[i] -= 32;
	return (ret);
}