/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 18:04:14 by mpinson           #+#    #+#             */
/*   Updated: 2017/09/09 18:04:17 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	ft_check(char *str)
{
	char	**tab;
	int		i;
	int		y;

	i = 0;
	tab = ft_strsplit(str, ' ');
	while (tab[i])
	{
		y = 0;
		while (str[y] && str[y] != ',')
		{
			if ((str[y] != '-' && str[y] != 32 && 1 != ft_isdigit(str[y]))
					|| ft_strlen(tab[i]) > 11 ||
					(ft_atol(tab[i]) > 2147483647 ||
						ft_atol(tab[i]) < -2147483648))
			{
				return (-1);
			}
			y++;
		}
		i++;
	}
	ft_free_tab(tab);
	return (0);
}

int	go_malloc1(char **tab, int y, t_gen *g)
{
	int i;

	i = 0;
	if (!(g->map[y] = malloc(sizeof(int) * ft_strlen_tab(tab))))
		return (-1);
	i = 0;
	while (i < ft_strlen_tab(tab))
	{
		g->map[y][i] = ft_atoi(tab[i]);
		free(tab[i]);
		i++;
	}
	return (0);
}

int	go_malloc2(t_gen *g, int lang)
{
	if (lang == -1)
		return (-1);
	if (!(g->map = malloc(sizeof(int *) * g->larg_x)))
		return (-1);
	return (0);
}

int	ft_last_check(t_gen *g)
{
	int x;

	x = 0;
	while (x < g->larg_y - 1)
	{
		if (g->map[0][x] == 0 || g->map[g->larg_x - 1][x] == 0
			|| g->map[0][x] == 42 || g->map[g->larg_x - 1][x] == 42)
			return (-1);
		x++;
	}
	x = 0;
	while (x < g->larg_x - 1)
	{
		if (g->map[x][0] == 0 || g->map[x][g->larg_y - 1] == 0
			|| g->map[x][0] == 42 || g->map[x][g->larg_y - 1] == 42)
			return (-1);
		x++;
	}
	return (0);
}

int	ft_pars(t_gen *g, char *pass)
{
	int		fd;
	char	*test;
	int		lang;

	lang = -1;
	if ((fd = open(pass, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &test) > 0)
	{
		if ((lang != -1 && lang != ft_strlen_s(test)) || ft_check(test) == -1)
			return (-1);
		g->larg_x++;
		lang = ft_strlen_s(test);
		free(test);
	}
	if (g->larg_x <= 21 || go_malloc2(g, lang) == -1)
		return (-1);
	close(fd);
	if (ft_init(g, pass) == -1)
		return (-1);
	free(test);
	if (ft_last_check(g) == -1)
		return (-1);
	return (0);
}
