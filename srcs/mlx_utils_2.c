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

void		bmp_fheader(void *bmp, t_map *map)
{
	char	*bm;
	int	*header;

	bm = bmp;
	ft_strcpy(bm, "BM");
	header = (int *)(bm + 2);
	header[0] = (55 + (map->win[0] * map->win[1] * 3));
	header[1] = 55;
}

void		img_to_bmp(void *bmp, t_char *player)
{
	int	i;
	int	tmp;
	int	*head;

	i = 0;
	tmp = 0;
	head = bmp + 55;
	while (i < player->file->win[0] * player->file->win[1])
	{
		tmp = (BLUE & player->image.tab[i]) << 3;
		tmp |= (GREEN & player->image.tab[i]) << 1;
		tmp |= (RED & player->image.tab[i]) >> 1;
		head[i] = tmp;
		i++;
	}
}

void		bmp_info_header(void *bmp, t_map *map)
{
	char	*bm;
	int	*header;

	bm = (char *)(bmp + 14);
	bm[14] = (unsigned char)(24);
	header = (int *)(bm);
	header[0] = 40;
	header[1] = map->win[0];
	header[2] = map->win[1];
	
}

void		img_bmp(t_char *player)
{
	int	fd;
	char	*bmp;

	player->save = 0;
	if ((fd = open("./save.bmp", O_CREAT | O_RDWR, 0666)) < 2)
		return ((void)error_flag("Unable to create file save.bmp.\n"));
	if (!(bmp = malloc(sizeof(char) * (55 + (player->file->win[0] * player->file->win[1] * 4)))))
		return ((void)error_flag("Malloc error.\n"));
	bzero(bmp, sizeof(char) * (55 + (player->file->win[0] * player->file->win[1] * 3)));
	bmp_fheader(bmp, player->file);
	bmp_info_header(bmp, player->file);
	img_to_bmp(bmp, player);
	printf("bmp = [%s]\n", bmp);
	ft_putstr_fd(bmp, fd);
	close(fd);
	free(bmp);
}
	//bmp_fheader = "BM??00??";//?? n1 = file size(see malloc)(4o), ?? n2 = BMP offset 55(4o)
	//bmp_inheader = 40, width(0), height(1), (2o)0, (2o)24(BitsPerPix), 0, 0, 0, 0, 0, 0;
