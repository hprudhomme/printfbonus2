#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef	struct		s_flags
{
	int				already_print;
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
	int				space;
	int				hashtag;
	int				plus;
}					t_flags;

int					ft_printf(const char *str, ...);
int					ft_is_in_type_list(int c);
int					ft_is_in_flags_list(int c);
int					ft_treatment(int c, t_flags flags, va_list args);
int					ft_treat_width(int width, int minus, int has_zero);
int					ft_putstr(char *str, int length);
int					ft_treat_char(char c, t_flags flags);
int					ft_treat_string(char *str, t_flags flags);
int					ft_treat_int(int i, t_flags flags);
int					ft_treat_percent(t_flags flags);
int					ft_treat_hexa(unsigned int ui, int lower, t_flags flags);
int					ft_treat_uint(unsigned int unsi, t_flags flags);
int             	ft_flag_dot(const char *input, t_flags *flags, va_list args, int i);
int					ft_putchar(int c);
int					ft_treat_pointer(unsigned long long pointer, t_flags flags);

char				*ft_u_dec_to_hexa(unsigned long long ull, int base);
char				*ft_u_itoa(unsigned int n);
char				*ft_str_tolower(char *str);

t_flags				ft_flag_minus(t_flags flags);
t_flags				ft_flag_width(va_list args, t_flags flags);
t_flags				ft_flag_digit(char c, t_flags flags);
t_flags				ft_flag_plus(t_flags flags);

#endif