/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <nisauvig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:03:32 by nisauvig          #+#    #+#             */
/*   Updated: 2021/03/15 15:03:40 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		load_texture(t_char *player)
{
	if (!(load_north(player)))
		return (BAD_OUT);
	if (!(load_south(player)))
		return (BAD_OUT);
	if (!(load_east(player)))
		return (BAD_OUT);
	if (!(load_west(player)))
		return (BAD_OUT);
	if (!(load_sprite(player)))
		return (BAD_OUT);
	return (GOOD_OUT);
}

void	bmp_fheader(void *bmp, t_map *map)
{
	char	*bm;
	int		*header;

	bm = bmp;
	ft_strcpy(bm, "BM");
	header = (int *)(bm + sizeof(char) * 2);
	header[0] = (55 + (map->win[0] * map->win[1] * 4));
	header[2] = 55;
}

void	bmp_info_header(void *bmp, t_map *map)
{
	char	*bm;
	int		*header;

	bm = (char *)(bmp + sizeof(char) * 14);
	bm[14] = (unsigned char)(24);
	header = (int *)(bm);
	header[0] = 40;
	header[1] = map->win[0];
	header[2] = map->win[1];
}

void	img_to_bmp(void *bmp, t_char *player)
{
	int		i;
	int		j;
	int		tmp;
	char	*head;

	tmp = 0;
	j = player->file->win[0] * (player->file->win[1] - 1);
	head = (bmp + (int)(54));
	while (j >= 0)
	{
		i = 0;
		while (i < player->file->win[0])
		{
			head[tmp] = 0;
			head[tmp++] = (char)(player->image.tab[i + j] / (256 * 256));
			head[tmp++] = (char)(player->image.tab[i + j] % 256);
			head[tmp++] = (char)(player->image.tab[i + j] / 256) % 256;
			i++;
		}
		j -= player->file->win[0];
	}
}

void	img_bmp(t_char *player)
{
	int		fd;
	int		size;
	char	*bmp;

	player->save = 0;
	size = (55 + (player->file->win[0] * player->file->win[1] * 3));
	if ((fd = open("./save.bmp", O_CREAT | O_RDWR, 0666)) < 2)
		return ((void)error_flag("Unable to create file save.bmp.\n"));
	if (!(bmp = malloc(sizeof(char) * size)))
		return ((void)error_flag("Malloc error.\n"));
	bzero(bmp, sizeof(char) * size);
	bmp_fheader(bmp, player->file);
	bmp_info_header(bmp, player->file);
	img_to_bmp(bmp, player);
	write(fd, bmp, size);
	close(fd);
	free(bmp);
}
