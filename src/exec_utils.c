/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:36:04 by iubieta-          #+#    #+#             */
/*   Updated: 2025/04/20 19:48:37 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

char	*findbin(t_md md, char *bin)
{
	char	*path;
	char	**paths;
	int		i;

	if (access(bin, X_OK) == 0)
		return (bin);
	bin = ft_strjoin("/", bin);
	path = expand_var(*md.env, "PATH");
	paths = ft_split(path, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], bin);
		if (access(path, X_OK) == 0)
			return (ft_free2parray(paths), paths = NULL, path);
		free(path);
		i++;
	}
	return (ft_free2parray(paths), paths = NULL, NULL);
}

void	create_pipe(t_md *md, int pipeint)
{
	if (pipe(md->fd[pipeint]) == -1)
		cleanup(md, 1);
}

pid_t	create_fork(t_md *md)
{
	pid_t	pid;

	pid = fork();
	sig_ignore();
	if (pid == -1)
		cleanup(md, 1);
	return (pid);
}

void	handle_signals(t_md *md, pid_t pid)
{
	int	status;

	if (access("/tmp/hdoc.tmp", F_OK) == 0)
		unlink("/tmp/hdoc.tmp");
	md->fd[IPIPE][RDEND] = md->fd[OPIPE][RDEND];
	md->fd[IPIPE][WREND] = md->fd[OPIPE][WREND];
	close(md->fd[IPIPE][WREND]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		md->exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		md->exit_code = 128 + WTERMSIG(status);
	else
		md->exit_code = 1;
}
