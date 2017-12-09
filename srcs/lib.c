/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 18:03:59 by mpinson           #+#    #+#             */
/*   Updated: 2017/09/09 18:04:01 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (ft_load_img(g) == -1 || ft_load_img2(g) == -1)
		return (-1);
	return (0);
}
