NAME	=	libftprintf.a
SRC	=	ft_printf.c param_checker.c  polymorophic_itoa.c unsigned.c signed.c itoh.c libft/ft_itoa.c \
		libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_putstr.c libft/ft_strdup.c itop.c
CFLAGS = -Wall -Wextra -Werror
CC = gcc
OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean 
	@rm -f $(NAME) 

re: fclean all
	
test:
	@gcc  mytester_ft_printf/test_printf.c libftprintf.a 
	@./a.out
