/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:47:42 by fpetit            #+#    #+#             */
/*   Updated: 2025/05/21 17:47:45 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	debug_ray(t_ray *ray)
{
	printf("\n\n====RAY\n");
	if (ray->current_cell)
	{
		ft_put_pink("current cell: ");
		printf("x %d y %d\n", ray->current_cell->x, ray->current_cell->y);
	}
	if (ray->raydir)
	{
		ft_put_pink("ray dir: ");
		printf("x %f y %f\n", ray->raydir->xd, ray->raydir->yd);
	}
	if (ray->delta)
	{
		ft_put_pink("delta: ");
		printf("x %f y %f\n", ray->delta->xd, ray->delta->yd);
	}
	if (ray->side_dist)
	{
		ft_put_pink("side dist: ");
		printf("x %f y %f\n", ray->side_dist->xd, ray->side_dist->yd);
	}
}

void	debug_data(t_data *data)
{
	ft_put_pink("dir\n");
	printf("x %f\ny %f\n", data->cam->dir->xd, data->cam->dir->yd);
	ft_put_pink("pos\n");
	printf("x %f\ny %f\n", data->player_pos->xd, data->player_pos->yd);
}

void	debug_elems(t_parsed_map *map, char *elems)
{
	int	y;

	y = 0;
	while (elems && y < map->heigth)
	{
		write(1, elems, map->width);
		printf("\n");
		elems += map->width;
		y++;
	}
}
