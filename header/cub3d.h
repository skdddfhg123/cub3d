/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:54:19 by idongmin          #+#    #+#             */
/*   Updated: 2022/11/30 18:33:41 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define GL_SILENCE_DEPRECATION
# include "../lib/include/get_next_line.h"
# include "../lib/include/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>

# define FALSE 0
# define TRUE 1

# define NORTH				0
# define SOUTH				1
# define EAST				2
# define WEST				3
# define FLOOR				5
# define CEILING			6
# define MAP				7
# define EMPTY				'0'
# define WALL				'1'
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define TEX_WIDTH			64
# define TEX_HEIGHT 		64

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_ESC	53

# define EPS 1e-06
# define WALL_H 1
# define SX 1080
# define SY 720
# define FOV 60
# define ROT_UNIT 0.13
# define MOVE_UNIT 0.2
# define VERT 0
# define HORIZ 1

typedef struct s_img
{
	void			*ptr;
	int				*data;
	int				size_line;
	int				bpp;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct s_user
{
	double			pos_x;
	double			pos_y;
	char			spawn_pos;
}					t_user;

typedef struct s_ray
{
	double	th;
	int		xstep;
	int		ystep;
	double	xslope;
	double	yslope;
	double	nx;
	double	ny;
	double	f;
	double	g;
	int		hit;
	int		hit_side;
	int		mapx;
	int		mapy;
	double	dist_v;
	double	dist_h;
}	t_ray;

typedef struct s_ele
{
	double			wx;
	double			wy;
	int				wdir;
	int				wh;
	int				y0;
	int				y1;
	int				floor;
	int				ceiling;
	int				color;
	char			*xpm_path[4];
	int				tex[4][TEX_HEIGHT * TEX_WIDTH];
}					t_ele;

typedef struct s_cub
{
	void			*mlx;
	void			*win;
	int				fd;
	char			**map;
	int				map_width;
	int				map_height;
	int				map_flag;
	t_list			*map_lines;
	t_user			user;
	t_ele			ele;
	t_img			img;
	t_ray			ray;
}					t_cub;

/* CheckMap */
void				check_map(t_cub *cub);
int					check_type(t_cub *cub, char **word, int wordcnt);
void				set_color(t_cub *cub, char *rgb_color, int type);
void				set_texure(t_cub *cub, char *xpm_path, int type);
void				error_check(t_cub *cub);

/*
** Util
*/
int					ft_filecheck(char *s1, char *s2);
void				ft_exit(char *str);
size_t				ft_wordcnt(char const *s, char c);
void				ft_two_point_free(char **arr);
char				*ft_strdup_nl(const char *str);
int					ft_isdigit_str(const char *str);
int					ft_isformat(char *str, char *fmt);
size_t				ft_find_maxwidth(t_list *lst);

/* setTexture.c */
void				set_texture(t_cub *cub);
void				get_texture_from_xpm(t_cub *cub, int *tex, \
										char *xpm_path, t_img *img);

/* raycastUtils.c */
int					map_get_cell(t_cub *cub, int x, int y);
int					sgn(double d);
double				l2dist(double x0, double y0, double x1, double y1);

/* raycastWall.c */
double				cast_single_ray(t_cub *cub, int x, double th);
int					get_wall_intersection(t_cub *cub, double ray, \
										double *wx, double *wy);

/* raycastHeight.c */
int					get_wall_height(double dist);
void				get_color(t_cub *cub, int y, double lum);
void				draw_wall(t_cub *cub, double wdist, int x);
/* settingRay.c */
void				set_wall_state(t_cub *cub, double *wx, double *wy);
void				set_nx_ny(t_cub *cub, double px, double py);
void				set_mapx_mapy(t_cub *cub);
void				init_ray(t_cub *cub, double ray, double px, double py);

/* key.c */
int					exit_cub3d(void);
int					key_press(int key, t_cub *cub);

/* start.c */
void				init_mlx(t_cub *cub);
void				start(t_cub	*cub);

/* render.c */
int					render(t_cub *cub);
void				set_wall(t_cub *cub);

/* fadeColor.c */
int					fade_color(int color, double lum);
int					encode_color(int r, int g, int b);
void				decode_color(int color, int *r, int *g, int *b);
double				get_luminosity(t_cub *cub, double dist);

/* mathUtil.c */
double				is_zero(double d);
double				deg2rad(double d);
double				rad2deg(double d);
double				fov_h(void);
double				fov_v(void);
double				angle_per_pixel(void);
double				half_fov_h(void);
double				pi_2(void);
int					min(int x, int y);
int					max(int x, int y);
#endif
