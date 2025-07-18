/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:46:07 by fpetit            #+#    #+#             */
/*   Updated: 2025/07/03 20:56:50 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# include "cub_bonus.h"

typedef enum e_dir
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}					t_dir;

typedef enum e_target
{
	WALL,
	BALL,
	CUP
}					t_target;

typedef enum e_goal
{
	GOAL_LEFT = 4,
	GOAL_CENTER = 5,
	GOAL_RIGHT = 6,
	CENTER_WAIT = 7,
	LEFT_FAIL = 8,
	CENTER_FAIL = 9,
	RIGHT_FAIL = 10,
	LEFT_CATCH = 11,
	CENTER_CATCH = 12,
	RIGHT_CATCH = 13,
	RIGHT_PASS_1 = 14,
	RIGHT_PASS_2 = 15,
	RIGHT_PASS_3 = 16,
	RIGHT_PASS_4 = 17,
	RIGHT_PASS_5 = 18,
	LEFT_PASS_1 = 19,
	LEFT_PASS_2 = 20,
	LEFT_PASS_3 = 21,
	LEFT_PASS_4 = 22,
	LEFT_PASS_5 = 23,
	NONE = 24
}					t_goal_tex;

typedef enum e_wall
{
	WEST_HIT = 25,
	EAST_HIT = 26,
	TROPHY = 27
}					t_wall_tex;

typedef struct s_point
{
	// int				x;
	// int				y;
	double			xd;
	double			yd;
	double			magnitude;
}					t_vec;

typedef struct s_color
{
	int				value;
	int				r;
	int				g;
	int				b;
}	t_color;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				*int_addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	t_vec			*location;
}					t_img;

typedef struct s_map
{
	int				width;
	int				heigth;
	int				nb_elems;
	char			*elems;
	unsigned int	ceiling_color;
	unsigned int	floor_color;
	bool			has_ceiling;
	bool			has_floor;
	char			**paths;
	int				fd;
	bool			is_started;
	bool			is_ended;
	char			*codes[4];
	char			player_orientation;
	int				player_pos;
	int				opened_door_index;
}					t_parsed_map;

typedef struct s_goal
{
	t_goal_tex		position;
	bool			results[5];
	char			*songs[6];
	int				current_song;
	int				songpid;
	int				effectpid;
	int				shootcount;
	bool			can_see_ball;
	bool			can_see_goal;
	bool			has_fail;
	bool			has_shot;
	bool			can_shoot;
	bool			ended;
	int				score;
	bool			win;
	int				anim_count;
	int				ball_anim_count;
	int				cup_anim_count;
	bool			is_soccer;
	int				**ballsprites;
	t_img			*ok;
	t_img			*ko;
}					t_goal;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;

typedef struct s_minimap
{
	int				max_pixels;
	double			tilesize;
	double			x_offset;
	double			y_offset;
	t_img			*map;
}					t_minimap;

typedef struct s_walls
{
	t_img			*img;
	float			ceiling_ratio;
}					t_walls;

typedef struct s_cam
{
	t_vec			*orig;
	t_vec			*plane;
	t_vec			*dir;
	double			angle;
}					t_cam;

typedef struct s_ray
{
	t_vec			*raydir;
	t_vec			*delta;
	t_vec			*current_cell;
	t_vec			*step_cell;
	t_vec			*side_dist;
	t_vec			*check_cell;
	int				prev_elem;
	double			wall_ratio;
	bool			has_hit;
	char			side;
	double			deg_from_dir;
	double			pro_dist;
	double			pro_height;
	int				hit_dir;
}					t_ray;

typedef struct s_sprite
{
	t_vec			*pos;
	char			elem;
	double			transform_y;
	double			transform_x;
	int				height;
	int				width;
	int				screenx;
	int				startx;
	int				endx;
	int				starty;
	int				endy;
	int				sprite_size;
	double			distance;
	int				uncutx;
	int				uncutxend;
	int				uncuty;
	int				uncutyend;
	int				drawstartx;
	int				drawendx;
	int				drawstarty;
	int				drawendy;
	int				**sprites;
	int				sprite_index;
	int				sprite_nb;
}	t_sprite;

typedef struct s_data
{
	t_mlx			*mlx;
	t_parsed_map	*parsed_map;
	t_minimap		*minimap;
	t_walls			*walls;
	t_goal			*goal;
	t_cam			*cam;
	t_ray			*ray;
	t_sprite		**balls;
	int				*sprite_order;
	double			*sprite_distance;
	double			*zbuffer;
	t_sprite		*cup;
	int				nb_ball;
	int				**tex;
	int				flag_frame;
	double			flag_wave_offset;
	int				ball_h;
	int				ball_w;
	t_vec			*ball_pos;
	t_vec			*player_pos;
	bool			rotates_left;
	bool			rotates_right;
	bool			move_forward;
	bool			move_backward;
	bool			move_left;
	bool			move_right;
	bool			show_help;
	bool			is_bonus;
	char			debug;
}					t_data;

typedef enum e_shape
{
	LINE,
	TRIANGLE_ISO,
	RECTANGLE,
	CIRCLE
}					t_shapetype;

typedef struct s_shape
{
	t_shapetype		type;
	t_img			*img;
	t_vec			*start;
	double			angle;
	double			width;
	double			heigth;
	unsigned int	color;
}					t_shape;

typedef struct s_map_state
{
	bool			map_started;
	bool			map_ended;
	int				y;
}					t_map_state;

#endif