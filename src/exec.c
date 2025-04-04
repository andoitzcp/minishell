/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:49:50 by iubieta-          #+#    #+#             */
/*   Updated: 2025/03/23 19:40:03 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_childproc(t_tree *tree, t_md *md)
{
	char	**cmd;
	int		**fd;
	t_tree	*next;
	//char	program[256];
	char	*program;

	sig_reset();
	fd = md->fd;
	cmd = tree->args;
	next = tree->right;
	// ft_memset(program, '\0', 256);
	//ft_strlcat(program, "/bin/", ft_strlen("/bin/") + 1);
	//ft_strlcat(program, *cmd, 50);
	program = *cmd;
	if (**cmd != '/' && **cmd != '.')
		program = ft_findbin(*cmd);
	// printf("path exec: %s\n", program);
	if (fd[IPIPE][RDEND] != -1)
	{
		//fprintf(stderr, "flag10\n");
		dup2(fd[IPIPE][RDEND], STDIN_FILENO);
		close(fd[IPIPE][RDEND]);
	}
	//fprintf(stderr, "flag10.5\n");
	if (next)
	{
        //fprintf(stderr, "flag10.6 %p\n", next);
		if (is_lredir(next->tok))
		{			//fprintf(stderr, "flag11\n");
			return ;
			/* ft_leftredir(md); //esto catearia el archivo y borraria el node de la llist */
		}
		else if (is_pipe(next->tok))
		{
			//fprintf(stderr, "flag12\n");
			dup2(fd[OPIPE][WREND], STDOUT_FILENO);
		}
		else if (is_rredir(next->tok))
		{
			//fprintf(stderr, "flag13\n");
			return ;
			/* ft_rightredir(md); */
		}
	}
	//fprintf(stderr, "flag14\n");
	close(fd[OPIPE][RDEND]);
	if (execve(program, cmd, NULL) == -1)
	{
		ft_putstr_fd("Command not found\n", 2);
	}
	close(fd[OPIPE][WREND]);
}

void	ft_parentproc(t_tree *tree, t_md *md)
{
	pid_t	pid;
	int		status;

	if (tree->right)
	{
		//printf("flag03\n");
		if (pipe(md->fd[OPIPE]) == -1)
			ft_cleanup(md);
	}
	pid = fork();
	sig_ignore();
	if (pid == -1)
		ft_cleanup(md);
	if (pid == 0)
	{
		sig_default();
		//fprintf(stderr, "flag04\n");
		//ft_printtreeinerror(tree);
		ft_childproc(tree, md);
	}
	//printf("flag05\n");
	md->fd[IPIPE][RDEND] = md->fd[OPIPE][RDEND];
	md->fd[IPIPE][WREND] = md->fd[OPIPE][WREND];
	close(md->fd[IPIPE][WREND]);
	// Guardo el codigo de salida
	waitpid(pid, &status, 0);
	// printf("Status: %i\n", status);
	if (WIFEXITED(status))
	{
		md->exit_code = WEXITSTATUS(status);
		// printf("Exit code %i\n", md->exit_code);
	}
	else if (WIFSIGNALED(status))
	{
		md->exit_code = 128 + WTERMSIG(status);
		// printf("Exit code %i\n", md->exit_code);
	}
	else
		md->exit_code = 1; // valor por defecto si nada aplica
}

// REVISAR

int is_builtin(char *cmd)
{
    return (!ft_strcmp(cmd, "cd") || 
			!ft_strcmp(cmd, "export") ||
			!ft_strcmp(cmd, "unset") ||
            !ft_strcmp(cmd, "env") || 
			!ft_strcmp(cmd, "exit") || 
			!ft_strcmp(cmd, "echo") ||
            !ft_strcmp(cmd, "pwd"));
}

void execute_builtin(char **args, t_md *md)
{
	if (!ft_strcmp(args[0], "cd"))
		md->exit_code = ft_cd(args);
	else if (!ft_strcmp(args[0], "export"))
		md->exit_code = ft_export(&md->env, args);
	else if (!ft_strcmp(args[0], "unset"))
		md->exit_code = ft_unset(&md->env, args);
	else if (!ft_strcmp(args[0], "env"))
		md->exit_code = ft_env(md->env);
	else if (!ft_strcmp(args[0], "exit"))
		ft_exit(md);
	else if (!ft_strcmp(args[0], "echo"))
		md->exit_code = ft_echo(args);
	else if (!ft_strcmp(args[0], "pwd"))
		md->exit_code = ft_pwd(args);
}
void	ft_execcmd(t_md *md)
{
	t_tree	*tree;

	tree = *(md->tree);
	while (tree)
	{
		if (tree->type == TREE_CMD)
		{
			//fprintf(stderr, "this is stderror\n");
			//printf("flag000\n");
			/* ft_printtree(tree); */
			if (is_builtin(tree->args[0]))
				execute_builtin(tree->args, md);
			else
				ft_parentproc(tree, md);
			// Buscar como implementar builtins sin forkear
		}
		tree = tree->right;
	}
}

