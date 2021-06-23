/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:15:48 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/23 16:02:43 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void check_flag(const char **format, va_list ap, t_cond *status)
{
	(*format)++;
	while (**format == '0' || **format == '-')
	{
		if (**format == '0')
			status->flag |= (1 << 0);
		if (**format == '-')
			status->flag |= (1 << 1);
		(*format)++;
	}
}

void check_width(const char **format, va_list ap, t_cond *status)
{
	long	val;

	if (**format == '*')
	{
		val = va_arg(ap, int);
		if (val < 0)
		{
			status->flag |= (1 << 1);
			val = -val;
		}
		status->width = val;
		(*format)++;
		return ;
	}
	val = 0;
	while ('0' <= **format && **format <= '9')
	{
		val *= 10;
		val += **format - '0';
		(*format)++;
	}
	status->width = val;
}

void check_precision(const char **format, va_list ap, t_cond *status)
{
	int		m_flag;
	long	val;

	m_flag = 0;
	val = 0;
	if (**format != '.')
		return ;
	(*format)++;
	if (**format == '*')
	{
		val = va_arg(ap, int);
		(*format)++;
	}
	else if (**format == '-')
	{
		m_flag = 1;
		(*format)++;
	}
	while ('0' <= **format && **format <= '9')
	{
		val *= 10;
		val += *(*format)++ - '0';
	}
	if (m_flag == 1)
		val = -val;
	status->prec = val >= 0? val : -1;
}

char	*check_specifier(const char **format, va_list ap, t_cond *status)
{
	char	*ret;
	int		offset;
	int		width;

	if (**format == 'c')
		ret = print_c(ap, status, offset, width);
	else if (**format == 's')
		ret = print_s(ap, status, offset, width);
	else if (**format == 'd' || **format == 'i' || **format == 'u' || **format == 'x')
	{
		status->spec = **format;
		ret = print_diux(ap, status, offset, width);
	}
	(*format)++;
	return (ret);
}