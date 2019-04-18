/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   texture.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/14 20:51:53 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/14 20:51:53 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../inc/wolf.h"

image_t                 *new_texture(void *mlx, char *fileName)
{
    image_t             *tex;

    if (!(tex = (image_t*)ft_memalloc(sizeof(image_t))))
        return (0);
    if (!(tex->id = mlx_xpm_file_to_image(mlx, fileName, &tex->width, &tex->heigh)))
        return (0);
    tex->data = mlx_get_data_addr(tex->id, &tex->bpp, &tex->size_l, &tex->endian);
    tex->bpp /= 8;
    return (tex);
}

void                    texture_uninit(void *mlx, image_t **texBuff)
{
    image_destroy(mlx, texBuff[0]);
    image_destroy(mlx, texBuff[1]);
    image_destroy(mlx, texBuff[2]);
    image_destroy(mlx, texBuff[3]);
    free(&texBuff);
    return ;
}

int                     texture_init(void *mlx, image_t **texBuff)
{
    if (!(texBuff[0] = new_texture(mlx, "tex/wood.xpm")))
        return (0);
    if (!(texBuff[1] = new_texture(mlx, "tex/brick.xpm")))
        return (0);
    if (!(texBuff[2] = new_texture(mlx, "tex/stone.xpm")))
        return (0);
    if (!(texBuff[3] = new_texture(mlx, "tex/redbrick.xpm")))
        return (0);
    if (!(texBuff[4] = new_texture(mlx, "tex/sky.xpm")))
        return (0);
    return (1);
}

