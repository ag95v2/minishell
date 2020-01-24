NAME = minishell
FLAGS=-Wall -Wextra -Werror
SRC=del_array.c\
	echo.c\
	env_actions.c\
	env_related_builtins.c\
	exit.c\
	ft_getenv.c\
	init_env.c\
	minishell.c\
	to_array.c\
	builtin_cd.c\
	find_path.c\
	find_exec.c\
	repl.c\
	get_builtin.c\
	dollar_expansion.c\
	tilda_expansion.c\
	builtin_env.c\
	parse_cd_args.c\
	get_curpath.c\
	is_a_directory.c\
	canonicize_utils.c\
	canonicize.c

OBJ = $(SRC:.c=.o)
HEADER = cd_utils.h\
		 environment.h\
		 find_exec.h\
		 name_max.h\
		 t_builtin.h\
		colors.h\
		expansions.h\
		find_path.h\
		repl.h

all: $(NAME)

$(NAME): lib $(OBJ) $(HEADER)
	gcc $(FLAGS) $(OBJ) -I . -I libft/includes -L libft -lft -o $(NAME) 

lib:
	make -C libft

%o : %c
	gcc -I. -I libft/includes/ $(FLAGS) -c $^

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
