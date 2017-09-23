#include "wolf.h"

void	calcule_2(t_gen *g)
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

void	calcule2_2(t_gen *g)
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

int ft_clic(int button, int x,int y, t_gen *g)
{
		init_algo(g, x);
		calcule_2(g);
		calcule2_2(g);
		printf("%d\n", button);
		g->lineh = H / g->perpwalldist;
		g->drawstart = -g->lineh / 2 + H / 2;
		if (g->drawstart < 0)
			g->drawstart = 0;
		g->drawend = g->lineh / 2 + H / 2;
		if (g->drawend > H)
			g->drawend = H - 1;
		if(y >= g->drawstart && y <= g->drawend && g->mapx !=0 && g->mapy !=0 && g->mapx != g->larg_x - 1 && g->mapy != g->larg_y - 1 && button == 1)
		{
			system("afplay musique/pistolet.mp3 &");
			g->map[g->mapx][g->mapy] = 0;
		}
		if(y >= g->drawstart && y <= g->drawend && button == 2)
		{
			if(g->side == 1 && g->mapy != g->larg_x - 1 && g->map[g->mapx][g->mapy + 1] == 0 && g->posy > g->mapy && (int)g->posy != g->mapy + 1 && (int)g->posy != g->mapy + 1)
				g->map[g->mapx][g->mapy + 1] = 1;
			if(g->side == 1 && g->mapy != 0 && g->map[g->mapx][g->mapy - 1] == 0 && g->posy < g->mapy && (int)g->posy != g->mapy - 1 && (int)g->posy != g->mapy - 1)
				g->map[g->mapx][g->mapy - 1] = 1;

			if(g->side == 0 && g->mapx != g->larg_x - 1 && g->map[g->mapx + 1][g->mapy] == 0 && g->posx > g->mapx && (int)g->posx != g->mapx + 1 && (int)g->posx != g->mapx + 1)
				g->map[g->mapx + 1][g->mapy] = 1;
			if(g->side == 0 && g->mapx != 0 && g->map[g->mapx - 1][g->mapy] == 0 && g->posx < g->mapx && (int)g->posx != g->mapx - 1 && (int)g->posx != g->mapx - 1)
				g->map[g->mapx - 1][g->mapy] = 1;
		}
	ft_start_algo(g);
	return(0);
}