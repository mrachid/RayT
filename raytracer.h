/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzimini <jzimini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 09:15:56 by jzimini           #+#    #+#             */
/*   Updated: 2014/03/26 16:27:36 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <libft.h>
# include <math.h>

# define WIDTH 1280.0
# define HEIGHT 896.0

# define PV_WIDTH 0.5
# define PV_HEIGHT 0.35
# define PV_DIST 1.0

# define IND_X PV_WIDTH / WIDTH
# define IND_Y PV_HEIGHT / HEIGHT

# define ITEMS 4

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sl;
	int				endian;
}					t_mlx;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef t_point		t_vect;

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct		s_sphere
{
	t_point			*center;
	double			radius;
}					t_sphere;

typedef struct		s_cone
{
	t_point			*center;
	t_vect			*axis;
	double			radius;
	double			angle;
}					t_cone;

typedef struct		s_cyl
{
	t_point			*center;
	t_vect			*axis;
	double			radius;
}					t_cyl;

typedef struct		s_plane
{
	t_vect			*vect;
	t_point			*center;
	double			d;
}					t_plane;

typedef struct		s_item
{
	char			*name;
	void			*item;
	t_color			*color;
	struct s_item	*prev;
	struct s_item	*next;
}					t_item;

typedef struct		s_itemfun
{
	char			*item;
	t_vect			*(*norm)(void *, t_point *, t_vect *);
	double			(*intsec)(void *, t_point *, t_vect *);
	void			(*clear)(void **);
	void			(*fill)(t_list **list, t_item **itemlist);
}					t_itemfun;

typedef struct		s_cam
{
	t_point			*pos;
	t_vect			*dir;
	t_vect			*up;
	t_vect			*right;
	double			min;
}					t_cam;

typedef struct		s_light
{
	char			*type;
	t_point			*pos;
	t_color			*color;
	struct s_light	*prev;
	struct s_light	*next;
}					t_light;

typedef struct		s_scene
{
	char			*name;
	t_point			*upleft;
	t_cam			*cam;
	t_item			*items;
	t_light			*lights;
}					t_scene;

typedef struct		s_info
{
	t_mlx			*mlx;
	t_scene			*scene;
}					t_info;

void				check_line(char *line);
void				main_2();
int					start(int fd);
void				ft_tmp(t_mlx *mlx, char **str, t_scene *scene);
void				ft_tmp2(t_mlx *m, t_scene *sc);
t_scene				*create_scene(void);
void				ft_begining(t_info *info);
t_itemfun			*get_item_fun(void);
t_item				*new_item(void *item, char *name, t_color *color);
void				add_item(t_item **itemlist, char *name, void *item,
		t_color *color);
t_vect				*new_vect(double x, double y, double z);
double				normalize_vect(t_vect *vect);
t_vect				*cross_product(t_vect *v1, t_vect *v2);
double				find_angle(t_vect *v1, t_vect *v2);
t_vect				*get_dir_vect(t_point *upleft, t_cam *cam, int x, int y);
t_point				*new_point(double x, double y, double z);
t_point				*get_upleft(t_cam *cam);
t_point				*get_dist_pos(t_point *pos, t_vect *dir, double min);
t_plane				*new_plane(t_vect *vect, t_point *center);
double				plane_intsec(void *plane, t_point *orig, t_vect *dir);
t_vect				*plane_norm(void *plane, t_point *orig, t_vect *dir);
void				inverse_plane(t_item *itemlist, t_cam *cam);
void				clear_plane(void **plane);
t_sphere			*new_sphere(double x, double y, double z, double radius);
t_vect				*sphere_norm(void *sphere, t_point *orig, t_vect *dir);
double				sphere_intsec(void *sphere, t_point *orig, t_vect *dir);
void				clear_sphere(void **sphere);
double				get_closer(double t1, double t2);
t_cyl				*new_cyl(t_point *center, t_vect *axis, double rad);
double				cyl_intsec(void *cyl, t_point *orig, t_vect *dir);
t_vect				*cyl_norm(void *cyl, t_point *orig, t_vect *dir);
t_cone				*new_cone(t_point *center, t_vect *axis, double rad,
		double angle);
double				cone_intsec(void *cone, t_point *orig, t_vect *dir);
t_vect				*cone_norm(void *cone, t_point *orig, t_vect *dir);
t_light				*new_light(char *type, t_point *pos, t_color *color);
void				add_light(t_light **lightlist, char *type, t_point *pos,
		t_color *color);
int					light_color(t_item *item, t_light *light, t_vect *vect,
		t_point *point);
int					get_light(t_item *cls, t_item *itm, t_light *li,
		t_point *pos);
t_color				*new_color(double r, double g, double b);
int					find_color(t_color *icolor, t_color *lcolor, double cos);
int					color_int(t_color *color);
void				process_pixel(t_mlx *m, int x, int y, int color);
char				**ft_rec(int fd, char *line);
t_scene				*ft_parser(char **str, t_scene *scn);
int					ft_compar(char **tab, int i, t_scene **scn);
int					plane(char **tab, int i, t_item **items);
int					sph(char **tab, int i, t_item **items);
int					cylinder(char **tab, int i, t_item **items);
int					cone(char **tab, int i, t_item **items);
int					light(char **tab, int i, t_light **light);
int					cam(char **tab, int i, t_cam **cam);

#endif
