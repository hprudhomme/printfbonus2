#include "../includes/ft_printf.h"

static int	ft_in_put_part_int(char *i_to_str, int save_i, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (save_i < 0 && flags.dot >= 0)
		ft_putchar('-');
	// bonus +
	if (save_i >= 0 && flags.plus == 1 && flags.zero == 0)
		ft_putchar('+');
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1, ft_strlen(i_to_str) - 1, 1);
	char_count += ft_putstr(i_to_str, ft_strlen(i_to_str));
	return (char_count);
}

static int	ft_bonus_part(t_flags *flags, int save_i)
{	
	int char_count;

	char_count = 0;
	if (flags->space && (flags->width <= 0 || flags->zero) && save_i >= 0)
	{	
		if (flags->zero)
			flags->width--;
		char_count += ft_putchar(' ');
	}
	if (flags->plus && save_i >= 0)
	{	
		if (flags->zero)
			ft_putchar('+');
		char_count++;
		flags->width--;
	}
	return (char_count);
}

static int	ft_put_part_int(char *i_to_str, int save_i, t_flags flags)
{
	int char_count;

	char_count = 0;
	// bonus + et space
	if (flags.plus || flags.space)
		char_count += ft_bonus_part(&flags, save_i);
	//
	if (flags.minus == 1)
		char_count += ft_in_put_part_int(i_to_str, save_i, flags);
	// peut etre ca
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(i_to_str))
		flags.dot = ft_strlen(i_to_str);
	if (flags.dot >= 0)
	{	
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width, ft_strlen(i_to_str), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_int(i_to_str, save_i, flags);
	return (char_count);
}

int			ft_treat_int(int i, t_flags flags)
{
	char	*i_to_str;
	int		save_i;
	int		char_count;

	save_i = i;
	char_count = 0;
	// garder ce if pr exam
	if (flags.dot == 0 && i == 0)
	{
		char_count += ft_treat_width(flags.width, 0, 0);
		return (char_count);
	}
	// celui la aussi
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			ft_putstr("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		char_count++;
	}
	i_to_str = ft_itoa(i);
	char_count += ft_put_part_int(i_to_str, save_i, flags);
	free(i_to_str);
	return (char_count);
}