/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:51:47 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/13 18:28:06 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

/*
* I need to use:
* 	va_list
* 	va_start
* 	va_arg
* 	va_end
*/

/* To parse the format, 
 * I need a struct to store the flags and values
 */

int	main(void)
{
	char str[] = "%s wowow %% %";
	int	argnum = numargs(str);
	printf("\n%d", argnum);
	return (0);
}
