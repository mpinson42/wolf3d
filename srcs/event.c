/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 18:03:50 by mpinson           #+#    #+#             */
/*   Updated: 2017/09/09 18:03:53 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		red_cross(t_gen *g)
{
	(void)g;
	system("killall afplay");
	exit(0);
	return (0);
}

void	key_pressed_deplace(int kc, t_gen *g, double olddir, double oldplan)
{
	if (kc == 13)
	{
		if (g->map[(int)(g->posx + g->dirx * g->sprint)][(int)g->posy] == 0)
			g->posx += g->dirx * g->sprint;
		if (g->map[(int)g->posx][(int)(g->posy + g->diry * g->sprint)] == 0)
			g->posy += g->diry * g->sprint;
	}
	if (kc == 1)
	{
		if (g->map[(int)(g->posx - g->dirx * 0.1)][(int)g->posy] == 0)
			g->posx -= g->dirx * 0.1;
		if (g->map[(int)g->posx][(int)(g->posy - g->diry * 0.1)] == 0)
			g->posy -= g->diry * 0.1;
	}
	if (kc == 2)
	{
		olddir = g->dirx;
		g->dirx = g->dirx * cos(-0.1) - g->diry * sin(-0.1);
		g->diry = olddir * sin(-0.1) + g->diry * cos(-0.1);
		oldplan = g->planx;
		g->planx = g->planx * cos(-0.1) - g->plany * sin(-0.1);
		g->plany = oldplan * sin(-0.1) + g->plany * cos(-0.1);
	}
}

void	key_pressed_color(int kc, t_gen *g)
{
	if (kc == 89)
		g->red2++;
	if (kc == 86)
		g->red2++;
	if (kc == 91)
		g->green2++;
	if (kc == 87)
		g->green2--;
	if (kc == 92)
		g->blue2++;
	if (kc == 88)
		g->blue2--;
	if (kc == 46 && g->map_affiche == 0)
		g->map_affiche = 1;
	else if (kc == 46 && g->map_affiche == 1)
		g->map_affiche = 0;
	if (g->posx > 18 && g->posx < 19 && g->posy > 5.5 &&
		g->posy < 6 && g->larg_x > 27)
		g->posx += 8;
	if (kc == 17 && g->texture == 1)
		g->texture = 0;
	else if (kc == 17 && g->texture == 0)
		g->texture = 1;
}

int		key_pressed(int kc, t_gen *g)
{
	double olddir;
	double oldplan;

	if (kc == 19)
		bmp_write(g);
	if (key_menu1(kc, g) == 0)
		return (0);
	if (g->posx > 24 && g->posx < 25 && g->posy > 22 && g->posy < 23)
		g->map[23][22] = 0;
	if (kc == 0)
	{
		olddir = g->dirx;
		g->dirx = g->dirx * cos(0.1) - g->diry * sin(0.1);
		g->diry = olddir * sin(0.1) + g->diry * cos(0.1);
		oldplan = g->planx;
		g->planx = g->planx * cos(0.1) - g->plany * sin(0.1);
		g->plany = oldplan * sin(0.1) + g->plany * cos(0.1);
	}
	kc == 117 ? ft_init_str(g) : 0;
	if (kc == 257 && g->sprint == 0.1)
		g->sprint = 0.5;
	else if (kc == 257 && g->sprint == 0.5)
		g->sprint = 0.1;
	ft_start_algo(g);
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
