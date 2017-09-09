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
	if (g->larg_y <= 21)
		return (-1);
	close(fd);
	free(test);
	return (0);
}

void	ft_init_str(t_gen *g)
{
	g->posx = 22;
	g->posy = 12;
	g->dirx = -1;
	g->diry = 0;
	g->planx = 0;
	g->plany = 0.66;
	g->time = 0;
	g->oldtime = 0;
	g->sprint = 0.1;
}
