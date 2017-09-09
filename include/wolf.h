#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include "mlx.h"
#include <math.h>

#define W (2560 / 2)
#define H (1440 / 2)

typedef	struct		s_gen
{
	int				**map;
	int				larg_x;
	int				larg_y;
	void			*win;
	void			*mlx;
	void			*img;
	char			*img_ptr;
	int				bpp;
	int				s_l;
	int				endian;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	double			time;
	double			oldtime;
	double			camerax;

	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int 			mapx;
	int 			mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadisty;
	double			deltadistx;
	double			perpwalldist;
	int 			stepx;
	int 			stepy;
	int 			hit;
	int 			side;

	int 			red;
	int 			green;
	int 			blue;

	int 			red2;
	int 			green2;
	int 			blue2;

	int 			lineh;
	int 			drawstart;
	int 			drawend;
	double 			sprint;
}					t_gen;

int	ft_pars(t_gen *g, char *pass);
void	ft_free_tab(char **tab);
int		ft_strlen_tab(char **tab);
int		ft_strlen_s(char *str);
long	ft_atol(const char *str);
int		init(t_gen *g);
int		red_cross(t_gen *g);
int		key_pressed(int kc, t_gen *g);
void	ft_putpixel_in_img(int x, int y, t_gen *g, unsigned int color);
void ft_start_algo(t_gen *g);
void ft_setimage(t_gen *g);
void ft_init_str(t_gen *g);

#endif