/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:20:20 by maricard          #+#    #+#             */
/*   Updated: 2023/06/12 21:15:17 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell_state	g_minishell;

// append handler
void	append(t_parsed *temp, t_file **file, int fd)
{
	int	file_fd;

	file_fd = open((*file)->name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (file_fd == -1)
	{
		perror("error opening file\n");
		exit(1);
	}
	if ((*file)->next == NULL || (*file)->next->type != APPEND)
	{
		dup2(file_fd, STDOUT_FILENO);
		if ((*file)->next != NULL)
		{
			*file = (*file)->next;
			execute_commands(temp, *file, fd);
			close(file_fd);
			return ;
		}
		else if (temp->args[0])
			execve_or_builtin(temp->args);
	}
	close(file_fd);
}

// redirect_out handler
void	redirect_out(t_parsed *temp, t_file **file, int fd)
{
	int	file_fd;

	file_fd = open((*file)->name, O_RDONLY, 0644);
	if (file_fd == -1)
	{
		print_error((*file)->name, ": Not found\n", 1);
	}
	if ((*file)->next == NULL || (*file)->next->type != SMALLER)
	{
		dup2(file_fd, STDIN_FILENO);
		if ((*file)->next != NULL)
		{
			*file = (*file)->next;
			execute_commands(temp, *file, fd);
			close(file_fd);
			return ;
		}
		else if (temp->args[0])
			execve_or_builtin(temp->args);
	}
	close(file_fd);
}

// redirect_in handler
void	redirect_in(t_parsed *temp, t_file **file, int fd)
{
	int	file_fd;

	file_fd = open((*file)->name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file_fd == -1)
	{
		perror("error opening file\n");
		exit(1);
	}
	if ((*file)->next == NULL || (*file)->next->type != GREATER)
	{
		dup2(file_fd, STDOUT_FILENO);
		if ((*file)->next != NULL)
		{
			*file = (*file)->next;
			execute_commands(temp, *file, fd);
			close(file_fd);
			return ;
		}
		else if (temp->args[0])
			execve_or_builtin(temp->args);
	}
	close(file_fd);
}
