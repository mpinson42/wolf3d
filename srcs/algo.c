/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:14:39 by mpinson           #+#    #+#             */
/*   Updated: 2017/11/25 14:14:47 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	calcule(t_gen *g)
{
	if (g->raydirx < 0)
	{
		g->stepx = -1;
		g->sidedistx = (g->rayposx - g->mapx) * g->deltadistx;
	}
	else
	{
		g->stepx = 1;
		g->sidedistx = (g->mapx + 1.0 - g->rayposx) * g->deltadistx;
	}
	if (g->raydiry < 0)
	{
		g->stepy = -1;
		g->sidedisty = (g->rayposy - g->mapy) * g->deltadisty;
	}
	else
	{
		g->stepy = 1;
		g->sidedisty = (g->mapy + 1.0 - g->rayposy) * g->deltadisty;
	}
}

void	calcule2(t_gen *g)
{
	while (g->hit == 0)
	{
		if (g->sidedistx < g->sidedisty)
		{
			g->sidedistx += g->deltadistx;
			g->mapx += g->stepx;
			g->side = 0;
		}
		else
		{
			g->sidedisty += g->deltadisty;
			g->mapy += g->stepy;
			g->side = 1;
		}
		if (g->map[g->mapx][g->mapy] > 0)
			g->hit = 1;
	}
	if (g->side == 0)
		g->perpwalldist = (g->mapx - g->rayposx +
				(1 - g->stepx) / 2) / g->raydirx;
	else
		g->perpwalldist = (g->mapy - g->rayposy +
				(1 - g->stepy) / 2) / g->raydiry;
}

int		ft_algo_choise_color1(t_gen *g)
{
	g->nb_block = g->map[g->mapx][g->mapy];
	if (g->map[g->mapx][g->mapy] == 1)
	{
		g->red = 255;
		g->green = 0;
		g->blue = 0;
		if (g->side == 0)
			g->red /= 2;
		return (1);
	}
	else if (g->map[g->mapx][g->mapy] == 2)
	{
		g->red = 0;
		g->green = 255;
		g->blue = 0;
		if (g->side == 0)
			g->green /= 2;
		return (1);
	}
	return (0);
}

void	ft_algo_choise_color2(t_gen *g)
{
	if (g->map[g->mapx][g->mapy] == 3)
	{
		g->red = 0;
		g->green = 0;
		g->blue = 255;
		g->side == 0 ? g->blue /= 2 : 0;
	}
	else if (g->map[g->mapx][g->mapy] == 4)
	{
		g->red = 255;
		g->green = 255;
		g->blue = 255;
		if (g->side == 0)
		{
			g->blue /= 2;
			g->red /= 2;
			g->green /= 2;
		}
	}
	else
	{
		g->red = 0;
		g->green = 0;
		g->blue = 0;
	}
}

void	*ft_start_algo(void *p)
{
	int x;

	t_gen *g = p;
	x = 0;
	//ft_setimage(g);

	if (pthread_create(&g->thread1, NULL, ft_setimage, g)) {
		exit(0);
    }
    if (pthread_join(g->thread1, NULL)) {
		exit(0);
    }


	while (x < W)
	{
		init_algo(g, x);
		calcule(g);
		calcule2(g);
		if (ft_algo_choise_color1(g) == 0)
			ft_algo_choise_color2(g);
		g->lineh = H / g->perpwalldist;
		g->drawstart = -g->lineh / 2 + H / 2 + g->hauteur;
		if (g->drawstart < 0)
			g->drawstart = 0;
		g->drawend = g->lineh / 2 + H / 2 + g->hauteur;
		if (g->drawend > H)
			g->drawend = H - 1;
		ft_verline(x, g->drawstart - 1, g->drawend, g);
		x++;
	}
	affiche(g);
	p = g;
	return (NULL);
}
