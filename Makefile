CC		= gcc
SAN		= -fsanitize=address
CFLAGS	= -Wall -Wextra -Werror -g3
EXEC	= philo


LIBFT 	= ./libft/

INCLUDES		= ./includes/
INCLUDESLIBFT	= ./libft/


SRCS	= ./main.c \
		./srcs/check_args.c \

OBJS = ${SRCS:.c=.o}


all : MAKELIBFT $(EXEC)

MAKEPRINTF : 
	make -C $(PRINTF)

MAKELIBFT : 
	make -C $(LIBFT)

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) -L $(LIBFT) $^ -o $(EXEC) -I $(INCLUDES) -I $(INCLUDESLIBFT) -lft

.c.o:
	$(CC) $(CFLAGS) -L $(LIBFT) -c $^ -o $@ -I $(INCLUDES) -I $(INCLUDESLIBFT) -lft


clean :
	rm -rf $(OBJS)
	make clean -C $(LIBFT)
	make clean -C $(PRINTF)

fclean : clean
	rm -rf $(EXEC)
	make fclean -C $(LIBFT)
	make fclean -C $(PRINTF)

re : fclean all

.PHONY : all clean fclean re 