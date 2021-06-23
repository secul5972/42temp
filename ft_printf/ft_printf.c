/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:37:42 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/23 20:30:53 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_cond *status)
{
	status->m_flag = 0;
	status->hex_flag = 0;
	status->flag = 0;
	status->spec = 0;
	status->prec = 2147483648;
	status->width = -1;
}

char	*check_ap(const char **format, va_list ap, t_cond *status)
{
	char *ret;
	
	(*format)++;
	if (**format == '%')
	{
		ret = malloc(sizeof(char)*2);
		ret[0] = '%';
		ret[1] = 0;
		(*format)++;
		return (ret);
	}
	check_flag(format, status);
	check_width(format, ap, status);
	check_precision(format, ap, status);
	return (check_specifier(format, ap, status));
}

int	print_format(const char **format, va_list ap)
{
	int		len;
	int		ret;
	char	*prt;
	t_cond	status;
	
	while (**format)
	{
		if (**format == '%')
		{
			init(&status);
			prt = check_ap(format, ap, &status);
			write(1, prt, (len = ft_strlen(prt)));
			ret += len;
			free(prt);
		}
		else
		{
			write(1, (*format)++, 1);
			ret++;
		}
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int ret;

	va_start(ap, format);
	ret = print_format(&format, ap);
	va_end(ap);
	return (ret);
}