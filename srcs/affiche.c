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

void	affiche(t_gen *g)
{
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
