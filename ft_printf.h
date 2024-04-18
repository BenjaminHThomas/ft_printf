/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:20:12 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/18 19:44:10 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h> /* malloc & free*/
# include <stdarg.h> /* variadics */
# include <unistd.h> /* write */
# include "libft/libft.h"

# define INTMAX 2147483647
# define INTMIN -2147483648
# define SPECS "cspdiuxX" /* ft_printf specifiers */
# define FLAG_CHARS ".-+ #0"
# define HEX_BASE "0123456789abcdef"
# define DEC_base "0123456789"
# define OCT_base "01234567"

/* **** Structs ****/

/* s_flags stores the info of flags present in the format string 
 * %[flags][width][.precision][length]specifier
 * specifier = cspdiuxX%
 * (length is not implemented here) */
typedef struct s_flags
{
	int		b_minus;
	int		b_plus;
	int		b_space;
	int		b_hash;
	int		b_zero;
	int		width_val;
	int		prec_val;
	char	specifier;
}	t_flags;

/* **** prototypes **** */
int		in(char const *s, char c);
void	putnbr_base(long n, char *strbase, int *len);
int		ft_printf(const char *fmt, ...);
int		printf_atoi(char **str);
int		ft_printvarg(char **fmt,/* t_flags *flags,*/ va_list ap);
int		is_printable(char c);
int		ft_fmtparse(char *fmt, va_list ap);
int		print_p(va_list ap);

#endif
