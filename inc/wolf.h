/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/15 01:03:27 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 18:30:53 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef								_WOLF_H
#define                             _WOLF_H

# include                           "../lib/minilibx_macos/mlx.h"
# include                           "../lib/libft/libft.h"
# include                           <stdint.h>
# include                           <math.h>
# include                           <sys/time.h>
# include                           <sys/types.h>
# include                           <sys/stat.h>
# include                           <stdio.h>
# include                           <fcntl.h>

# define RGBA(r,g,b,a)              (a << 24) | (r << 16) | (g << 8) | (b)

# define WIDTH                      1920
# define WIDTH_2                    WIDTH*0.5
# define HEIGH                      1080
# define HEIGH_2                    HEIGH*0.5

# define TEX_BUFF_S                 5

# define M_DEG                      180.0/M_PI
# define M_RAD                      M_PI/180.0

# define VIEW_MAX                   256

# define FOV                        90.0
# define FOV_2                      FOV*0.5
# define FOVRAD                     FOV*M_RAD
# define FOVRAD_2                   FOV_2*M_RAD

# define P_SENSI                    0.075
# define P_VELO                     0.05

# define IA_VELO                    0.10

# define KEYBOARD_S                 285
# define REG_KMASK_MAX              32
# define VOXEL_SIZE                 8

# define KEY_ESCAPE	                53
# define KEY_F1 			        122
# define KEY_F2				        120
# define KEY_F3				        99
# define KEY_F4				        118
# define KEY_F5				        96
# define KEY_F6				        97
# define KEY_F7				        98
# define KEY_F8				        100
# define KEY_F9				        101
# define KEY_F10			        109
# define KEY_F11			        103
# define KEY_F12			        111
# define KEY_F13			        105
# define KEY_F14			        107
# define KEY_F15			        113
# define KEY_F16			        106
# define KEY_F17			        64
# define KEY_F18      				79
# define KEY_F19			        80
# define KEY_TILDE			        50
# define KEY_1				        18
# define KEY_2				        19
# define KEY_3				        20
# define KEY_4				        21
# define KEY_5				        23
# define KEY_6				        22
# define KEY_7				        26
# define KEY_8				        28
# define KEY_9				        25
# define KEY_0				        29
# define KEY_MINUS			        27
# define KEY_EQUAL			        24
# define KEY_BACKSPACE		        51
# define KEY_TAB					48
# define KEY_Q				        12
# define KEY_W				        13
# define KEY_E				        14
# define KEY_R				        15
# define KEY_T				        17
# define KEY_Y				        16
# define KEY_U				        32
# define KEY_I				        34
# define KEY_O				        31
# define KEY_P				        35
# define KEY_OPEN_BRACKET	        33
# define KEY_OPEN_BRACE		        33
# define KEY_CLOSE_BRACKET	        30
# define KEY_CLOSE_BRACE	        30
# define KEY_BACKSLASH		        42
# define KEY_PIPE			        42
# define KEY_CAPSLOCK		        272
# define KEY_A				        0
# define KEY_S				        1
# define KEY_D				        2
# define KEY_F				        3
# define KEY_G				        5
# define KEY_H				        4
# define KEY_J				        38
# define KEY_K				        40
# define KEY_L				        37
# define KEY_COLON			        41
# define KEY_SEMI_COLON		        41
# define KEY_SIMPLE_QUOTE	        39
# define KEY_DOUBLE_QUOTES	        39
# define KEY_ENTER			        36
# define KEY_SHIFT_LEFT		        257
# define KEY_Z				        6
# define KEY_X				        7
# define KEY_C				        8
# define KEY_V				        9
# define KEY_B				        11
# define KEY_N				        45
# define KEY_M				        46
# define KEY_LESS_THAN		        43
# define KEY_COMMA			        43
# define KEY_GREATER_THAN	        47
# define KEY_DOT			        47
# define KEY_SLASH			        44
# define KEY_QUESTION_MARK	        44
# define KEY_SHIFT_RIGHT	        258
# define KEY_CTRL_LEFT		        256
# define KEY_COMMAND_LEFT	        259
# define KEY_OPTION_LEFT	        261
# define KEY_ALT			        261
# define KEY_SPACE			        49
# define KEY_COMMAND_RIGHT	        260
# define KEY_ALT_GR			        262
# define KEY_FN				        279
# define KEY_CTRL_RIGHT		        269
# define KEY_LEFT			        123
# define KEY_DOWN			        125
# define KEY_RIGHT			        124
# define KEY_UP				        126
# define KEY_DEL			        117
# define KEY_HOME			        115
# define KEY_END			        119
# define KEY_PAGE_UP		        116
# define KEY_PAGE_DOWN		        121
# define KEY_CLEAR			        71
# define KEY_PAD_1			        83
# define KEY_PAD_2			        84
# define KEY_PAD_3			        85
# define KEY_PAD_4			        86
# define KEY_PAD_5			        87
# define KEY_PAD_6			        88
# define KEY_PAD_7			        89
# define KEY_PAD_8			        91
# define KEY_PAD_9			        92
# define KEY_PAD_0			        82
# define KEY_PAD_EQUAL		        81
# define KEY_PAD_DIVIDE		        75
# define KEY_PAD_MULTIPLY	        67
# define KEY_PAD_SUB		        78
# define KEY_PAD_ADD		        69
# define KEY_PAD_ENTER		        76
# define KEY_PAD_DOT		        65
# define MOUSE_LEFT                 280
# define MOUSE_RIGHT                281
# define MOUSE_MID                  282
# define SCROLL_UP                  283
# define SCROLL_DOWN                284

# define KeyPress		            2
# define KeyRelease  		        3
# define ButtonPress	    	    4
# define ButtonRelease		        5
# define MotionNotify		        6
# define EnterNotify	    	    7
# define LeaveNotify	    	    8
# define FocusIn			        9
# define FocusOut	    	        10
# define KeymapNotify		        11
# define Expose			            12
# define GraphicsExpose		        13
# define NoExpose	    	        14
# define VisibilityNotify	        15
# define CreateNotify		        16
# define DestroyNotify		        17
# define UnmapNotify 		        18
# define MapNotify	    	        19
# define MapRequest  		        20
# define ReparentNotify		        21
# define ConfigureNotify		    22
# define ConfigureRequest	        23
# define GravityNotify		        24
# define ResizeRequest		        25
# define CirculateNotify	        26
# define CirculateRequest	        27
# define PropertyNotify		        28
# define SelectionClear		        29
# define SelectionRequest	        30
# define SelectionNotify	        31
# define ColormapNotify	        	32
# define ClientMessage	        	33
# define MappingNotify	        	34
# define LASTEvents		            35

# define NoEventMask			    0L
# define KeyPressMask		    	(1L<<0)  
# define KeyReleaseMask		    	(1L<<1)  
# define ButtonPressMask		    (1L<<2)  
# define ButtonReleaseMask	    	(1L<<3)  
# define EnterWindowMask		    (1L<<4)  
# define LeaveWindowMask		    (1L<<5)  
# define PointerMotionMask	    	(1L<<6)  
# define PointerMotionHintMask	    (1L<<7)  
# define Button1MotionMask	    	(1L<<8)  
# define Button2MotionMask	    	(1L<<9)  
# define Button3MotionMask	    	(1L<<10) 
# define Button4MotionMask	    	(1L<<11) 
# define Button5MotionMask	    	(1L<<12) 
# define ButtonMotionMask	    	(1L<<13) 
# define KeymapStateMask		    (1L<<14)
# define ExposureMask			    (1L<<15) 
# define VisibilityChangeMask    	(1L<<16) 
# define StructureNotifyMask	   	(1L<<17) 
# define ResizeRedirectMask		    (1L<<18) 
# define SubstructureNotifyMask	    (1L<<19) 
# define SubstructureRedirectMask   (1L<<20) 
# define FocusChangeMask			(1L<<21) 
# define PropertyChangeMask		    (1L<<22) 
# define ColormapChangeMask		    (1L<<23) 
# define OwnerGrabButtonMask		(1L<<24) 

typedef struct      keyboard_s
{
	uint64_t        regKey;
	int             regSize;
	uint8_t         *regID;
}                   keyboard_t;

typedef struct      mouse_s
{
	int             x;
	int             y;
	keyboard_t      *keyboard;
}                   mouse_t;

typedef struct      angle_s
{
	double          fTheta;
	double          fCos;
	double          fSin;
}                   angle_t;

typedef struct      vector2D_s
{
	double          x;
	double          y;
}                   vector2D_t;

typedef struct      mat2x2_s
{
	double          m[2][2];
}                   mat2x2_t;

typedef struct      entity_s
{
	vector2D_t      coord;
	vector2D_t      dir;
	angle_t         angle;
	vector2D_t      vel;
	vector2D_t      straf;
	double          fVeloCur;
	double          fVeloDef;
	uint8_t         anchor;
}                   entity_t;

typedef struct      camera_s
{
	vector2D_t      plane;
	entity_t        *entity;
	double          fSensi;
	double          fView_max;
}                   camera_t;

typedef struct		image_s
{
	void			*id;
	char		    *data;
	int				bpp;
	int				size_l;
	int				endian;
	int             width;
	int             heigh;
}					image_t;

typedef struct      window_s
{
	void            *id;
	void            *mlx_id;
	char            *title;
	int             width;
	int             heigh;
	uint8_t         menu;
	image_t         *img;
}                   window_t;

typedef struct      framework_s
{
	void            *id;
	window_t        *win;
	double          frame;
}                   framework_t;

typedef struct      wall_s
{
	image_t         *face[2];
}                   wall_t;

typedef struct      ray_s
{
	vector2D_t      origin;
	vector2D_t      dir;
	vector2D_t      sideDist;
	vector2D_t      wallTex;
	vector2D_t      dDist;
	double          wallProjDist;
	int             wallHeight;
	int             texID;
	int             wallSide;
	int             stepX;
	int             stepY;
	int             mapX;
	int             mapY;
	int             light;
}                   ray_t;

typedef struct      world_s
{
	vector2D_t      spawn;
	int             *data;
	int             width;
	int             heigh;
	char            *fileName;
}                   world_t;

typedef struct      engine_s
{
	framework_t     *mlx;
	keyboard_t      *keyboard;
	mouse_t         *mouse;
	entity_t        *player;
	entity_t        *IA;
	camera_t        *cam;
	world_t         *world;
	wall_t          **wallBuff;
	image_t         *texBuff[TEX_BUFF_S];
	int             wall_s;
	struct timeval  old;
	struct timeval  cur;
}                   engine_t;

/*------------------[   hook.c    ]---------------------*/
int                 mouse_motion_hook(int x, int y, mouse_t *mouse);
int                 mouse_press_hook(int key, int x, int y, mouse_t *mouse);
int                 mouse_release_hook(int key, int x, int y, mouse_t *mouse);
int                 key_press_hook(int key, keyboard_t *keyboard);
int                 key_release_hook(int key, keyboard_t *keyboard);
int                 destroy_window_hook(engine_t *engine);

/*------------------[   device.c   ]--------------------*/
void                mouse_destroy(mouse_t *mouse);
mouse_t             *new_mouse(keyboard_t *keyboard);
void                keyboard_destroy(keyboard_t *keyboard);
keyboard_t          *new_keyboard(int size);
int                 register_newKey(keyboard_t *keyboard, int key);

/*------------------[   entity.c   ]--------------------*/
void                entity_destroy(entity_t *e);
entity_t            *new_entity(double velDefault, uint8_t anchor);
void                entity_setLocation(entity_t *e, int x, int y);
void                entity_setOrientation(entity_t *e, double deg);
void                entity_tryMove(world_t *w ,entity_t *e);
void                entity_view(engine_t *engine);

/*------------------[   angle.c    ]--------------------*/
angle_t             *new_angle(double fTheta);
void                angle_destroy(angle_t *angle);
void                angle_reset(angle_t *angle, double fTheta);
double              angle_toDegree(vector2D_t *v);
void                angle_toRadian(vector2D_t *v, double deg);

/*------------------[   world.c     ]--------------------*/
world_t             *new_world(char *fileName);
void                world_destroy(world_t *w);
void                world_setSpawn(world_t *w, int x, int y);
int                 world_getObj(world_t *w, int x, int y);
world_t             *world_init(char *fileName);

/*------------------[   ray.c       ]--------------------*/
void                ray_cast(engine_t *e, camera_t *cam);

/*------------------[   misc.c      ]--------------------*/
void                debug_display(engine_t *e);

/*------------------[   engine.c    ]--------------------*/
engine_t            *new_engine(void);
void                engine_destroy(engine_t *e);

/*------------------[   vector.c    ]--------------------*/
void                mat2x2_setRotY(angle_t *t);
void                vector_vecProduct(vector2D_t *vDest, vector2D_t *vMult);
void                vector_rotY(vector2D_t *v);
void                vector_reset(vector2D_t *v);
void                vector_set(vector2D_t *v, double x, double y);

/*------------------[   event.c     ]--------------------*/
void                event_refresh(engine_t *engine, keyboard_t *keyboard, camera_t *cam);
void                event_docker(engine_t *engine, keyboard_t *k, camera_t *c);

/*------------------[   framework.c ]--------------------*/
void                window_destroy(window_t *win);
window_t            *new_window(void *mlx_id, int width, int heigh, char *title);
void                framework_destroy(framework_t *framework);
framework_t         *new_framework(void);

/*------------------[   image.c     ]--------------------*/
void                image_destroy(void *mlx, image_t *img);
image_t             *new_image(void *mlx, int width, int heigh);
void                image_clear(image_t *img);
void                image_pixelPut(image_t *img, int x, int y, int color);
int                 image_getPixel(image_t *img, int x, int y);
void                image_lineColorPut(image_t *img, int x, int y1, int y2, int color);

/*------------------[   texture.c   ]--------------------*/
image_t             *new_texture(void *mlx, char *fileName);
int                 texture_init(void *mlx, image_t **texBuff);
void                texture_uninit(void *mlx, image_t **texBuff);

/*------------------[   texture.c   ]--------------------*/
wall_t              *new_wall(image_t *f0, image_t *f1);

/*------------------[   wall.c      ]--------------------*/
wall_t              **wall_init(image_t **texBuff, int size);
wall_t              *new_wall(image_t *f0, image_t *f1);
void                wall_destroy(wall_t *wall);
void                wall_uninit(wall_t **wallBuf);

/*------------------[   parser.c    ]--------------------*/
int                 parser_getWorld(world_t *w);
int                 parser_getWorldSize(world_t *w);

/*------------------[   camera.c    ]--------------------*/
camera_t            *new_camera(double fSensi, double fov_2, double view);
void                camera_destroy(camera_t *c);
void                camera_dock(camera_t *c, entity_t *e);
void                camera_view(window_t *w, mouse_t *m, camera_t *c);

#endif