/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:49:53 by ytabia            #+#    #+#             */
/*   Updated: 2024/11/19 12:16:44 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#define FD_MAX 1024

static char	*ft_read_save(int fd, char *save)
{
	int		read_bytes;
	char	*buff;
	char	*tmp;

	buff = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buff), free(save), NULL);
		if (read_bytes == 0)
			break ;
		buff[read_bytes] = '\0';
		tmp = save;
		save = ft_strjoin(save, buff);
		free(tmp);
	}
	if (read_bytes == 0 && (!save || *save == '\0'))
		return (free(buff), free(save), NULL);
	free(buff);
	return (save);
}

static char	*ft_get_the_line(char *save)
{
	int		i;
	char	*s;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_update_save(char *save)
{
	char	*s;
	int		i;
	int		j;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(save) - i) + 1);
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		s[j++] = save[i++];
	s[j] = '\0';
	free(save);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*save[FD_MAX];
	char		*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE < 0)
		return (NULL);
	save[fd] = ft_read_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_get_the_line(save[fd]);
	save[fd] = ft_update_save(save[fd]);
	return (line);
}

//#include <stdio.h>

// int	main(void)
// {
// 	int fd1 = open("test.txt", O_RDONLY);

// 	int fd2 = open("test2.txt", O_RDONLY);
// 	int fd3 = open("test3.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// //	printf("%d", fd);
// 	printf("%s", get_next_line(fd3));
// 	printf("%s", get_next_line(fd1));
// //	printf("%d", );
// 	printf("%s", get_next_line(fd2));
// //	printf("%d", fd);
// 	printf("%s", get_next_line(fd3));

// 	printf("fd1 -> %d\n", fd1);
// 	printf("fd2 -> %d\n", fd2);
// 	printf("fd3 -> %d\n", fd3);
// }
