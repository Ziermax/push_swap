/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:39:49 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/29 17:26:11 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*	Malloc join buffer for characters in line and append buffer
 *	Copy chars to join and append '\0'
 *	return join - Free line buffer
 *	if malloc fails
 *	 return NULL - Free line buffer
 *	*/
char	*ultra_join(char *line, char *read, int to_append)
{
	char	*join;
	int		len;
	int		i;

	len = 0;
	if (line)
	{
		while (line[len])
			len++;
	}
	join = malloc(sizeof(char) * (len + to_append + 1));
	if (!join)
		return (free(line), NULL);
	i = -1;
	while (++i < len)
		join[i] = line[i];
	i = -1;
	while (++i < to_append)
		join[len + i] = read[i];
	join[len + i] = '\0';
	return (free(line), join);
}

/*	Search in line buffer for '\n'
 *	return 1 if found
 *	return 0 if not
 *	*/
int	new_line_info(char	*line)
{
	if (!line)
		return (0);
	while (*line)
	{
		if (*line == '\n')
			return (1);
		line++;
	}
	return (0);
}

/*	Read 5 bytes of file descriptor if no '\n' in line buffer
 *	Append bytes read to line
 *	return line
 *	if malloc or read fails
 *	 return NULL - Set info integer to FAILED
 *	*/
char	*read_stdin(char *line, int fd, int *info)
{
	char	lecture[5];
	int		rd;

	*info = 0;
	if (new_line_info(line))
		return (line);
	rd = read(fd, lecture, 5);
	if (rd < 0)
		return (free(line), *info = FAILED, NULL);
	if (rd == 0)
		return (line);
	line = ultra_join(line, lecture, rd);
	if (!line)
		return (*info = FAILED, NULL);
	return (line);
}

/*	Malloc buffer clean with size of bytes after '\n' in line
 *	Fill buffer with bytes after '\n'
 *	return clean - free line buffer
 *	if malloc fails or no bytes after '\n'
 *	 return NULL - free line buffer
 *	*/
char	*clean_line(char *line)
{
	char	*clean;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	while (line[i + len])
		len++;
	if (len == 0)
		return (free(line), NULL);
	clean = malloc(sizeof(char) * (len + 1));
	if (!clean)
		return (free(line), NULL);
	len = -1;
	while (line[i + ++len])
		clean[len] = line[i + len];
	clean[len] = '\0';
	return (free(line), clean);
}

/*	Read from stdin in line
 *	Execute movement in line
 *	Repite untill no more bytes in stdin
 *	if malloc fails or wrong format in line
 *	 return - Free stacks
 *	*/
void	execute_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		read_info;

	line = NULL;
	while (1)
	{
		line = read_stdin(line, 0, &read_info);
		if (!line)
			break ;
		interpretate_moves(line, stack_a, stack_b);
		if (!*stack_a && !*stack_b)
			return (free(line));
		line = clean_line(line);
	}
	if (read_info == FAILED)
		return (free_stack(stack_a), free_stack(stack_b));
}
