/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:20:12 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/14 15:05:04 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h> /* malloc & free*/
# include <stdarg.h> /* variadics */
# include <unistd.h> /* write */

/* Int min & max for testing purposes */
# define INTMAX 2147483647
# define INTMIN -2147483648
# define SPECS "cspdiuxX"

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
int	in(char const *s, char c);

#endif
