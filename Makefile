
test_env:
	make -C libft re
	gcc -g del_array.c env_actions.c ft_getenv.c init_env.c to_array.c test_env.c -I . -I libft/includes -L libft -lft -o test_env

