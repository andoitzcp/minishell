#include "minishell.h"
#include <fcntl.h>
#include <unistd.h>

void handle_redir_in(t_tree *tree)
{
    int fd;

    fd = open(*(tree->args), O_RDONLY);
    dup2(fd, STDIN_FILENO);
    close(fd);
    return ;
}

void handle_redir_out(t_tree *tree)
{
    int fd;
    fd = open(*(tree->args), O_TRUNC | O_CREAT | O_WRONLY);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return ;
}

void handle_redir_hdoc(t_tree *tree)
{

    char *end;
    char *line;

    end = *(tree->args);
    while (1)
    {
        line = readline(NULL);
        if (ft_strncmp(end, line, ft_strlen(line)) != 0)
            return ;
        ft_putstr_fd(line, STDIN_FILENO);
    }
}

void handle_redir_append(t_tree *tree)
{
    int fd;

    fd = open(*(tree->args), O_APPEND);
    if (fd == -1)
        perror("open error");
    fprintf(stderr, "stdout: %d, fd: %d\n", STDOUT_FILENO, fd);
    dup2(fd, STDOUT_FILENO);
    fprintf(stderr, "stdout: %d, fd: %d\n", STDOUT_FILENO, fd);
    close(fd);
    return ;
}

void handle_redirs(t_tree *tree)
{
    t_tree *node;

    node = tree;
    while (node)
    {
        if (is_redir_in(node->tok))
            handle_redir_in(node->right);
        if (is_redir_out(node->tok))
            handle_redir_out(node->right);
        if (is_redir_hdoc(node->tok))
            handle_redir_hdoc(node->right);
        if (is_redir_append(node->tok))
        {
            ft_putstr_fd("flag00\n", 2);
            handle_redir_append(node->right);
        }
        node = node->right;
    }
}
