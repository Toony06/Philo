/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:16:17 by toroman           #+#    #+#             */
/*   Updated: 2025/04/03 11:42:44 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

void	*free_all(char *stack, char *buffer)
{
	free(stack);
	free(buffer);
	return (NULL);
}

char	*fill_line_buffer(int fd, char *stack)
{
	int		i;
	char	*buffer;
	char	*tmp;

	if (!stack)
		stack = ft_strdup("");
	i = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (i != 0 && !ft_strchr(stack, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free_all(stack, buffer));
		buffer[i] = '\0';
		tmp = ft_strjoin(stack, buffer);
		free(stack);
		stack = tmp;
	}
	free(buffer);
	return (stack);
}

char	*next_line(char *stack)
{
	int		i;
	int		j;
	char	*new_stack;

	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (!stack[i])
	{
		free (stack);
		return (NULL);
	}
	new_stack = malloc(sizeof(char) * (ft_strlen(stack) - i + 1));
	i++;
	j = 0;
	while (stack[i])
	{
		new_stack[j] = stack[i];
		j++;
		i++;
	}
	free (stack);
	new_stack[j] = '\0';
	return (new_stack);
}

char	*before_line(char *stack)
{
	char	*str;
	int		i;

	i = 0;
	if (!stack)
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		str[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stack = fill_line_buffer(fd, stack);
	if (!stack)
		return (NULL);
	str = before_line(stack);
	stack = next_line(stack);
	if (str[0] == '\0')
	{
		free (stack);
		free (str);
		return (NULL);
	}
	return (str);
}

//int		main(int ac, char **av)
//{
//	(void) ac;
//	int		fd;

//	fd = open(av[1], O_RDONLY);
//	printf("str = %s", get_next_line(fd));
//	printf("str = %s", get_next_line(fd));
//	printf("str = %s", get_next_line(fd));
//	printf("str = %s", get_next_line(fd));
//}

//int main()
//{
//	int fd = open("get_next_line.c", O_RDONLY);
//	char 	*ligne;

//	while (1)
//	{
//		ligne = get_next_line(fd);
//		if(!ligne)
//			break;
//		printf("%s", ligne);
//	}
//	free (ligne);
//	return 0;
//}
