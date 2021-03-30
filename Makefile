SRCS =  ft_printf.c \
		sources/ft_treatment.c \
		sources/ft_treat_width.c \
		sources/ft_u_itoa.c \
		sources/ft_u_dec_to_hexa.c \
		sources/ft_putchar.c \
		sources/ft_str_tolower.c \
		sources/ft_putstr.c \
		sources/ft_treat_string.c \
		sources/ft_treat_char.c \
		sources/ft_treat_pointer.c \
		sources/ft_treat_int.c \
		sources/ft_treat_uint.c \
		sources/ft_treat_percent.c \
		sources/ft_treat_hexa.c \
		sources/ft_treat_flags.c 
		
OBJS	= $(SRCS:.c=.o)

NAME = libftprintf.a

LIBFT = ./libft/libft.a

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

RM		= rm -f

OBJS = $(SRCS:.c=.o)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) all -C ./libft
			cp libft/libft.a ./
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

clean :
	$(MAKE) clean -C ./libft 
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
