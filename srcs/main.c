#include "wolf.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_gen g;

	ft_bzero(&g, sizeof(g));
	if (argc != 2 || argv[1][ft_strlen(argv[1]) - 1] != 'l'
			|| argv[1][ft_strlen(argv[1]) - 2] != 'o'
			|| argv[1][ft_strlen(argv[1]) - 3] != 'w'
			|| argv[1][ft_strlen(argv[1]) - 4] != '.')
	{
		ft_putstr("need file .wol");
		return (0);
	}
	if (ft_pars(&g, argv[1]) == -1)
	{
		ft_putstr("error");
		return (0);
	}
	if (init(&g) == -1)
		return (0);
	printf("ok\n");
}