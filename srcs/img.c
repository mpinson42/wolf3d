/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:02:10 by mpinson           #+#    #+#             */
/*   Updated: 2017/12/09 18:02:11 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_load_img2(t_gen *g)
{
	int wid;

	wid = 64;
	if (!(g->eagle = mlx_xpm_file_to_image(g->mlx,
		"./img/eagle.xpm", &wid, &wid)))
		return (-1);
	if (!(g->ptr_eagle = mlx_get_data_addr(g->eagle,
		&(g->bpp), &(g->s_l), &(g->endian))))
		return (-1);
	if (!(g->redbrick = mlx_xpm_file_to_image(g->mlx,
		"./img/redbrick.xpm", &wid, &wid)))
		return (-1);
	if (!(g->ptr_redbrick = mlx_get_data_addr(g->redbrick,
		&(g->bpp), &(g->s_l), &(g->endian))))
		return (-1);
	return (0);
}

int		ft_load_img(t_gen *g)
{
	int wid;

	wid = 64;
	g->texture = 1;
	if (!(g->wood = mlx_xpm_file_to_image(g->mlx,
		"./img/wood.xpm", &wid, &wid)))
		return (-1);
	if (!(g->ptr_wood = mlx_get_data_addr(g->wood,
		&(g->bpp), &(g->s_l), &(g->endian))))
		return (-1);
	if (!(g->stone = mlx_xpm_file_to_image(g->mlx,
		"./img/greystone.xpm", &wid, &wid)))
		return (-1);
	if (!(g->ptr_stone = mlx_get_data_addr(g->stone,
		&(g->bpp), &(g->s_l), &(g->endian))))
		return (-1);
	return (0);
}

void	ft_draw(int x, int start, int end, t_gen *g)
{
	while (++start < end)
	{
		if (g->texture == 1 && (g->nb_block == 1 ||
			g->nb_block == 2 || g->nb_block == 4 || g->nb_block == 3))
		{
			g->d = start * 256 - H * 128 + g->lineh * 128;
			g->texy = ((g->d * 64) / g->lineh) / 256;
			g->blue = g->p_img[(64 * g->texy * 4) + (g->texx * 4)];
			g->green = g->p_img[(64 * g->texy * 4) + (g->texx * 4) + 1];
			g->red = g->p_img[(64 * g->texy * 4) + (g->texx * 4) + 2];
			if (g->side == 1)
			{
				g->blue = g->p_img[(64 * g->texy * 4) + (g->texx * 4)] / 2;
				g->green = g->p_img[(64 * g->texy * 4) + (g->texx * 4) + 1] / 2;
				g->red = g->p_img[(64 * g->texy * 4) + (g->texx * 4) + 2] / 2;
			}
		}
		ft_putpixel_in_img(x, start, g, 42);
	}
}
