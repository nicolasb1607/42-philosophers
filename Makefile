CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=thread

EXEC	= philo

LIBFT 	= ./libft/

INCLUDES		= ./includes/

SRCS	=	./main.c				\
			./srcs/check_args.c		\
			./srcs/launch_prgm.c	\
			./srcs/free_prgm.c		\
			./srcs/routine.c		\
			./srcs/gettime.c		\
			./srcs/init_global.c	\
			./srcs/init_philo.c		\
			./srcs/print_msg.c		\
			./srcs/check_death.c	\
			./srcs/ft_is_int.c		\
			./srcs/ft_isdigit.c	\
			./srcs/ft_putstr_fd.c	\
			./srcs/ft_atoi.c		\
			./srcs/ft_strlen.c		\
			./srcs/ft_memcpy.c		\
			./srcs/ft_strcmp.c		\
			./srcs/ft_putchar_fd.c	\


OBJS = ${SRCS:.c=.o}

all : $(EXEC) 

MAKEPRINTF : 
	make -C $(PRINTF)

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(EXEC) -I $(INCLUDES) -pthread

.c.o :
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCLUDES) -pthread

clean :
	rm -rf $(OBJS)
	
fclean : clean
	rm -rf $(EXEC)
	

re : fclean all

.PHONY : all clean fclean re 