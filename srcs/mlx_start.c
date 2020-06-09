/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 23:39:37 by nisauvig          #+#    #+#             */
/*   Updated: 2020/05/24 23:51:13 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		mlx_start(t_map *file)
{
	void	*mlx;
	void	*win;

	if (!(mlx = mlx_init()))
		return (error_flag("MLX error : funct. init doesn't work.\n"));
	if (!(win = mlx_new_window(mlx, file->win[0], file->win[1], "cub3D")))
		return (error_flag("MLX error : funct. new_window doesn't work.\n"));
	while(1)
		;
	return (GOOD_OUT);
}
