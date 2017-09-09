#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include "mlx.h"

typedef	struct		s_gen
{
	int				**ad_x;
	int				**ad_y;
	int				**ad_z;
	int				**bd_x;
	int				**bd_y;
	int				larg_x;
	int				larg_y;
	void			*win;
	void			*mlx;
	void			*img;
	char			*img_ptr;
	int				bpp;
	int				s_l;
	int				endian;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	float			zoom;
	int				x;
	int				y;
	int				color;
	float			xrot;
	float			yrot;
	int				test;
}					t_gen;

typedef	struct		s_bresenham
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_bresenham;

int	ft_pars(t_gen *g, char *pass);
void	ft_free_tab(char **tab);
int		ft_strlen_tab(char **tab);
int		ft_strlen_s(char *str);
long	ft_atol(const char *str);
int		init(t_gen *g);

#endif