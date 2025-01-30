/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:06:40 by elel-m-b          #+#    #+#             */
/*   Updated: 2024/11/17 09:57:31 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buf, char *reminder)
{
	char		*tmp;
	int			read_byte;

	read_byte = 1;
	while (read_byte)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == 0)
			break ;
		else if (read_byte == -1)
			return (0);
		buf[read_byte] = '\0';
		if (!reminder)
			reminder = ft_strdup("");
		tmp = reminder;
		reminder = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (find_line(buf, '\n'))
			break ;
	}
	return (reminder);
}

char	*remove_line(char	*line)
{
	char	*reminder;
	int		count;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0')
		return (0);
	reminder = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*reminder == '\0')
	{
		free(reminder);
		reminder = NULL;
	}
	line[count + 1] = '\0';
	return (reminder);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_line(fd, buf, reminder);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	reminder = remove_line(line);
	return (line);
}
// int main(void)
// {
//     char *line;
//     int fd = open("file.txt", O_RDONLY);
//     //printf("%s", line);
//  line = get_next_line(fd);
//     while (line)
//     {
//         printf("%s", line);
//         free(line);
//         line = get_next_line(fd);  // 9ra l-line jdida
//     }
//     close(fd);
// }
