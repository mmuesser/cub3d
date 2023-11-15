/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:36:06 by pineau            #+#    #+#             */
/*   Updated: 2023/11/15 16:54:26 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
// # include <mlx.h>
// # include <key_code.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define KEY_ESCAPE 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define PI 3.1415926535

# define WIDTH        	1920
# define HEIGHT        	1080

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	// int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	a;
	int		size;
	int		color;
}	t_player;

typedef struct s_map
{
	int		mapx;
	int		mapy;
	int		maps;
	char	**map;
}	t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_player		*player;
	t_map			*map;
	double			dx;
	double			dy;
}	t_data;

/*main.c*/
void		init(void);
void		end(t_data *data);
void		put_pixel(t_img *img, int x, int y, int color);
void		erase_player(t_data *data);

// /*get_next_line*/
// char		*get_next_line(int fd);
// int			ft_strlen(char *str);
// char		*ft_strdup(char *s);
// char		*ft_strjoin(char *s1, char *s2);
// char		*ft_substr(char *s, unsigned int start, size_t len);

/*get_line.c*/
void		get_line(t_data *data);

/*init.c*/
void		init_player(t_data *data);
int			init_data(t_data *data);
void		init_map(t_data *data);
void		tab_maker(t_data *data);

/*draws.c*/
void		draw_backgroud(t_data *data);
void		draw_player(t_data *data);
void		draw_map(t_data *data);
void		draw_line(t_data *data, char *str);
void		draw_all(t_data *data);
void		draw_angle(t_data *data);
void		draw_ray(t_data *data);

/*hook.c*/
void		init_hook(t_data *data);
int			cross_p(t_data *data);
int			key_press(int keysym, t_data *data);

/*keys_moves.c*/
void		key_down(t_data *data);
void		key_up(t_data *data);
void		key_right(t_data *data);
void		key_left(t_data *data);







/*tmp*/
void	draw_square(t_data *data, int x, int y, int color);
void	draw_squares(t_data *data);
// void	draw_line(t_data *data, double x1, double y1, double x2, double y2);
void	draw_lines(t_data *data);
void	draw_grid(t_data *data);
int	draw_loop(t_data *data);
void	draw_dir_ray(t_data *data, double angle);
void	draw_ray(t_data *data);
int		ardi(double nombre);


/*parsing.c*/
char	**split_file(char *tmp);

#endif
