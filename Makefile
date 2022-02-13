NAME = ft_select

CC = gcc

FLAGS = -Wall -Wextra -Werror

C_PATH = srcs/

O_PATH = objs/

SRCS_F = main.c \
		 second.c \
		 st_key_handler.c \
		 st_sig_master.c \
		 st_term_handler.c \
		 st_term_switch.c

OBJS_F = $(SRCS_F:.c=.o)

SRCS = $(addprefix $(C_PATH),$(SRCS_F))
OBJS = $(addprefix $(O_PATH),$(OBJS_F))

$(NAME) : $(OBJS)
	make -C libft/
	$(CC) -o $(NAME) $(OBJS) -L libft -lft -ltermcap

$(O_PATH)%.o: $(C_PATH)%.c
	mkdir -p objs
	$(CC) $(FLAGS) -I libft/includes -I includes -o $@ -c $<

all : $(NAME)

clean :
	make -C libft/ clean
	rm -rf $(OBJS)
	rm -rf $(O_PATH)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME)

re : fclean all
