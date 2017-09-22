/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 18:38:14 by mpinson           #+#    #+#             */
/*   Updated: 2017/09/09 18:39:35 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
#include <stdio.h>

# define W (2560 / 2)
# define H (1440 / 2)

typedef	struct		s_gen
{
	int				**map;
	int 			mini_map[5][5];
	int				larg_x;
	int				larg_y;
	void			*win;
	void			*mlx;
	void			*img;
	void			*cursor;
	int				cursor_x;
	int				cursor_y;
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
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadisty;
	double			deltadistx;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				red;
	int				green;
	int				blue;
	int				red2;
	int				green2;
	int				blue2;
	int				lineh;
	int				drawstart;
	int				drawend;
	double			sprint;
	int				hidd_menu;
	int				map_affiche;
	int				menu_mod;
	int				pos_curseur;
	char			*path_save;
	double			old_posx;
	double			old_posy;
	int				x_map_1;
	int				y_map_1;
	int				x_map;
	int				y_map;
	int				limit_x;
	int				limit_y;
	int				save_y;
}					t_gen;

int					ft_pars(t_gen *g, char *pass);
void				load(t_gen *g);
int					key_menu1(int kc, t_gen *g);
void				key_pressed_deplace(int kc, t_gen *g,
	double olddir, double oldplan);
void				key_pressed_color(int kc, t_gen *g);
void				affiche(t_gen *g);
void				ft_free_tab(char **tab);
int					ft_strlen_tab(char **tab);
int					ft_strlen_s(char *str);
long				ft_atol(const char *str);
int					init(t_gen *g);
int					red_cross(t_gen *g);
int					key_pressed(int kc, t_gen *g);
void				ft_putpixel_in_img(int x,
	int y, t_gen *g, unsigned int color);
void				ft_start_algo(t_gen *g);
void				ft_setimage(t_gen *g);
void				ft_init_str(t_gen *g);
void				ft_verline(int x, int start, int end, t_gen *g);
void				ft_menu(t_gen *g);
void				init_algo(t_gen *g, int x);
int					ft_init(t_gen *g, char *pass);
int					go_malloc1(char **tab, int y, t_gen *g);
int ft_clic(int button, int x,int y, t_gen *g);

#endif
