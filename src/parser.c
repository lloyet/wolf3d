/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 20:39:28 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 20:43:03 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../inc/wolf.h"

int                 parser_getWorld(world_t *w)
{
    char            *str;
    char            *str_;
    int             fd;
    int             i;
    int             j;

    if ((fd = open(w->fileName, O_RDONLY)) < 0)
        return (0);
    i = 0;
    while (get_next_line(fd, &str) > 0)
    {
        str_ = str;
        j = 0;
        while (*str_)
        {
            if (*str_ > '/' && *str_ < ':')
                w->data[i * w->width + j++] = *str_ - '0';
            else if (*str_ == 'X')
                world_setSpawn(w, i - 0.5, j++ - 0.5);
            str_++;
        }
        i++;
        free(str);
    }
    return (1);
}

/*SIZE = LINE*COL*/
int                 parser_getWorldSize(world_t *w)
{
    int             fd;
    int             oldL;
    int             l;
    char            *str;
    char            *str_;

    if ((fd = open(w->fileName, O_RDONLY)) < 0)
        return (0);
    l = 0;
    w->width = 0;
    w->heigh = 0;
    while (get_next_line(fd, &str) > 0)
    {
        oldL = l;
        l = 0;
        str_ = str;
        while (*str_)
        {
            if (*str_ > '/' && *str_ < ':')
                l++;
            str_++;
        }
        if (oldL != w->width)
            return (-1);
        w->width = l;
        w->heigh++;
        free(str);
    }
    return (1);
}