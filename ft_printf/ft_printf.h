/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:38:13 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/23 20:12:35 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_cond
{
	int			m_flag;
	int			hex_flag;
	int			flag;
	long		width;
	long		prec;
	char		spec;

}				t_cond;

typedef struct s_idx
{
	int			offset;
	int			width;
	int			prec;
	int			len;
	int			i;
}				t_idx;

int		ft_strlen(const char *str);
int		ft_max(const long a, const long b);
int		ft_min(const long a, const long b);

static	long	ft_abs(long long n);
static	char	*fill_num(int size, long long temp, t_cond *status, int digit);
char	*ft_ntoa(long long n, int digit, t_cond *status);

void	check_flag(const char **format, va_list ap, t_cond *status);
void	check_width(const char **format, va_list ap, t_cond *status);
void	check_precision(const char **format, va_list ap, t_cond *status);
char	*check_specifier(const char **format, va_list ap, t_cond *status);

char	*print_c(va_list ap, t_cond *status);
char	*print_s(va_list ap, t_cond *status);
char	*get_c_arr(va_list ap, t_cond *status);
char	*print_diuxp(va_list ap, t_cond *status);


int		ft_printf(const char *format, ...);

#endif