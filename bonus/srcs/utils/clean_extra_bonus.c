/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_extra_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:35:54 by alaualik          #+#    #+#             */
/*   Updated: 2025/07/03 21:03:09 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

/*
 * passing 0b1001 will free index 0 and 4
 */
void	cub_clean2d(void **array, int size, unsigned int bitmask, bool freeArr)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < size)
	{
		if ((bitmask & (1 << i)) != 0)
			free(array[i]);
		i++;
	}
	if (freeArr)
		free(array);
}

void	cub_clean_parsed(t_parsed_map *parsed)
{
	if (!parsed)
		return ;
	free(parsed->elems);
	if (parsed->paths)
	{
		free(parsed->paths[0]);
		free(parsed->paths[1]);
		free(parsed->paths[2]);
		free(parsed->paths[3]);
	}
	free(parsed->paths);
	free(parsed);
}

void	cub_clean_cam(t_cam *cam)
{
	if (!cam)
		return ;
	if (cam->dir)
		free(cam->dir);
	if (cam->plane)
		free(cam->plane);
	free(cam);
}

void	cub_clean_text(int **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < 28)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}

void	cub_clean_data(t_data *data)
{
	if (!data)
		return ;
	cub_clean_bonus(data);
	if (data->walls)
		cub_clean_field(data, data->walls);
	if (data->parsed_map)
		cub_clean_parsed(data->parsed_map);
	if (data->cam)
		cub_clean_cam(data->cam);
	if (data->player_pos)
		free(data->player_pos);
	if (data->ray)
		cub_clean_ray(data->ray);
	if (data->tex)
		cub_clean_text(data->tex);
	if (data->mlx)
		cub_clean_mlx(data->mlx);
	free(data);
}
