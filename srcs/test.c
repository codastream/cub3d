#include "test.h"

// Remplacement du NSWE par '0' dans la map après parsing
static void	replace_player_with_zero(t_parsed_map *map)
{
	if (map->elems && map->player_pos >= 0 && map->player_pos < map->nb_elems)
		map->elems[map->player_pos] = '0';
}

// Ne pas toucher cette fonction si tu utilises le parsing
// t_parsed_map	*cub_init_map(void)
// {
// 	t_parsed_map	*map;

// 	map = ft_calloc(1, sizeof(t_parsed_map));
// 	if (!map)
// 		return (NULL);
// 	char mapElems[] = {
// 		'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
// 			'1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
// 			'0', '0', '1', '1', '0', '1', '0', '0', '1', '0', '0', '0', '0',
// 			'0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0',
// 			'0', '0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '0', '1',
// 			'0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1',
// 			'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0',
// 			'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1',
// 			'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
// 			'0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
// 			'0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
// 			'1', '1', '1', '1', '1', '1',
// 	};
// 	map->elems = ft_calloc(150, sizeof(int));
// 	if (!map->elems)
// 		return (NULL);
// 	ft_memcpy(map->elems, mapElems, (150) * sizeof(int));
// 	map->heigth = 10;
// 	map->width = 15;
// 	map->nb_elems = 150;
// 	map->player_orientation = 'W';
// 	map->player_pos = 20;
// 	map->ceiling_color = BLUE;
// 	map->floor_color = YELLOW;
// 	map->ea_path = "textures/ik1.xpm";
// 	map->we_path = "textures/ik2.xpm";
// 	map->no_path = "textures/ik3.xpm";
// 	map->so_path = "textures/ik4.xpm";
// 	return (map);
// }

void	init_parsed_map(t_data *data)
{
	data->parsed_map = ft_calloc(1, sizeof(t_parsed_map));
	if (!data->parsed_map)
		cub_handle_fatal(data, MSG_ALLOC);
	data->parsed_map->paths = ft_calloc(4, sizeof(char *));
	if (!data->parsed_map->paths)
		cub_handle_fatal(data, MSG_ALLOC);
	data->parsed_map->has_ceiling = false;
	data->parsed_map->has_floor = false;
	data->parsed_map->heigth = 0;
	data->parsed_map->width = 0;
	data->parsed_map->nb_elems = 0;
}

// Nouvelle version : crée la structure et parse le .cub si besoin
t_data	*cub_init_data(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	if (ac == 3)
		data->debug = av[2][0];
	data->rotates_left = false;
	data->rotates_right = false;
	data->move_forward = false;
	data->move_backward = false;
	data->move_left = false;
	data->move_right = false;
	data->mlx = cub_init_mlx();
	if (!data->mlx)
		return (NULL);
	init_parsed_map(data);
	if (cub_parse_file(av[1], data))
		return (NULL);
	replace_player_with_zero(data->parsed_map);
	return (data);
}

bool	check_args(int ac, char **av, char **env)
{
	if (ac < 2 || (ac == 3 && (av[2][0] != '1' && av[2][0] != '2')))
	{
		ft_puterr(MSG_USAGE);
		return (false);
	}
	if (!env)
	{
		ft_puterr(MSG_EMPTY_ENV);
		return (false);
	}
	return (true);
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	if (check_args(ac, av, env) == false)
		return (EXIT_FAILURE);
	data = cub_init_data(ac, av);
	if (!data)
		return (EXIT_FAILURE);
	cub_init_graphics(data);
	cub_draw_ceiling_and_floor(data);
	cub_draw_minimap(data);
	cub_draw_player(data);
	cub_draw_walls(data);
	mlx_loop_hook(data->mlx->mlx, &cub_refresh, data);
	mlx_hook(data->mlx->win, KeyPress, KeyPressMask, &cub_handle_keypress, \
data);
	mlx_hook(data->mlx->win, KeyRelease, KeyReleaseMask, \
&cub_handle_keyrelease, data);
	mlx_hook(data->mlx->win, DestroyNotify, NoEventMask, &handle_click_on_close, (void *) data);
	mlx_hook(data->mlx->win, MotionNotify, PointerMotionMask, &handle_mouse_rotate, (void *) data);
	cub_cpy_with_transparency(data->walls->img, data->minimap->map, \
data->minimap->map->location->x, data->minimap->map->location->y);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
data->walls->img->img, 0, 0);
	mlx_loop(data->mlx->mlx);
	cub_clean_data(data);
	return (EXIT_SUCCESS);
}
