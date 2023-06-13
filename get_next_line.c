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
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;

    bytes_read = 0;
    if(remaining_data == NULL) //Cuando esta vacio remaining, le metemos un caracter vacio
        remaining_data = ft_strdup("");
    while(ft_strchr(remaining_data, '\n') == NULL) //hasta que no encuentre \n
    {  
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if(bytes_read == -1) //fallo de lectura
        {
            free(remaining_data);
            return (NULL);
        }

        if(bytes_read == 0) //Ha leido todo el archivo
            break;
        buffer[bytes_read] = 0;
        remaining_data = ft_strjoin(remaining_data, buffer); //guardamos y unimos
    }
    return remaining_data;

}

// char ft_get_line()
// {

// }
char *ft_clean_line(char *remaining_data)
{
    int i;
    int cont;
    char *new_line;

    cont = 0;
    i = 0;
    
    while(remaining_data[i] != '\n' && remaining_data[i] != '\0') //calculamos la longitud de la primera linea
        i++;
    new_line = ft_substr(remaining_data, i + 1, ft_strlen(remaining_data) - i);
    return new_line;
}

char *get_next_line(int fd)
{
    static char *remaining_data;
    char *line;
    int cont;


    cont = 0;
    remaining_data = ft_read(fd, remaining_data);
    if(remaining_data == NULL) //No se puedo abrir el archivo
        return NULL;
    while(remaining_data[cont] != '\n' && remaining_data[cont] != '\0') //calculamos la longitud de la primera linea
        cont++;
    line = ft_substr(remaining_data, 0, cont + 1);// copiamos de un string a otro una longitud(cont)
    remaining_data = ft_clean_line(remaining_data); // limpiamos la linea
    return (line);
}

// int main(void)
// {
//     int     fd;
//     char    *str;
//     int     i;
//     i = 0;
//     fd = open("text.txt", O_RDONLY);
//     while ((i <= 6))
//     {
//         str = get_next_line(fd);
//         printf("line %i=>%s\n", i + 1, str);
//         free(str);
//         i++;
//     }
//     printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
//     return (0);
// }