/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:46:29 by mpinson           #+#    #+#             */
/*   Updated: 2017/09/10 17:46:32 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_flech(int x, int y, t_gen *g)
{
	int	i;
	int	max;
	int	old_x;
	int test;
	int moin;

	test = y;
	moin = 0;
	i = x;
	max = 50;
	old_x = x;
	while (test < y + 50)
	{
		i = x;
		while (i + moin < x + 50)
		{
			mlx_pixel_put(g->mlx, g->win, i, y, 0x00FFFFFF);
			mlx_pixel_put(g->mlx, g->win, i, y + moin, 0x00FFFFFF);
			i++;
		}
		moin += 2;
		y--;
	}
}

int		ft_algo_choise_color1_2(t_gen *g, int x, int y)
{
	if (g->map[x][y] == 1)
	{
		g->red = 255;
		g->green = 0;
		g->blue = 0;
		return (1);
	}
	else if (g->map[x][y] == 2)
	{
		g->red = 0;
		g->green = 255;
		g->blue = 0;
		return (1);
	}
	else if (g->map[x][y] == 3)
	{
		g->red = 0;
		g->green = 0;
		g->blue = 255;
		return (1);
	}
	return (0);
}

void	ft_algo_choise_color2_2(t_gen *g, int x, int y)
{
	if (g->map[x][y] == 4)
	{
		g->red = 255;
		g->green = 255;
		g->blue = 255;
	}
	else if (g->map[x][y] == 5)
	{
		g->red = 255 / 2;
		g->green = 255 / 2;
		g->blue = 255 / 2;
	}
	else if (g->posx > x && g->posx - 1 < x && g->posy > y && g->posy - 1 < y)
	{
		g->red = 5;
		g->green = 100;
		g->blue = 55;
	}
	else
	{
		g->red = 0;
		g->green = 0;
		g->blue = 0;
	}
}

void	ft_map(t_gen *g)
{
	g->y_map_1 = 5;
	g->x_map = -1;
	while (++g->x_map < g->larg_x)
	{
		g->y_map = -1;
		g->x_map_1 = W - g->larg_y * 10 - 5;
		while (++g->y_map < g->larg_y)
		{
			if (ft_algo_choise_color1_2(g, g->x_map, g->y_map) == 0)
				ft_algo_choise_color2_2(g, g->x_map, g->y_map);
			g->limit_x = g->x_map_1 + 10;
			g->limit_y = g->y_map_1 + 10;
			g->save_y = g->y_map_1;
			while (g->x_map_1 < g->limit_x)
			{
				g->y_map_1 = g->save_y - 1;
				while (++g->y_map_1 < g->limit_y)
					ft_putpixel_in_img(g->x_map_1, g->y_map_1, g, 42);
				g->x_map_1++;
			}
			g->y_map_1 = g->save_y;
		}
		g->y_map_1 += 10;
	}
}

void	affiche(t_gen *g)
{
	if (g->map_affiche == 1)
		ft_map(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	if (g->menu_mod)
	{
		mlx_clear_window(g->mlx, g->win);
		draw_flech(W / 2 - 110, 110 + g->pos_curseur * 50, g);
	}
	if (g->hidd_menu == 1 && g->menu_mod == 0)
		ft_menu(g);
	if (g->menu_mod)
	{
		mlx_string_put(g->mlx, g->win, W / 2 - 50, 100, 0x00FFFFFF, "resume");
		mlx_string_put(g->mlx, g->win, W / 2 - 50, 150, 0x00FFFFFF, "save");
		mlx_string_put(g->mlx, g->win, W / 2 - 50, 200, 0x00FFFFFF, "restart");
		mlx_string_put(g->mlx, g->win, W / 2 - 50, 250, 0x00FFFFFF, "load");
		mlx_string_put(g->mlx, g->win, W / 2 - 50, 300, 0x00FFFFFF, "quit");
	}
}
