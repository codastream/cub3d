/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:46:44 by fpetit            #+#    #+#             */
/*   Updated: 2025/07/05 15:51:36 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	cub_is_valid_direction_codes(t_data *data, char *trim, char *line)
{
	char	*codes[4];
	int		i;

	cub_init_cardinal_codes(codes);
	i = 0;
	while (i < 4)
	{
		if (!ft_strncmp(trim, codes[i], 2) && (trim[2] == ' '
				|| trim[2] == '\t'))
		{
			cub_check_texture_path(data, i, line, trim);
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	cub_check_color_codes(t_data *data, char *trimmed, char *line)
{
	bool	has_matched;

	has_matched = false;
	if ((!ft_strncmp(trimmed, "F", 1) && (trimmed[1] == ' '
				|| trimmed[1] == '\t')) || (!ft_strncmp(trimmed, "C", 1)
			&& (trimmed[1] == ' ' || trimmed[1] == '\t')))
	{
		cub_add_ceiling_or_floor_color(data, trimmed, line, &has_matched);
	}
	return (has_matched);
}

void	cub_try_add_texture_paths_and_colors(t_data *data, char *line)
{
	char	*trimmed;
	bool	has_matched;

	trimmed = cub_trim_full(line);
	if (ft_isblankornlstr(trimmed))
		return ;
	has_matched = cub_is_valid_direction_codes(data, trimmed, line);
	if (!has_matched)
		has_matched = cub_check_color_codes(data, trimmed, line);
	if (!has_matched)
		cub_handle_fatal_parse(data, data->parsed_map->fd, line,
			MSP_IVL);
}
