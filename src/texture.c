/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   texture.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/14 20:51:53 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 03:54:37 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

t_image					*new_texture(void *mlx, char *file_name)
{
	t_image				*tex;

	if (!(tex = (t_image*)ft_memalloc(sizeof(t_image))))
		return (0);
	if (!(tex->id = mlx_xpm_file_to_image(mlx, file_name, &tex->width,
					&tex->heigh)))
		return (0);
	tex->data = mlx_get_data_addr(tex->id, &tex->bpp, &tex->size_l,
			&tex->endian);
	tex->bpp /= 8;
	return (tex);
}

void					texture_uninit(void *mlx, t_image **tex_buff)
{
	image_destroy(mlx, tex_buff[0]);
	image_destroy(mlx, tex_buff[1]);
	image_destroy(mlx, tex_buff[2]);
	image_destroy(mlx, tex_buff[3]);
	free(&tex_buff);
	return ;
}

int						texture_init(void *mlx, t_image **tex_buff)
{
	if (!(tex_buff[0] = new_texture(mlx, "tex/wood.xpm")))
		return (0);
	if (!(tex_buff[1] = new_texture(mlx, "tex/brick.xpm")))
		return (0);
	if (!(tex_buff[2] = new_texture(mlx, "tex/stone.xpm")))
		return (0);
	if (!(tex_buff[3] = new_texture(mlx, "tex/redbrick.xpm")))
		return (0);
	if (!(tex_buff[4] = new_texture(mlx, "tex/sky.xpm")))
		return (0);
	return (1);
}
