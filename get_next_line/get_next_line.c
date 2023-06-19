/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyki2 <jinhyki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:31:58 by jinhyki2          #+#    #+#             */
/*   Updated: 2023/05/01 14:22:22 by jinhyki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_update_backup(int fd, char *buffer, char *backup)
{
	ssize_t	bytes;
	char	*backup_to_free;

	bytes = 1;
	while ((ft_strchr(buffer, '\n') == 0) && (bytes != 0))
	{
		backup_to_free = backup;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(backup_to_free);
			return (0);
		}
		buffer[bytes] = '\0';
		backup = ft_strjoin(backup, buffer);
		if (backup != backup_to_free)
			free(backup_to_free);
		if (backup == 0)
			return (0);
	}
	return (backup);
}

static char	*ft_valcheck_and_update(int fd, char *buffer, char **backup)
{
	char		*backup_tmp;

	if (buffer == 0)
	{
		free (*backup);
		*backup = 0;
		return (0);
	}
	backup_tmp = *backup;
	backup_tmp = ft_update_backup(fd, buffer, backup_tmp);
	if (!(backup_tmp))
	{
		*backup = 0;
		return (0);
	}
	return (backup_tmp);
}

static char	*ft_create_ret_line(char *backup_tmp, char **backup)
{
	char		*ret_line;
	long long	index;
	size_t		len;

	len = ft_strlen_gnl(backup_tmp, '\n');
	ret_line = (char *)malloc(sizeof(char) * len + 2);
	if (!(ret_line))
	{
		free(backup_tmp);
		*backup = 0;
		return (0);
	}
	index = -1;
	while (++index < (long long)(len + 1))
		ret_line[index] = backup_tmp[index];
	ret_line[index] = '\0';
	*backup = ft_strdup_gnl(&(backup_tmp[index]));
	free(backup_tmp);
	if (*backup == 0)
	{
		free(ret_line);
		return (0);
	}
	return (ret_line);
}

static char	*ft_get_line(int fd, char *buffer)
{
	static char	*backup;
	char		*backup_tmp;
	char		*ret_line;

	backup_tmp = ft_valcheck_and_update(fd, buffer, &backup);
	if (!backup_tmp)
		return (0);
	if (!ft_strchr(backup_tmp, '\n'))
	{
		ret_line = ft_strdup_gnl(backup_tmp);
		free(backup_tmp);
		backup = 0;
		return (ret_line);
	}
	ret_line = ft_create_ret_line(backup_tmp, &backup);
	if (ret_line == 0)
		return (0);
	if (backup[0] == '\0')
	{
		free(backup);
		backup = 0;
	}
	return (ret_line);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line_to_print;
	size_t	index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!(buffer))
	{
		ft_get_line(fd, 0);
		return (0);
	}
	index = 0;
	while (index < (BUFFER_SIZE + 1))
		buffer[index++] = '\0';
	line_to_print = ft_get_line(fd, buffer);
	free(buffer);
	return (line_to_print);
}
