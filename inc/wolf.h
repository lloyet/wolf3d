/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 19:44:01 by augberna     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/27 00:49:57 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _WOLF_H
# define _WOLF_H

# include "../lib/minilibx_macos/mlx.h"
# include "../lib/libft/libft.h"
# include <stdint.h>
# include <math.h>
# include <sys/time.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define RGBA(r,g,b,a)				(a << 24) | (r << 16) | (g << 8) | (b)

# define WIDTH						1920
# define WIDTH_2					WIDTH*0.5
# define HEIGH						1080
# define HEIGH_2					HEIGH*0.5

# define TEX_BUFF_S					5

# define M_DEG						180.0/M_PI
# define M_RAD						M_PI/180.0

# define VIEW_MAX					256

# define FOV						90.0
# define FOV_2						FOV*0.5
# define FOVRAD						FOV*M_RAD
# define FOVRAD_2					FOV_2*M_RAD

# define P_SENSI					0.075
# define P_VELO						0.05

# define IA_VELO					0.10

# define KEYBOARD_S					285
# define REG_KMASK_MAX				32
# define VOXEL_SIZE					8

# define KEY_ESCAPE					53
# define KEY_F1						122
# define KEY_F2						120
# define KEY_F3						99
# define KEY_F4						118
# define KEY_F5						96
# define KEY_F6						97
# define KEY_F7						98
# define KEY_F8						100
# define KEY_F9						101
# define KEY_F10					109
# define KEY_F11					103
# define KEY_F12					111
# define KEY_F13					105
# define KEY_F14					107
# define KEY_F15					113
# define KEY_F16					106
# define KEY_F17					64
# define KEY_F18					79
# define KEY_F19					80
# define KEY_TILDE					50
# define KEY_1						18
# define KEY_2						19
# define KEY_3						20
# define KEY_4						21
# define KEY_5						23
# define KEY_6						22
# define KEY_7						26
# define KEY_8						28
# define KEY_9						25
# define KEY_0						29
# define KEY_MINUS					27
# define KEY_EQUAL					24
# define KEY_BACKSPACE				51
# define KEY_TAB					48
# define KEY_Q						12
# define KEY_W						13
# define KEY_E						14
# define KEY_R						15
# define KEY_T						17
# define KEY_Y						16
# define KEY_U						32
# define KEY_I						34
# define KEY_O						31
# define KEY_P						35
# define KEY_OPEN_BRACKET			33
# define KEY_OPEN_BRACE				33
# define KEY_CLOSE_BRACKET			30
# define KEY_CLOSE_BRACE			30
# define KEY_BACKSLASH				42
# define KEY_PIPE					42
# define KEY_CAPSLOCK				272
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2
# define KEY_F						3
# define KEY_G						5
# define KEY_H						4
# define KEY_J						38
# define KEY_K						40
# define KEY_L						37
# define KEY_COLON					41
# define KEY_SEMI_COLON				41
# define KEY_SIMPLE_QUOTE			39
# define KEY_DOUBLE_QUOTES			39
# define KEY_ENTER					36
# define KEY_SHIFT_LEFT				257
# define KEY_Z						6
# define KEY_X						7
# define KEY_C						8
# define KEY_V						9
# define KEY_B						11
# define KEY_N						45
# define KEY_M						46
# define KEY_LESS_THAN				43
# define KEY_COMMA					43
# define KEY_GREATER_THAN			47
# define KEY_DOT					47
# define KEY_SLASH					44
# define KEY_QUESTION_MARK			44
# define KEY_SHIFT_RIGHT			258
# define KEY_CTRL_LEFT				256
# define KEY_COMMAND_LEFT			259
# define KEY_OPTION_LEFT			261
# define KEY_ALT					261
# define KEY_SPACE					49
# define KEY_COMMAND_RIGHT			260
# define KEY_ALT_GR					262
# define KEY_FN						279
# define KEY_CTRL_RIGHT				269
# define KEY_LEFT					123
# define KEY_DOWN					125
# define KEY_RIGHT					124
# define KEY_UP						126
# define KEY_DEL					117
# define KEY_HOME					115
# define KEY_END					119
# define KEY_PAGE_UP				116
# define KEY_PAGE_DOWN				121
# define KEY_CLEAR					71
# define KEY_PAD_1					83
# define KEY_PAD_2					84
# define KEY_PAD_3					85
# define KEY_PAD_4					86
# define KEY_PAD_5					87
# define KEY_PAD_6					88
# define KEY_PAD_7					89
# define KEY_PAD_8					91
# define KEY_PAD_9					92
# define KEY_PAD_0					82
# define KEY_PAD_EQUAL				81
# define KEY_PAD_DIVIDE				75
# define KEY_PAD_MULTIPLY			67
# define KEY_PAD_SUB				78
# define KEY_PAD_ADD				69
# define KEY_PAD_ENTER				76
# define KEY_PAD_DOT				65
# define MOUSE_LEFT					280
# define MOUSE_RIGHT				281
# define MOUSE_MID					282
# define SCROLL_UP					283
# define SCROLL_DOWN				284

# define KEYPRESS					2
# define KEYRELEASE					3
# define BUTTONPRESS				4
# define BUTTONRELEASE				5
# define MOTIONNOTIFY				6
# define ENTERNOTIFY				7
# define LEAVENOTIFY				8
# define FOCUSIN					9
# define FOCUSOUT					10
# define KEYMAPNOTIFY				11
# define EXPOSE						12
# define GRAPHICSEXPOSE				13
# define NOEXPOSE					14
# define VISIBILITYNOTIFY			15
# define CREATENOTIFY				16
# define DESTROYNOTIFY				17
# define UNMAPNOTIFY				18
# define MAPNOTIFY					19
# define MAPREQUEST					20
# define REPARENTNOTIFY				21
# define CONFIGURENOTIFY			22
# define CONFIGUREREQUEST			23
# define GRAVITYNOTIFY				24
# define RESIZEREQUEST				25
# define CIRCULATENOTIFY			26
# define CIRCULATEREQUEST			27
# define PROPERTYNOTIFY				28
# define SELECTIONCLEAR				29
# define SELECTIONREQUEST			30
# define SELECTIONNOTIFY			31
# define COLORMAPNOTIFY				32
# define CLIENTMESSAGE				33
# define MAPPINGNOTIFY				34
# define LASTEVENTS					35
# define NOEVENTMASK				0L
# define KEYPRESSMASK				(1L<<0)
# define KEYRELEASEMASK				(1L<<1)
# define BUTTONPRESSMASK			(1L<<2)
# define BUTTONRELEASEMASK			(1L<<3)
# define ENTERWINDOWMASK			(1L<<4)
# define LEAVEWINDOWMASK			(1L<<5)
# define POINTERMOTIONMASK			(1L<<6)
# define POINTERMOTIONHINTMASK		(1L<<7)
# define BUTTON1MOTIONMASK			(1L<<8)
# define BUTTON2MOTIONMASK			(1L<<9)
# define BUTTON3MOTIONMASK			(1L<<10)
# define BUTTON4MOTIONMASK			(1L<<11)
# define BUTTON5MOTIONMASK			(1L<<12)
# define BUTTONMOTIONMASK			(1L<<13)
# define KRYMAPSTATEMASK			(1L<<14)
# define EXPOSUREMASK				(1L<<15)
# define VISIBILITYCHANGEMASK		(1L<<16)
# define STRUCTURENOTIFYMASK		(1L<<17)
# define RESIZEREDIRECTMASK			(1L<<18)
# define SUBSTRUCTURENOTIFYMASK		(1L<<19)
# define SUBSTRUCTUREREDIRECTMASK	(1L<<20)
# define FOCUSCHANGEMASK			(1L<<21)
# define PROPERTYCHANGEMASK			(1L<<22)
# define COLORMAPCHANGEMASK			(1L<<23)
# define OWNERGRABBUTTONMASK		(1L<<24)

typedef struct		s_keyboard
{
	uint64_t		reg_key;
	int				reg_size;
	uint8_t			*reg_id;
}					t_keyboard;

typedef struct		s_mouse
{
	int				x;
	int				y;
	t_keyboard		*keyboard;
}					t_mouse;

typedef struct		s_angle
{
	double			f_theta;
	double			f_cos;
	double			f_sin;
}					t_angle;

typedef struct		s_vector2d
{
	double			x;
	double			y;
}					t_vector2d;

typedef struct		s_mat2x2
{
	double			m[2][2];
}					t_mat2x2;

typedef struct		s_entity
{
	t_vector2d		coord;
	t_vector2d		dir;
	t_angle			angle;
	t_vector2d		vel;
	t_vector2d		straf;
	double			f_velo_cur;
	double			f_velo_def;
	uint8_t			anchor;
}					t_entity;

typedef struct		s_camera
{
	t_vector2d		plane;
	t_entity		*entity;
	double			f_sensi;
	double			f_view_max;
}					t_camera;

typedef struct		s_image
{
	void			*id;
	char			*data;
	int				bpp;
	int				size_l;
	int				endian;
	int				width;
	int				heigh;
}					t_image;

typedef struct		s_window
{
	void			*id;
	void			*mlx_id;
	char			*title;
	int				width;
	int				heigh;
	uint8_t			menu;
	t_image			*img;
}					t_window;

typedef struct		s_framework
{
	void			*id;
	t_window		*win;
	double			frame;
}					t_framework;

typedef struct		s_wall
{
	t_image			*face[4];
}					t_wall;

typedef struct		s_ray
{
	t_vector2d		origin;
	t_vector2d		dir;
	t_vector2d		side_dist;
	t_vector2d		t_wallex;
	t_vector2d		d_dist;
	double			wall_proj_dist;
	int				wall_height;
	int				tex_id;
	int				wall_side;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	int				light;
	double			light_ratio;
}					t_ray;

typedef struct		s_world
{
	t_vector2d		spawn;
	int				*data;
	int				width;
	int				heigh;
	char			*file_name;
}					t_world;

typedef struct		s_engine
{
	t_framework		*mlx;
	t_keyboard		*keyboard;
	t_mouse			*mouse;
	t_entity		*player;
	t_entity		*ia;
	t_camera		*cam;
	t_world			*world;
	t_wall			**wall_buff;
	t_image			*tex_buff[TEX_BUFF_S];
	int				wall_s;
	struct timeval	old;
	struct timeval	cur;
}					t_engine;

int					mouse_motion_hook(int x, int y, t_mouse *mouse);
int					mouse_press_hook(int key, int x, int y, t_mouse *mouse);
int					mouse_release_hook(int key, int x, int y, t_mouse *mouse);
int					key_press_hook(int key, t_keyboard *keyboard);
int					key_release_hook(int key, t_keyboard *keyboard);
int					destroy_window_hook(t_engine *engine);

void				mouse_destroy(t_mouse *mouse);
t_mouse				*new_mouse(t_keyboard *keyboard);
void				keyboard_destroy(t_keyboard *keyboard);
t_keyboard			*new_keyboard(int size);
int					register_new_key(t_keyboard *keyboard, int key);

void				entity_destroy(t_entity *e);
t_entity			*new_entity(double vel_default, uint8_t anchor);
void				entity_set_location(t_entity *e, int x, int y);
void				entity_set_orientation(t_entity *e, double deg);
void				entity_try_move(t_world *w, t_entity *e);
void				entity_view(t_engine *engine);

t_angle				*new_angle(double f_theta);
void				angle_destroy(t_angle *angle);
void				angle_reset(t_angle *angle, double f_theta);
double				t_angleo_degree(t_vector2d *v);
void				t_angleo_radian(t_vector2d *v, double deg);

t_world				*new_world(char *file_name);
void				world_destroy(t_world *w);
void				world_set_spawn(t_world *w, int x, int y);
int					world_get_obj(t_world *w, int x, int y);
t_world				*world_init(char *file_name);

void				ray_cast(t_engine *e, t_camera *cam);
void				ray_init(t_ray *r, t_camera *c, double camera_x);
void				ray_draw_wall(t_ray *r, t_image *img, int *draw, int x);

void				debug_display(t_engine *e);

t_engine			*new_engine(void);
void				engine_destroy(t_engine *e);

void				mat2x2_set_rot_y(t_angle *t);
void				vector_vec_product(t_vector2d *v_dest, t_vector2d *v_mult);
void				vector_rot_y(t_vector2d *v);
void				vector_reset(t_vector2d *v);
void				vector_set(t_vector2d *v, double x, double y);

void				event_refresh(t_engine *engine, t_keyboard *keyboard,
						t_camera *cam);
void				event_docker(t_engine *engine, t_keyboard *k, t_camera *c);

void				window_destroy(t_window *win);
t_window			*new_window(void *mlx_id, int width, int heigh,
						char *title);
void				framework_destroy(t_framework *framework);
t_framework			*new_framework(void);

void				image_destroy(void *mlx, t_image *img);
t_image				*new_image(void *mlx, int width, int heigh);
void				image_clear(t_image *img);
void				image_pixel_put(t_image *img, int x, int y, int color);
int					image_get_pixel(t_image *img, int x, int y);

t_image				*new_texture(void *mlx, char *file_name);
int					texture_init(void *mlx, t_image **tex_buff);
void				texture_uninit(void *mlx, t_image **tex_buff);

t_wall				**wall_init(t_image **tex_buff, int size);
t_wall				*new_wall(t_image *f0, t_image *f1, t_image *f2, t_image *f3);
void				wall_set_face(t_wall *wall, int face, t_image *f);
void				wall_destroy(t_wall *wall);
void				wall_uninit(t_wall **wall_buf);

int					parser_get_world(t_world *w);
int					parser_get_world_size(t_world *w);

t_camera			*new_camera(double f_sensi, double fov_2, double view);
void				camera_destroy(t_camera *c);
void				camera_dock(t_camera *c, t_entity *e);
void				camera_view(t_window *w, t_mouse *m, t_camera *c);

#endif
