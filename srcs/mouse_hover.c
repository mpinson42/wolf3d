/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hover.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:43:22 by mpinson           #+#    #+#             */
/*   Updated: 2018/03/14 11:43:27 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	turn_head(t_gen *g)
{
	double		olddir;
	double		oldplan;

	olddir = g->dirx;
	g->dirx = g->dirx * cos(0.07) - g->diry * sin(0.07);
	g->diry = olddir * sin(0.07) + g->diry * cos(0.07);
	oldplan = g->planx;
	g->planx = g->planx * cos(0.07) - g->plany * sin(0.07);
	g->plany = oldplan * sin(0.07) + g->plany * cos(0.07);
}

void	turn_head2(t_gen *g)
{
	double		olddir;
	double		oldplan;

	olddir = g->dirx;
	g->dirx = g->dirx * cos(-0.07) - g->diry * sin(-0.07);
	g->diry = olddir * sin(-0.07) + g->diry * cos(-0.07);
	oldplan = g->planx;
	g->planx = g->planx * cos(-0.07) - g->plany * sin(-0.07);
	g->plany = oldplan * sin(-0.07) + g->plany * cos(-0.07);
}

int		ft_mouse(int x, int y, t_gen *g)
{
	static int	x_s = 0;
	static int	y_s = 0;

	if (g->block_mouse)
		return (0);
	if (x < x_s)
		turn_head(g);
	if (x > x_s)
		turn_head2(g);
	if (y > y_s && g->hauteur > -200)
		g->hauteur -= 20;
	if (y < y_s && g->hauteur < 200)
		g->hauteur += 20;
	x_s = x;
	y_s = y;
	ft_start_algo(g);
	return (0);
}
