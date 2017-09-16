/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 18:35:36 by mpinson           #+#    #+#             */
/*   Updated: 2017/09/09 18:35:39 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_init(t_gen *g, char *pass)
{
	int		fd;
	char	*test;
	char	**tab;
	int		y;

	y = 0;
	if ((fd = open(pass, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &test) > 0)
	{
		tab = ft_strsplit(test, ' ');
		if (-1 == (go_malloc1(tab, y, g)))
			return (-1);
		free(test);
		y++;
	}
	g->larg_y = ft_strlen_tab(tab);
	close(fd);
	free(test);
	return (0);
}

void	ft_chr42(t_gen *g)
{
	int x;
	int y;

	x = 0;
	while (x < g->larg_x)
	{
		y = 0;
		while (y < g->larg_y)
		{
			if (g->map[x][y] == 42)
			{
				g->posx = x + 0.5;
				g->posy = y + 0.5;
				g->old_posx = x + 0.5;
				g->old_posy = y + 0.5;
				g->map[x][y] = 0;
				return ;
			}
			y++;
		}
		x++;
	}
	exit(0);
}

void	ft_init_str(t_gen *g)
{
	static int i = 0;

	if (i == 0)
		ft_chr42(g);
	else
	{
		g->posx = g->old_posx;
		g->posy = g->old_posy;
	}
	i = 1;
	g->dirx = -1;
	g->diry = 0;
	g->planx = 0;
	g->plany = 0.66;
	g->time = 0;
	g->oldtime = 0;
	g->sprint = 0.1;
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
