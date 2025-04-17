#include "minishell.h"
#include <fcntl.h>
#include <unistd.h>

t_tree *handle_redir_in(t_tree *node, t_md *md)
{
    int fd;
    t_tree *filenode;
    char **cmd;

	cmd = node->args;
    filenode = node->right->right;
    fd = open(*(filenode->args), O_RDONLY);
    if (fd == -1)
         cleanup(md);
    dup2(fd, STDIN_FILENO);
	if (execve(ft_findbin(*cmd), cmd, md->env) == -1)
		ft_putstr_fd("Command not found\n", 2);
    md->nodeact = filenode->right;
}
