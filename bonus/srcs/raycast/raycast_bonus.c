/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:35:44 by alaualik          #+#    #+#             */
/*   Updated: 2025/06/30 16:16:27 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	compute_increments(t_ray *ray, t_vec *player)
{
	if (ray->raydir->xd < 0)
	{
		ray->step_cell->xd = -1;
		ray->side_dist->xd = (player->xd - (double)ray->current_cell->xd)
			* ray->delta->xd;
	}
	else
	{
		ray->step_cell->xd = 1;
		ray->side_dist->xd = ((double)ray->current_cell->xd + 1.0 - player->xd)
			* ray->delta->xd;
	}
	if (ray->raydir->yd < 0)
	{
		ray->step_cell->yd = -1;
		ray->side_dist->yd = (player->yd - (double)ray->current_cell->yd)
			* ray->delta->yd;
	}
	else
	{
		ray->step_cell->yd = 1;
		ray->side_dist->yd = ((double)ray->current_cell->yd + 1.0 - player->yd)
			* ray->delta->yd;
	}
}

double	compute_dist(t_data *data, t_ray *ray, char side)
{
	double	dist;

	if (side == 'x')
	{
		dist = ((double)ray->current_cell->xd - data->player_pos->xd + (1
					- ray->step_cell->xd) / 2) / ray->raydir->xd;
		ray->wall_ratio = data->player_pos->yd + dist * ray->raydir->yd;
	}
	else
	{
		dist = ((double)ray->current_cell->yd - data->player_pos->yd + (1
					- ray->step_cell->yd) / 2) / ray->raydir->yd;
		ray->wall_ratio = data->player_pos->xd + dist * ray->raydir->xd;
	}
	ray->wall_ratio -= floor(ray->wall_ratio);
	return (dist);
}

double	cub_measure_dist_to_wall(t_data *data, t_vec *ray_dirvector)
{
	double	distance;

	distance = -1;
	reinit_ray(data, ray_dirvector);
	compute_increments(data->ray, data->player_pos);
	cub_iter_ray(data, data->ray);
	distance = compute_dist(data, data->ray, data->ray->side);
	return (distance);
}

int	get_direction(char side, t_vec *dir)
{
	if (side == 'x')
	{
		if (dir->xd < 0)
			return (WEST);
		else
			return (EAST);
	}
	else
	{
		if (dir->yd < 0)
			return (NORTH);
		else
			return (SOUTH);
	}
}
