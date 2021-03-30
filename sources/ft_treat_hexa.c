#include "../includes/ft_printf.h"

static int		ft_in_put_part_hexa(char *hexa, t_flags flags, int lower)
{
	int char_count;

	char_count = 0;
	if (flags.hashtag && flags.zero == 0 && hexa[0] != '0')
	{
		char_count += (flags.type == 'x') ? ft_putstr("0x", 2) : ft_putstr("0X", 2);
	}
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1, ft_strlen(hexa) - 1, 1);
	char_count += ft_putstr(hexa, ft_strlen(hexa));
	return (char_count);
}

static int		ft_put_part_hexa(char *hexa, t_flags flags, int lower)
{
	int char_count;

	if (flags.hashtag == 1 && hexa[0] != '0')
	
	{	
		if (flags.zero)
			char_count += (flags.type == 'x') ? ft_putstr("0x", 2) : ft_putstr("0X", 2);
		// {
		// if (lower)
		// 	char_count += ft_putstr("0x", 2);
		// else
		// 	char_count += ft_putstr("0X", 2);
		// }
		flags.width -= 2;
	}
	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_hexa(hexa, flags, lower);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width,
		ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_hexa(hexa, flags, lower);
	return (char_count);
}

int				ft_treat_hexa(unsigned int ui, int lower, t_flags flags)
{
	char	*hexa;
	int		char_count;

	char_count = 0;
	ui = (unsigned int)(4294967295 + 1
				+ ui);
	printf("ui = %d \n", ui);
	if (flags.dot == 0 && ui == 0)
	{	
		char_count += ft_treat_width(flags.width, 0, 0);
		return (char_count);
	}
	hexa = ft_u_dec_to_hexa((unsigned long long)ui, 16);
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	char_count += ft_put_part_hexa(hexa, flags, lower);
	free(hexa);
	return (char_count);
}