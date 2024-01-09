/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:36:06 by pineau            #+#    #+#             */
/*   Updated: 2024/01/08 16:41:17 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define KEY_ESCAPE 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65
# define KEY_DOWN 83

# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define WIDTH        	1920
# define HEIGHT        	1080

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	char	*path;
	void	*texture;
}	t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	xx;
	double	yy;
	double	endx;
	double	endy;
	double	tmpa;
	double	line;
	double	dx;
	double	dy;
	double	a;
	double	distance;
	int		nbr_ray;
	int		size;
	int		color;
	int		side;
	double	fov_degrees;
	double	fov_radians;
	double	fov_correction;
}	t_player;

typedef struct s_map
{
	int		mapx;
	int		mapy;
	int		maps;
	char	**desc;
	char	**map;
	int		floor;
	int		ceiling;
}	t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_img			*no;
	t_img			*so;
	t_img			*we;
	t_img			*ea;
	t_player		*player;
	t_map			*map;
	char			**file;
}	t_data;

/*main.c*/
void		init(void);
void		end(t_data *data);

/*init.c*/
void		init_player(t_data *data);
int			init_data(t_data *data);
void		init_map(t_data *data);
void		tab_maker(t_data *data);
int			init_images(t_data *data);
void		fill_path(t_data *data);

/*draws.c*/
void		draw_backgroud(t_data *data);
void		draw_player(t_data *data);
void		draw_line(t_data *data, char *str);
void		draw_all(t_data *data);
double		draw_rayy(t_data *data);
double		draw_rayx(t_data *data);
int			mode2(t_data *data, double tmpx, double tmpy);
int			mode1(t_data *data, double tmpx, double tmpy);
int			draw_ray2(t_data *data);
int			hit_wall2(t_data *data, double i, int mode);
double		draw_rayy2(t_data *data);
double		draw_rayx2(t_data *data);

/*colors.c*/
void		put_pixel(t_img *img, int x, int y, int color);
int			extract_component(char *str, int *pos);
int			rgb_to_int(char *rgb_str);
void		find_rgb(t_data *data);

/*hook.c*/
void		init_hook(t_data *data);
int			cross_p(t_data *data);
int			key_press(int keysym, t_data *data);
void		key_a(t_data *data);
void		key_d(t_data *data);

/*keys_moves.c*/
void		key_down(t_data *data);
void		key_up(t_data *data);
void		key_right(t_data *data);
void		key_left(t_data *data);

/*look.c*/
int			look(t_data *data, int mode);
int			look_right(t_data *data);
int			look_left(t_data *data);
int			look_top(t_data *data);
int			look_bot(t_data *data);

/*print.c*/
void		print_rays(t_data *data);
void		print_rays2(t_data *data);
void		draw_map(t_data *data);
void		draw_player(t_data *data);

/*tmp*/
void		draw_lines(t_data *data);
void		draw_grid(t_data *data);
int			draw_ray(t_data *data);
int			draw_ray2(t_data *data);

/*3d.c*/
void		test_3d(t_data *data);
void		print_line2(t_data *data, double i, double j, int color);

/*parsing.c*/
char		**split_file_line(char *tmp);

/*utils2.c*/
char		*get_path(char *str);

/*textures.c*/
void		init_textures(t_data *data);
void		which_sprite(t_data *data, double len, double start);
void		print_east(t_data *data, double len, double start, double ray);
void		print_west(t_data *data, double len, double start, double ray);
void		print_south(t_data *data, double len, double start, double ray);
void		print_north(t_data *data, double len, double start, double ray);

void		free_img(t_data *data);
int			check_ext(char *file_name, char *ext);

t_data		*split_desc_and_map(t_data *data, char **file);

int			check_desc(char **desc);

t_data		*parsing(t_data *data, int ac, char **av);

int			check_map(char **map);

int			free_all(t_data *data);
void		free_data(t_data *data);

int			error(int i);

void		fill_line(char **line, char *src, int len);
void		print_tab(char **tab);
void		free_tab(char **tab);
int			len_tab(char **map);
int			max_len(char **map);

#endif
