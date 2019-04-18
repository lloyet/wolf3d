/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:38:20 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/13 20:38:20 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../inc/wolf.h"

void                image_destroy(void *mlx, image_t *img)
{
    mlx_destroy_image(mlx, img->id);
    ft_memdel((void **)&img);
    return;
}

image_t             *new_image(void *mlx, int width, int heigh)
{
    image_t         *img;

    if (!(img = (image_t *)ft_memalloc(sizeof(image_t))))
        return (0);
    if (!(img->id = mlx_new_image(mlx, width, heigh)))
        return (0);
    img->width = width;
    img->heigh = heigh;
    img->data = mlx_get_data_addr(img->id, &img->bpp, &img->size_l, &img->endian);
    img->bpp /= 8;
    return (img);
}

void                image_clear(image_t *img)
{
    ft_bzero(img->data, img->width * img->heigh * img->bpp);
    return;
}

void                image_pixelPut(image_t *img, int x, int y, int color)
{
    if (!img->id || x < 0 || y < 0 || x >= img->width || y >= img->heigh)
        return;
    *(int *)(img->data + ((x + y * img->width) * img->bpp)) = color;
    return;
}

int                 image_getPixel(image_t *img, int x, int y)
{
    return (*(int*)(img->data + ((x + y * img->width) * img->bpp)));
}

void                image_lineColorPut(image_t *img, int x, int y1, int y2, int color)
{
    while (y1 < y2)
        image_pixelPut(img, x, y1++, color);
    return;
}