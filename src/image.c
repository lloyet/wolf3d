/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:38:20 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 03:54:37 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

void				image_destroy(void *mlx, t_image *img)
{
	mlx_destroy_image(mlx, img->id);
	ft_memdel((void **)&img);
	return ;
}

t_image				*new_image(void *mlx, int width, int heigh)
{
	t_image			*img;

	if (!(img = (t_image *)ft_memalloc(sizeof(t_image))))
		return (0);
	if (!(img->id = mlx_new_image(mlx, width, heigh)))
		return (0);
	img->width = width;
	img->heigh = heigh;
	img->data =
		mlx_get_data_addr(img->id, &img->bpp, &img->size_l, &img->endian);
	img->bpp /= 8;
	return (img);
}

void				image_clear(t_image *img)
{
	ft_bzero(img->data, img->width * img->heigh * img->bpp);
	return ;
}

void				image_pixel_put(t_image *img, int x, int y, int color)
{
	*(int *)(img->data + ((x + y * img->width) * img->bpp)) = color;
	return ;
}

int					image_get_pixel(t_image *img, int x, int y)
{
	return (*(int*)(img->data + ((x + y * img->width) * img->bpp)));
}
