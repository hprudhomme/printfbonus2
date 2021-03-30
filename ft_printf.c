// #include "./includes/ft_printf.h"

// t_flags     ft_init_flags(void)
// {
//     t_flags flags;

//     flags.dot = -1;
//     flags.minus = 0;
//     flags.star = 0; 
//     flags.type = 0;
//     flags.width = 0;
//     flags.zero = 0;

//     return (flags);
// }

// int         ft_flag_parse(const char *save, int i, t_flags *flags, va_list args)
// {
//     while (save[i])
//     {
//         if (!ft_isdigit(save[i])  && !ft_is_in_type_list(save[i]) && !ft_is_in_flags_list(save[i]))
//             break;
//         if (save[i] == '0' && flags->width == 0 && flags->minus == 0)
//             flags->zero = 1;
//         if (save[i] == '.')
//             i = ft_flag_dot(save, i, flags, args);
//         if (save[i] == '-')
//             *flags = ft_flag_minus(*flags);
//         if (save[i] == '*')
// 			*flags = ft_flag_width(args, *flags);
//         if (ft_isdigit(save[i]))
// 			*flags = ft_flag_digit(save[i], *flags);
//         if (ft_is_in_type_list(save[i]))
// 		{
// 			flags->type = save[i];
// 			break ;
// 		}
//         i++;
//     }
//     return (i);
// }

// int         ft_save_treat(const char *save, va_list args)
// {
//     int     char_count;
//     int     i;
//     t_flags flags;

//     i = 0;
//     char_count = 0;
//     while (1)
//     {
//         flags = ft_init_flags();
//         if (!save[i])
//             break;
//         else if (save[i] == '%' && save[i + 1])
//         {
//             i = ft_flag_parse(save, ++i, &flags, args);
//             if (ft_is_in_type_list(save[i]))
//                 char_count += ft_treatment((char)flags.type, flags, args);
//             else if (save[i])
//                 char_count += ft_putchar(save[i]);
//         }
//         else if (save[i] != '%')
//             char_count += ft_putchar(save[i]);
//         i++;    
//     }
//     return (char_count);
// }

// int			ft_printf(const char *input, ...)
// {
//     const char      *save;
//     va_list         args;
//     int             char_count;

//     char_count = 0;
//     save = ft_strdup(input);
//     va_start(args, input);
//     char_count += ft_save_treat(save, args);
//     va_end(args);
//     free((char *)save);
//     return (char_count);
// }

// int main()
// {   
//     int x;
//     int y;

//     x = ft_printf(" %4.2s %-4.2s ", "123", "4567");
//     printf("\n");
//     y = printf(" %4.2s %-4.2s ", "123", "4567");
//     printf("\n");
//     printf("x = %d & y = %d\n", x, y);

//     return 0;
// }

#include "./includes/ft_printf.h"

t_flags     ft_init_flags()
{
     t_flags flags;

    flags.dot = -1;
    flags.minus = 0;
    flags.star = 0; 
    flags.type = 0;
    flags.width = 0;
    flags.zero = 0;
    flags.space = 0;
    flags.hashtag = 0;
    flags.plus = 0;
    
    return (flags);
}

int         ft_flag_parse(const char *input, t_flags *flags, va_list args, int i)
{
    while (input[i])
    {
        if (!ft_isdigit(input[i])  && !ft_is_in_type_list(input[i]) && !ft_is_in_flags_list(input[i]))
            break;
        if (input[i] == '0' && flags->width == 0 && flags->minus == 0)
            flags->zero = 1;
        if (input[i] == ' ' && flags->plus == 0 && flags->width == 0)
            flags->space = 1;
        if (input[i] == '+')
            *flags = ft_flag_plus(*flags);
        if (input[i] == '.')
            i = ft_flag_dot(input, flags, args, i);
        if (input[i] == '-')
            *flags = ft_flag_minus(*flags);
        if (input[i] == '*')
            *flags = ft_flag_width(args, *flags);
        if (input[i] == '#')
            flags->hashtag = 1;
        if (ft_isdigit(input[i]))
            *flags = ft_flag_digit(input[i], *flags);
        if (ft_is_in_type_list(input[i]))
        {
            flags->type = input[i];
            break ; 
        }
        i++;
    }
    return (i);
}

int         ft_parse_input(va_list args, const char *input)
{
    int char_count;
    int i;
    t_flags flags;

    i = 0;
    char_count = 0;
    while (input[i])
    {
        flags = ft_init_flags();
        if (input[i] == '%' && input[i + 1])
        {
            i = ft_flag_parse(input, &flags, args, ++i);
            if (ft_is_in_type_list(input[i]))
                char_count += ft_treatment((char)flags.type, flags, args);
            else if (input[i])
                char_count += ft_putchar(input[i]);
        }
        else if(input[i] != '%')
            char_count += ft_putchar(input[i]);
        i++;
    }
    return (char_count);
}

int			ft_printf(const char *input, ...)
{
    const char  *input_save;
    int         char_count;
    va_list     args;

    char_count = 0;
    input_save = ft_strdup(input);
    va_start(args, input);
    char_count += ft_parse_input(args, input_save);
    va_end(args);
    free((char *)input_save);
    return (char_count);
}

int main()
{   
    int x;
    int y;
    x = ft_printf("%3.3x", -4242);
    printf("\n");
    y = printf("%3.3x", -4242);
    printf("\n");
    printf("x = %d & y = %d\n", x, y);

    return 0;
}