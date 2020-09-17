#include "cub3D.h"

int		load_sprite(t_char *player)
{
	char	*path;

	if (!(path = ft_strdup((char *)player->file->sp_path.tex)))
		return (error_flag("Texture malloc error.\n"));
	free(player->file->sp_path.tex);
	player->file->sp_path.tex = NULL;
	if (!(player->file->sp_path.tex = mlx_xpm_file_to_image(player->mlx, path,
				&player->file->sp_path.width, &player->file->sp_path.height)))
		return (error_flag("Texture open error.\n"));
	free(path);
	return (GOOD_OUT);
}

int		load_west(t_char *player)
{
	char	*path;

	if (!(path = ft_strdup((char *)player->file->we_path.tex)))
		return (error_flag("Texture malloc error.\n"));
	free(player->file->we_path.tex);
	player->file->we_path.tex = NULL;
	if (!(player->file->we_path.tex = mlx_xpm_file_to_image(player->mlx, path,
				&player->file->we_path.width, &player->file->we_path.height)))
		return (error_flag("Texture open error.\n"));
	free(path);
	return (GOOD_OUT);
}

int		load_east(t_char *player)
{
	char	*path;

	if (!(path = ft_strdup((char *)player->file->ea_path.tex)))
		return (error_flag("Texture malloc error.\n"));
	free(player->file->ea_path.tex);
	player->file->ea_path.tex = NULL;
	if (!(player->file->ea_path.tex = mlx_xpm_file_to_image(player->mlx, path,
				&player->file->ea_path.width, &player->file->ea_path.height)))
		return (error_flag("Texture open error.\n"));
	free(path);
	return (GOOD_OUT);
}

int		load_north(t_char *player)
{
	char	*path;

	if (!(path = ft_strdup((char *)player->file->n_path.tex)))
		return (error_flag("Texture malloc error.\n"));
	free(player->file->n_path.tex);
	player->file->n_path.tex = NULL;
	if (!(player->file->n_path.tex = mlx_xpm_file_to_image(player->mlx, path,
				&player->file->n_path.width, &player->file->n_path.height)))
		return (error_flag("Texture open error.\n"));
	free(path);
	return (GOOD_OUT);
}

int		load_south(t_char *player)
{
	char	*path;

	if (!(path = ft_strdup((char *)player->file->so_path.tex)))
		return (error_flag("Texture malloc error.\n"));
	free(player->file->so_path.tex);
	player->file->so_path.tex = NULL;
	if (!(player->file->so_path.tex = mlx_xpm_file_to_image(player->mlx, path,
				&player->file->so_path.width, &player->file->so_path.height)))
		return (error_flag("Texture open error.\n"));
	free(path);
	return (GOOD_OUT);
}
