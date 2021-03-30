#include "../includes/ft_printf.h"

static int		ft_ui_length(long n)
{
	size_t	ui_length;
	int		isneg;

	ui_length = 0;
	isneg = 0;
	if (n < 0)
	{
		ui_length++;
		isneg++;
		n = -n;
	}
	while (n >= 1)
	{
		ui_length++;
		n /= 10;
	}
	return (ui_length);
}

static char		*ft_ui_to_str(char *str_ui, long nbr, int len, int isneg)
{
	if (nbr != 0)
		str_ui = malloc(sizeof(char) * (len + 1));
	else
		return (str_ui = ft_strdup("0"));
	if (!str_ui)
		return (0);
	isneg = 0;
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	str_ui[len] = '\0';
	while (--len)
	{
		str_ui[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (isneg == 1)
		str_ui[0] = '-';
	else
		str_ui[0] = (nbr % 10) + '0';
	return (str_ui);
}

char			*ft_u_itoa(unsigned int n)
{
	int		len;
	char	*str_ui;
	long	nbr;
	int		isneg;

	nbr = n;
	len = ft_ui_length(nbr);
	printf("len = %d\n", len);
	str_ui = 0;
	isneg = 0;
	if (!(str_ui = ft_ui_to_str(str_ui, nbr, len, isneg)))
		return (0);
	printf("str_ui = %s\n", str_ui);
	return (str_ui);
}