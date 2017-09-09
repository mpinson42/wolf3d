#include "wolf.h"

#include <stdio.h>

void	ft_menu(t_gen *g)
{
	mlx_string_put(g->mlx, g->win, 0, 0, 0x00FFFFFF, "7,4,8,5,9,6 couleur");
	mlx_string_put(g->mlx, g->win, 0, 15, 0x00FFFFFF, "fleche, deplacement");
	mlx_string_put(g->mlx, g->win, 0, 30, 0x00FFFFFF, "echap quiter");
	mlx_string_put(g->mlx, g->win, 0, 45, 0x00FFFFFF, "shift sprint");
	mlx_string_put(g->mlx, g->win, 0, 60, 0x00FFFFFF, "del reset");
}

void ft_init_str(t_gen *g)
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

void ft_verline(int x, int start, int end, t_gen *g)
{
	while(start < end)
	{
		ft_putpixel_in_img(x, start, g, 42);
		start++;
	}
}

void ft_setimage(t_gen *g)
{
	int x;
	int y;

	x = 0;
	while(x < W)
	{
		y = 0;
		while(y < H)
		{
			if(y < H / 2)
			{
				g->red = 96;
				g->green = 96;
				g->blue = 96;
			}
			else
			{
				g->red = 136;
				g->green = 66;
				g->blue = 29;
			}
			ft_putpixel_in_img(x, y, g, 42);
			y++;
		}
		x++;
	}
}

void ft_start_algo(t_gen *g)
{
	int x;

	x = 0;
	ft_setimage(g);
	while(x < W)
	{
		g->camerax = 2 * x / (double)W - 1;
		g->rayposx = g->posx;
		g->rayposy = g->posy;
		g->raydirx = g->dirx + g->planx * g->camerax;
		g->raydiry = g->diry + g->plany * g->camerax;
		g->mapx = g->rayposx;
		g->mapy = g->rayposy;
		g->deltadistx = sqrt(1 + (g->raydiry * g->raydiry) / (g->raydirx * g->raydirx));
		g->deltadisty = sqrt(1 + (g->raydirx * g->raydirx) / (g->raydiry * g->raydiry));
		g->hit = 0;
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

      	if(g->side == 0)
      		g->perpwalldist = (g->mapx - g->rayposx + (1 - g->stepx) / 2) / g->raydirx;
      	else
      		g->perpwalldist = (g->mapy - g->rayposy + (1 - g->stepy) / 2) / g->raydiry;


      	if(g->map[g->mapx][g->mapy] == 1)
      	{
      		g->red = 255;
      		g->green = 0;
      		g->blue = 0;
      		if(g->side == 0)
      			g->red /= 2;
      	}
      	else if(g->map[g->mapx][g->mapy] == 2)
      	{
      		g->red = 0;
      		g->green = 255;
      		g->blue = 0;
      		if(g->side == 0)
      			g->green /= 2;
      	}
      	else if(g->map[g->mapx][g->mapy] == 3)
      	{
      		g->red = 0;
      		g->green = 0;
      		g->blue = 255;
      		if(g->side == 0)
      			g->blue /= 2;
      	}
      	else if(g->map[g->mapx][g->mapy] == 4)
      	{
      		g->red = 255;
      		g->green = 255;
      		g->blue = 255;
      		if(g->side == 0)
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

      	g->lineh = H / g->perpwalldist;
      	g->drawstart = -g->lineh / 2 + H / 2;
      	if(g->drawstart < 0)
      		g->drawstart = 0;
      	g->drawend = g->lineh / 2 + H / 2;
      	if(g->drawend > H)
      		g->drawend = H - 1;


      	ft_verline(x, g->drawstart, g->drawend, g);
		x++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	ft_menu(g);
}

void ft_test(t_gen *g)
{
	int x;
	int y;

	x = 0;
	while(x < g->larg_y)
	{
		y = 0;
		while(y < g->larg_x)
		{
			printf("%d ", g->map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_gen g;

	ft_bzero(&g, sizeof(g));
	if (argc != 2 || argv[1][ft_strlen(argv[1]) - 1] != 'l'
			|| argv[1][ft_strlen(argv[1]) - 2] != 'o'
			|| argv[1][ft_strlen(argv[1]) - 3] != 'w'
			|| argv[1][ft_strlen(argv[1]) - 4] != '.')
	{
		ft_putstr("need file .wol");
		return (0);
	}
	if (ft_pars(&g, argv[1]) == -1)
	{
		ft_putstr("error");
		return (0);
	}
	if (init(&g) == -1)
		return (0);
	ft_test(&g);
	ft_init_str(&g);
	ft_start_algo(&g);
	mlx_hook(g.win, 2, 1L << 0, &key_pressed, &g);
	mlx_hook(g.win, 17, (1L << 17), &red_cross, &g);
	mlx_loop(g.mlx);
}