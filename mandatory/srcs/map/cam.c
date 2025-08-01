/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:23:00 by alaualik          #+#    #+#             */
/*   Updated: 2025/06/28 15:29:03 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_update_plane_vector(t_data *data)
{
	t_vec	*vec;
	double	fov_rad;
	double	plane_len;

	fov_rad = ft_to_rad(FOV_DEGREES);
	plane_len = tan(fov_rad / 2.0);
	vec = cub_init_vec_double(-data->cam->dir->yd * plane_len,
			data->cam->dir->xd * plane_len);
	if (!vec)
		cub_handle_fatal(data, MSG_ALLOC);
	data->cam->plane = vec;
}

/*
 * as the origin is topleft, the vector will be positive for South and East
 */
void	cub_init_dir_vector(t_data *data)
{
	t_vec	*vec;

	vec = cub_init_vec_double(0, 0);
	if (data->parsed_map->player_orientation == E_NORTH)
		vec->yd = -1.0f;
	if (data->parsed_map->player_orientation == E_SOUTH)
		vec->yd = 1.0f;
	if (data->parsed_map->player_orientation == E_EAST)
		vec->xd = 1.0f;
	if (data->parsed_map->player_orientation == E_WEST)
		vec->xd = -1.0f;
	data->cam->dir = vec;
}

t_vec	*cub_get_player_position(t_parsed_map *map)
{
	int		x;
	int		y;
	t_vec	*pos;

	x = map->player_pos % map->width;
	y = map->player_pos / map->width;
	pos = cub_init_vec_double((double)x + 0.5, (double)y + 0.5);
	return (pos);
}

void	cub_init_cam(t_data *data)
{
	t_cam	*cam;

	cam = ft_calloc(1, sizeof(t_cam));
	if (!cam)
		cub_handle_fatal(data, "Error\n init cam\n");
	data->cam = cam;
	cub_init_dir_vector(data);
	cub_update_plane_vector(data);
	data->player_pos = cub_get_player_position(data->parsed_map);
	data->cam->orig = data->player_pos;
}
