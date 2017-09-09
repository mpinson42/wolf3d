#include "wolf.h"

long	ft_atol(const char *str)
{
	long i;
	long res;
	long neg;

	neg = 1;
	res = 0;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f'
				|| str[i] == '\r' || str[i] == '\v') && str[i])
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] <= '9' && str[i] >= '0') && str[i])
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * neg);
}

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		ft_strlen_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		ft_strlen_s(char *str)
{
	char	**tab;
	int		i;

	tab = ft_strsplit(str, ' ');
	i = ft_strlen_tab(tab);
	ft_free_tab(tab);
	return (i);
}

int		init(t_gen *g)
{
	if (!(g->mlx = mlx_init()))
		return (-1);
	if (!(g->img = mlx_new_image(g->mlx, W, H)))
		return (-1);
	if (!(g->img_ptr = mlx_get_data_addr(g->img, &(g->bpp),
		&(g->s_l), &(g->endian))))
		return (-1);
	if (!(g->win = mlx_new_window(g->mlx, W, H, "wolf3D")))
		return (-1);
	return (0);
}

void	ft_putpixel_in_img(int x, int y, t_gen *g, unsigned int color)
{
	if ((unsigned long long int)((x * 4) + (y * W * 4)) >
			(unsigned long long int)(W * H * 4) ||
			(unsigned long long int)((x * 4) + (y * W * 4))
			<= 0 || x > W || x < 0 || y < 0 || y > H)
		return ;
	if (color == 0)
	{
		g->img_ptr[(x * 4) + (y * W * 4)] = 0;
		g->img_ptr[(x * 4) + (y * W * 4) + 1] = 0;
		g->img_ptr[(x * 4) + (y * W * 4) + 2] = 0;
		g->img_ptr[(x * 4) + (y * W * 4) + 3] = 0;
	}
	else
	{
		g->img_ptr[(x * 4) + (y * W * 4)] = g->blue + g->blue2;
		g->img_ptr[(x * 4) + (y * W * 4) + 1] = g->green + g->green2;
		g->img_ptr[(x * 4) + (y * W * 4) + 2] = g->red + g->red2;
		g->img_ptr[(x * 4) + (y * W * 4) + 3] = 0;
	}
}