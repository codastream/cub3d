/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:34:24 by alaualik          #+#    #+#             */
/*   Updated: 2025/06/28 16:30:24 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	check_left_tex(t_data *data, int **keeper_tex)
{
	int	anim_inc;

	if (data->goal->position == GOAL_LEFT
		&& data->goal->has_fail == false)
		*keeper_tex = data->tex[LEFT_FAIL];
	else if (data->goal->position == GOAL_LEFT
		&& data->goal->has_fail == true)
		*keeper_tex = data->tex[LEFT_CATCH];
	else if (data->goal->position == GOAL_RIGHT && !data->goal->has_fail)
	{
		anim_inc = data->goal->anim_count / 10 + LEFT_PASS_1;
		*keeper_tex = data->tex[anim_inc];
	}
	else if (data->goal->win)
	{
		*keeper_tex = data->tex[EAST_HIT];
	}
}

void	check_right_tex(t_data *data, int **keeper_tex)
{
	int	anim_inc;

	if (data->goal->position == GOAL_RIGHT
		&& data->goal->has_fail == false)
		*keeper_tex = data->tex[RIGHT_FAIL];
	else if (data->goal->position == GOAL_RIGHT
		&& data->goal->has_fail == true)
		*keeper_tex = data->tex[RIGHT_CATCH];
	else if (data->goal->position == GOAL_LEFT && !data->goal->has_fail)
	{
		anim_inc = data->goal->anim_count / 10 + RIGHT_PASS_1;
		*keeper_tex = data->tex[anim_inc];
	}
	else if (data->goal->win)
	{
		*keeper_tex = data->tex[WEST_HIT];
	}
}

int	*select_keeper_tex(t_data *data, t_ray *ray)
{
	int	*keeper_tex;

	keeper_tex = NULL;
	if (ray->hit_dir == GOAL_CENTER && data->goal->position == GOAL_CENTER
		&& !data->goal->has_fail && !data->goal->win)
		keeper_tex = data->tex[CENTER_WAIT];
	else if (ray->hit_dir == GOAL_CENTER && data->goal->win)
		keeper_tex = data->tex[TROPHY];
	else if (ray->hit_dir == GOAL_LEFT)
		check_left_tex(data, &keeper_tex);
	else if (ray->hit_dir == GOAL_RIGHT)
		check_right_tex(data, &keeper_tex);
	else
		keeper_tex = NULL;
	return (keeper_tex);
}

int	cub_merge_goal_col(t_data *data, t_ray *ray, double pos, double texture_x)
{
	int	*keeper_tex;
	int	color;
	int	index;

	index = (int)(TEXTURE_SIZE * ((int)pos & (TEXTURE_SIZE - 1)))
		+ (int)texture_x;
	keeper_tex = select_keeper_tex(data, ray);
	if (keeper_tex && keeper_tex[index] != INVISIBLE)
		color = keeper_tex[index];
	else
		color = data->tex[ray->hit_dir][index];
	return (color);
}

void	cub_update_goal_anim(t_data *data)
{
	if (data->goal->ended)
		return ;
	if (!data->goal->ended)
		data->goal->ball_anim_count++;
	if (data->goal->ball_anim_count >= 50)
		data->goal->ball_anim_count = 0;
	if (data->goal->has_shot)
		data->goal->anim_count++;
	if (data->goal->anim_count >= 50)
	{
		data->goal->anim_count = 0;
		data->goal->has_shot = false;
		data->goal->position = GOAL_CENTER;
		data->goal->has_fail = false;
	}
}
