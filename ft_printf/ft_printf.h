/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:38:13 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/22 21:41:12 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_cond
{
	int			flag;
	int			align;
	long		width;
	long		precision;

}				t_cond;

int		ft_strlen(const char *str);
int		ft_max(const int a, const int b);
int		ft_min(const int a, const int b);

void	check_flag(const char **format, va_list ap, t_cond *status);
void	check_width(const char **format, va_list ap, t_cond *status);
void	check_precision(const char **format, va_list ap, t_cond *status);
char	*check_specifier(const char **format, va_list ap, t_cond *status);

char	*print_c(va_list ap, t_cond *status);
char	*print_s(va_list ap, t_cond *status);

int	ft_printf(const char *format, ...);

#endif