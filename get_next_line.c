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

char *ft_read(int fd, char *remaining_data)
{
    int bytes_read = 0;
    char buffer[BUFFER_SIZE + 1];
    char    *tmp_free;
    
    if(!remaining_data)
        remaining_data = ft_strdup("");
    if (remaining_data == NULL)
        return NULL;
    while(ft_strchr(remaining_data, '\n') == NULL)
    {   
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == 0) //Fin del archivo
            break;
        if (bytes_read == -1) // Error de lectura
        {
            free(remaining_data);
            return NULL;
        }
        buffer[bytes_read] = 0;
        tmp_free = remaining_data;
        remaining_data = ft_strjoin(remaining_data, buffer);
        free(tmp_free);
    }
    if (ft_strlen(remaining_data) == 0) // Archivo vacío
    {
        free(remaining_data);
        return NULL;
    }
    return (remaining_data);
}

char *get_next_line(int fd)
{
    static char *remaining_data;
    char *line;
    int cont;
    int cont2;
    cont2 = 0;
    cont = 0;
    
    remaining_data = ft_read(fd, remaining_data);
    if (remaining_data == NULL)
        return NULL;
    if (ft_strlen(remaining_data) == 0)
    {
        free(remaining_data);
        remaining_data = NULL;
        return NULL;
    }
    while(remaining_data[cont] != '\n' && remaining_data[cont] != '\0')
        cont++;
    line = ft_substr(remaining_data, 0, cont + 1);
    if (line == NULL)
    {
        free(remaining_data);
        return NULL;
    }
    while(remaining_data[cont + cont2] != '\n' && remaining_data[cont + cont2] != '\0')
        cont2++;
    remaining_data = ft_substr(remaining_data, cont + 1, cont2);
    // free(remaining_data);
    // remaining_data = NULL;
    return line;
}
// int main(void)
// {
//     int fd;
//     char *line;
//     int i;
//     i = 0;

//     // atexit(system("leaks -q gnl"));
//     fd = open("text.txt", O_RDONLY);
//     if (fd == -1 || BUFFER_SIZE <= 0)
//     {
//         printf("Error al abrir el archivo.\n");
//         return 1;
//     }
//     while (i < 10 && line != NULL)
//     {
//         line = get_next_line(fd);
//         // if (line == NULL || ft_strlen(line) == 0) // Verificar si la línea es NULL o vacía
//         // {
//         //     free(line);
//         //     break;
//         // }
//         printf("%s", line);
//         free(line);
//         i++;
//     }
//     close(fd);
//     return 0;
// }