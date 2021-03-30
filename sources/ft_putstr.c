#include "../includes/ft_printf.h"

int		ft_putstr(char *str, int length)
{
	int char_count;

	char_count = 0;
	while (str[char_count] && char_count < length)
		ft_putchar(str[char_count++]);
	return (char_count);
}