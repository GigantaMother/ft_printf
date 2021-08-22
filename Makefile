NAME := libftprintf.a

HEADER = ft_printf.h

SOURSES :=	ft_printf.c			parser.c			parameter.c\
			parameter_num.c		utilities1.c		utilities2.c 	

OBJ = $(patsubst %.c, %.o, $(SOURSES))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME)	: $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re 