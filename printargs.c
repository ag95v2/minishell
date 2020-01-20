#include <stdio.h>

int main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		fprintf(stderr, "%s\n", "Usage: printargs arg1 arg2 ..");
	i = 0;
	while (++i < argc)
		printf("%d: %s\n", i, argv[i]);
	return (0);
}
