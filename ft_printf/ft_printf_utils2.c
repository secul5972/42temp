/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:57:25 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/23 16:41:53 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	long	ft_abs(long n)
{
	if (n < 0)
		n = -1 * n;
	return (n);
}

static	char	*fill_num(int size, long temp, int m_flag, int digit)
{
	char	*ret;
	int		val;

	if (!(ret = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	ret[size--] = 0;
	while (size - m_flag >= 0)
	{
		val = temp % digit;
		if((val = temp % digit + '0') > 9 + '0')
			val += 'a' - 10 - '0';
		ret[size--] = val;
		temp /= digit;
	}
	if (m_flag == 1)
		ret[0] = '-';
	return (ret);
}

char			*ft_itoa(long n, int digit, int ul_flag)
{
	int		m_flag;
	int		size;
	char	*ret;
	long	temp;
	int		i;

	temp = n;
	m_flag = 0;
	size = 1;
	if (temp < 0)
	{
		m_flag = 1;
		temp *= -1;
	}
	while (temp /= digit)
		size++;
	temp = ft_abs(n);
	ret = fill_num(size + m_flag, temp, m_flag, digit);
	i = -1;
	if (ul_flag > 0)
		while (++i < size)
			if ('a' <= ret[i] && ret[i] <= 'f')
				ret[i] -= 32;
	return (ret);
}