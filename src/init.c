<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:08:36 by iubieta-          #+#    #+#             */
/*   Updated: 2025/01/12 20:03:50 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int **initfdarray(void)
{
    int **p;
    int *a;

    p = malloc(2 * sizeof(int *));
    a = malloc(4 * sizeof(int));
    a[0] = -1;
    a[1] = -1;
    a[2] = -1;
    a[3] = -1;
    p[0] = a;
    p[1] = a + 2;
    return (p);
}

// Queda pendiente de adaptar, pero va a ser necesario para despues
void ft_cleanup(t_md *md)
{
    ft_freetree(md->tree);
    free(md->fd[0]);
    free(md->fd);
    ft_free2parray(md->env[0]);
    free(md);
    md = NULL;
}

t_md *ft_initmetadata(void)
{
    t_md *md;
    extern char **environ;

    md = malloc(sizeof(t_md));
    md->tok = malloc(sizeof(t_token));
    md->tree = malloc(sizeof(t_tree));
    md->env = malloc(sizeof(char **));
    md->fd = initfdarray();
    return (md);
}
