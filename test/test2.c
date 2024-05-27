#include "../ft_printf/ft_printf.h"
#include <stdio.h>

void	test(int n, ...)
{
	va_list	ap;
	int	i;
	char	c;

	va_start(ap, n);
	i = 0;
	while (i < n)
	{
		c = va_arg(ap, int);
		printf("%c", c);
		i++;
	}
}


int	main(void)
{
	test(5, 'a', 'b');
	return (0);
}
