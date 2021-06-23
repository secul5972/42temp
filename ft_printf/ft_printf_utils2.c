/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:57:25 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/23 15:01:45 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	long	ft_abs(long n)
{
	if (n < 0)
		n = -1 * n;
	return (n);
}

static	void	fill_num(int size, char *ret, long temp, int m_flag)
{
	ret[size--] = 0;
	while (size - m_flag >= 0)
	{
		ret[size--] = temp % 10 + '0';
		temp /= 10;
	}
	if (m_flag == 1)
		ret[0] = '-';
}

char			*ft_itoa(long n)
{
	int		m_flag;
	int		size;
	char	*ret;
	long	temp;

	temp = n;
	m_flag = 0;
	size = 1;
	if (temp < 0)
	{
		m_flag = 1;
		temp *= -1;
	}
	while (temp /= 10)
		size++;
	temp = ft_abs(n);
	if (!(ret = (char*)malloc(sizeof(char) * (size + 1 + m_flag))))
		return (0);
	fill_num(size + m_flag, ret, temp, m_flag);
	return (ret);
}