#include "wolf.h"

#include <stdio.h>


void	ft_clear(t_gen *g)
{
	int i;

	i = 0;
	while(i < H * W * 4)
	{
		g->img_ptr[i] = 0;
		g->img_ptr[i + 1] = 0;
		g->img_ptr[i + 2] = 0;
		g->img_ptr[i + 3] = 0;
		i += 4;
	}
}

int		red_cross(t_gen *g)
{
	(void)g;
	exit(0);
	return (0);
}

int		check_img(t_gen *g)
{
	int i;
	int is_no;

	i = 0;
	is_no = 1;
	while(i < H * W * 4 - 4)
	{
		if(g->img_ptr[i] != 0 || g->img_ptr[i + 1] != 0 || g->img_ptr[i + 2] != 0 || g->img_ptr[i + 3] != 0)
			is_no = 0;
		i += 4;
	}
	return(is_no);
}

int		key_pressed(int kc, t_gen *g)
{
	double olddir;
	double oldplan;

	(void)g;
	if (kc == 53)
		exit(0);
	
	if(kc == 13) //w
	{
		if(g->map[(int)(g->posx + g->dirx * g->sprint)][(int)g->posy] == 0)
			g->posx += g->dirx * g->sprint;
		if(g->map[(int)g->posx][(int)(g->posy + g->diry * g->sprint)] == 0)
			g->posy += g->diry * g->sprint;
	}
	if(kc == 1) //s
	{
		if(g->map[(int)(g->posx - g->dirx * 0.1)][(int)g->posy] == 0)
			g->posx -= g->dirx * 0.1;
		if(g->map[(int)g->posx][(int)(g->posy - g->diry * 0.1)] == 0)
			g->posy -= g->diry * 0.1;
	}
	if(kc == 2) //d
	{
		olddir = g->dirx;
		g->dirx = g->dirx * cos(-0.1) - g->diry * sin(-0.1);
		g->diry = olddir * sin(-0.1) + g->diry * cos(-0.1);
		oldplan = g->planx;
		g->planx = g->planx * cos(-0.1) - g->plany * sin(-0.1);
		g->plany = oldplan * sin(-0.1) + g->plany * cos(-0.1);
	}
	if(kc == 0) //a
	{
		olddir = g->dirx;
		g->dirx = g->dirx * cos(0.1) - g->diry * sin(0.1);
		g->diry = olddir * sin(0.1) + g->diry * cos(0.1);
		oldplan = g->planx;
		g->planx = g->planx * cos(0.1) - g->plany * sin(0.1);
		g->plany = oldplan * sin(0.1) + g->plany * cos(0.1);
	}
	if(kc == 117)
	{
		ft_init_str(g);
	}
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
	if(kc == 257 && g->sprint == 0.1)
		g->sprint = 0.5;
	else if(kc == 257 && g->sprint == 0.5)
		g->sprint = 0.1;
	printf("x = %d\n", kc);
	if(g->posx > 18 && g->posx < 19 && g->posy > 5.5 && g->posy < 6)
	{
		g->posx += 8;
	}
	ft_start_algo(g);
	return (0);
}