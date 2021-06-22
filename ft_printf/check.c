/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:15:48 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/22 22:16:29 by seungcoh         ###   ########.fr       */
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
			status->align = 2;
			val = -val;
		}
		status->width = val;
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
	status->precision = val >= 0? val : -1;
}

char	*check_specifier(const char **format, va_list ap, t_cond *status)
{
	char *ret;

	switch(**format)
	{
	case 'c': ret = print_c(ap, status); break;
	case 's': ret = print_s(ap, status); break;
	case 'p': break;
	case 'd': break;
	case 'i': break;
	case 'u': break;
	case 'x': break;
	case 'X': break;
	default : break;
	}
	(*format)++;
	return (ret);
}