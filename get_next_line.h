/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:24:23 by elel-m-b          #+#    #+#             */
/*   Updated: 2024/11/17 13:14:34 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 100

# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strlen(const char *str);
int		find_line(char *buf, char c);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t	len);
char	*ft_strdup(const char	*src);
char	*get_next_line(int fd);

#endif
