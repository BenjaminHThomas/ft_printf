/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:20:12 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/26 11:57:11 by bthomas          ###   ########.fr       */
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
# define FLAG_CHARS "-+ #0"
# define HEX_BASE "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

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
int		ft_printf(const char *fmt, ...);
int		printf_atoi(char **str);
int		ft_printvarg(char **fmt, t_flags *flags, va_list ap);
int		is_printable(char c);
int		ft_fmtparse(char *fmt, va_list ap);
int		print_p(t_flags *flags, va_list ap);
int		print_s(t_flags *flags, va_list ap);
int		print_c(t_flags *flags, va_list ap);
int		print_digit(t_flags *flags, va_list ap);
void	print_flags(t_flags *flags);
void	pad_output(char c, int n);
char	get_padder(t_flags *flags);
int		printf_putstr(char *s, int limit, int null_cmp);
void	pad_output(char c, int n);
int		init_len(char *s, t_flags *flags);
int		max(int n1, int n2);
int		print_d_left(t_flags *flags, char *numstr);
int		print_d_right(t_flags *flags, char *numstr);
int		print_u(t_flags *flags, va_list ap);
int		print_p_left(t_flags *flags, char *pstr);
int		print_p_right(t_flags *flags, char *pstr);
int		num_digits(unsigned long int n, int base);
int		print_x(t_flags *flags, va_list ap);
int		min(int n1, int n2);

#endif
