#include "test.h"

t_img	*cub_init_img(t_data *data, int width, int height, t_vec *location)
{
	t_img	*img;
	int		bpp;
	int		line_length;
	int		endian;

	if (!location)
		cub_handle_fatal(data, "no location for img\n");
	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(data->mlx->mlx, width, height);
	if (!img->img)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &bpp, &line_length, &endian);
	if (!img->addr)
	{
		cub_clean_img(data, img);
		return (NULL);
	}
	cub_update_img_info(img, bpp, line_length, endian);
	cub_update_img_coord(img, width, height, location);
	return (img);
}

t_mlx	*cub_init_mlx( void )
{
	t_mlx	*mlx;
	void	*mlxptr;
	void	*mlxwin;

	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlxptr = mlx_init();
	if (!mlxptr)
	{
		free(mlx);
		return (NULL);
	}
	mlx->mlx = mlxptr;
	mlxwin = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "Test");
	if (!mlxwin)
	{
		free(mlx);
		return (NULL);
	}
	mlx->win = mlxwin;
	return (mlx);
}

void	cub_clear_img(t_img *img)
{
	double	y;
	double	x;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			cub_put_pix_to_img(img, x, y, INVISIBLE);
			x++;
		}
		y++;
	}
}

int	cub_refresh(void *param)
{
	t_data	*data;

	data = (t_data *) param;
	cub_update_translation(data);
	cub_update_rotation(data);
	cub_clear_img(data->minimap->map);
	cub_clear_img(data->walls->img);
	cub_draw_ceiling_and_floor(data);
	cub_draw_walls(data);
	cub_draw_minimap(data);
	cub_draw_player(data);
	cub_cpy_with_transparency(data->walls->img, data->minimap->map, \
data->minimap->map->location->x, data->minimap->map->location->y);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
data->walls->img->img, 0, 0);
	return (EXIT_SUCCESS);
}
