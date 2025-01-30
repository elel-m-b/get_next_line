/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:48:36 by elel-m-b          #+#    #+#             */
/*   Updated: 2024/11/17 13:17:59 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char	*buf, char	**reminder)
{
	char	*tmp;
	int		byte_read;

	byte_read = 1;
	while (byte_read)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
			break ;
		else if (byte_read == 0)
			break ;
		buf[byte_read] = '\0';
		if (!*reminder)
			*reminder = ft_strdup("");
		tmp = *reminder;
		*reminder = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (find_line(buf, '\n'))
			break ;
	}
	return (*reminder);
}

char	*extract_line(char	*line)
{
	char	*reminder;
	int		count;

	count = 0;
	while (line[count] != '\0' && line[count] != '\n')
		count++;
	if (line[count] == '\0')
		return (0);
	reminder = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (reminder[0] == '\0')
	{
		free(reminder);
		reminder = NULL;
	}
	line[count + 1] = '\0';
	return (reminder);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*reminder[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_line(fd, buf, &reminder[fd]);
	free(buf);
	if (!line)
		return (NULL);
	reminder[fd] = extract_line(line);
	return (line);
}
/*
#include <stdio.h>
int main(int ac, char **av)
{
    int fd;
    // int i;
    // i = 1;
	if (ac < 2)
        return 0;
    fd = open(av[1], O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL) 
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
}*/
