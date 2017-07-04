SRCS_DIR = srcs/
SRC = cd.c cd_handlers1.c cd_handlers2.c echo.c env.c set_env.c main.c \
	  unset_env.c search_path.c
FLAGS = -Wall -Wextra -Werror
NAME = minishell
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
OBJS = cd.o cd_handlers1.o cd_handlers2.o echo.o env.o set_env.o main.o \
	   unset_env.o search_path.o

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) -I includes -c $(SRCS)
	gcc $(OBJS) -L libft/ -lft -lftprintf -o $(NAME)

clean:
	rm -f minishell
	make -C libft clean

fclean: clean
	rm -f minishell
	rm *.o
	make -C libft fclean

re: fclean all
