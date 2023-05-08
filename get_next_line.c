/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:18:29 by johernan          #+#    #+#             */
/*   Updated: 2023/03/14 15:18:32 by johernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
    
}
int main(void)
{
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);
    if (fd == -1)
        return NULL;
    else

}