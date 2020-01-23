FLAGS=-g -Wall -Wextra -Werror
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

all:
	make -C libft re
	gcc $(FLAGS) $(SRC) -I . -I libft/includes -L libft -lft -o minishell 

test_env:
	make -C libft re
	gcc -g del_array.c env_actions.c ft_getenv.c init_env.c to_array.c test_env.c -I . -I libft/includes -L libft -lft -o test_env
