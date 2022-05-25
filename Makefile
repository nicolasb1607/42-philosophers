CC		= gcc
SAN		= -fsanitize=address
CFLAGS	= -Wall -Wextra -Werror -MMD -g3
EXEC	= philo

OBJS_PATH =	objs/
SRCS_PATH 	=	srcs/

LIBFT 	= ./libft/

INCLUDES		= ./includes/

SRCS	=	main.c			\
			check_args.c	\
			launch_prgm.c	\
			routine.c		\
			time.c			\
			init.c			\


OBJS = 	$(addprefix $(OBJS_PATH),${SRCS:.c=.o})
DEPS =	$(addprefix $(OBJS_PATH), $(SRCS:.c=.d))

all : MAKELIBFT $(EXEC)

MAKEPRINTF : 
	make -C $(PRINTF)

MAKELIBFT : 
	make -C $(LIBFT)

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) -L $(LIBFT) $^ -o $(EXEC) -I $(INCLUDES) -I $(LIBFT) -lft -pthread

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -L $(LIBFT) -c $^ -o $@ -I $(INCLUDES) -I $(LIBFT) -lft -pthread

clean :
	rm -rf objs
	make clean -C $(LIBFT)

fclean : clean
	rm -rf $(EXEC)
	make fclean -C $(LIBFT)

re : fclean all

-include $(DEPS)

.PHONY : all clean fclean re 