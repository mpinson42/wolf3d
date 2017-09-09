/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 18:04:07 by mpinson           #+#    #+#             */
/*   Updated: 2017/09/09 18:26:08 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_menu(t_gen *g)
{
	mlx_string_put(g->mlx, g->win, 0, 0, 0x00FFFFFF, "7,4,8,5,9,6 couleur");
	mlx_string_put(g->mlx, g->win, 0, 15, 0x00FFFFFF, "fleche, deplacement");
	mlx_string_put(g->mlx, g->win, 0, 30, 0x00FFFFFF, "echap quiter");
	mlx_string_put(g->mlx, g->win, 0, 45, 0x00FFFFFF, "shift sprint");
	mlx_string_put(g->mlx, g->win, 0, 60, 0x00FFFFFF, "del reset");
}

void	ft_verline(int x, int start, int end, t_gen *g)
{
	while (start < end)
	{
		ft_putpixel_in_img(x, start, g, 42);
		start++;
	}
}

void	ft_setimage(t_gen *g)
{
	int x;
	int y;

	x = -1;
	while (++x < W)
	{
		y = -1;
		while (++y < H)
		{
			if (y < H / 2)
			{
				g->red = 96;
				g->green = 96;
				g->blue = 96;
			}
			else
			{
				g->red = 136;
				g->green = 66;
				g->blue = 29;
			}
			ft_putpixel_in_img(x, y, g, 42);
		}
	}
}

void	init_algo(t_gen *g, int x)
{
	g->camerax = 2 * x / (double)W - 1;
	g->rayposx = g->posx;
	g->rayposy = g->posy;
	g->raydirx = g->dirx + g->planx * g->camerax;
	g->raydiry = g->diry + g->plany * g->camerax;
	g->mapx = g->rayposx;
	g->mapy = g->rayposy;
	g->deltadistx = sqrt(1 + (g->raydiry * g->raydiry)
		/ (g->raydirx * g->raydirx));
	g->deltadisty = sqrt(1 + (g->raydirx * g->raydirx)
		/ (g->raydiry * g->raydiry));
	g->hit = 0;
}

int		main(int argc, char **argv)
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
	ft_init_str(&g);
	ft_start_algo(&g);
	mlx_hook(g.win, 2, 1L << 0, &key_pressed, &g);
	mlx_hook(g.win, 17, (1L << 17), &red_cross, &g);
	mlx_loop(g.mlx);
}
