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

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char remaining_data[10];
    static size_t remaining_data_size = 0;
    char *line = NULL;
    char buffer[6];
    size_t bytes_read = 0;

    // Implementación de la función
    if (remaining_data_size > 0)
    {
    // Copiar los datos pendientes al comienzo del buffer
    // y actualizar la cantidad de datos restantes
    }
    bytes_read = read(fd, buffer, 10);
    if (bytes_read == 0)
    {
        free(line);
        return NULL;
    }

    if (bytes_read == -1)
    {
        free(line);
        return NULL;
    }
    char *end_of_line = NULL;
    end_of_line = strchr(buffer, '\n');

    if (end_of_line != NULL)
    {
        // Calcular la longitud de la línea
        // Reservar memoria suficiente
        // Copiar la línea
        // Actualizar los datos pendientes
    }
    
    else
    {
        // Copiar los datos restantes al final del buffer
        // Actualizar la cantidad de datos restantes
    }
    return line;
}
int main(void)
{
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("%s\n", line);
        free(line);
    }

    return 0;

}