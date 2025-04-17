/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:19:09 by iubieta           #+#    #+#             */
/*   Updated: 2025/02/22 17:12:30 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <time.h>

t_tree	*buildtreenode(t_token *token, t_md *md)
{
	t_tree	*node;

	if (!token)
		return (NULL);
	node = (t_tree *)malloc(sizeof(t_tree));
	if (node == NULL)
		exitwithmallocerror(md);
	node->tok = token;
	if (is_redir(token))
		node->type = TREE_REDIR;
	else
	{
		node->type = TREE_CMD;
		while (!is_redir(token->right) && token->right != NULL)
			token = token->right;
	}
	*(md->tok) = token->right;
	token->right = NULL;
	node->args = tokensto2parray(node->tok, md);
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/*
 * This function aims to reorganize the tree to accomodate
 * left redirs into an orthogonal direction
 */
void recompose_tree(t_md *md)
{
	t_tree *node;
	t_tree *p;
	t_tree *t;

	node = *(md->tree);
	while (node)
	{
		p = node;
		while (p && !is_pipe(p->tok))
		{
			if (!is_redir(p->tok))
			{
				p = p->right;
				continue ;
			}
			if (node->left != NULL)
				freetree(node->left);
			node->left = p;
			node->right = p->right->right;
			p->right->right = NULL;
			p = node;
		}
		node = node->right;
	}
}

void	buildtreestruct(t_md *md)
{
	t_tree	*node;
	t_tree	*tmp;

	tmp = NULL;
	while (*(md->tok) != NULL)
	{
		node = buildtreenode(*(md->tok), md);
		if (!tmp)
			*(md->tree) = node;
		else
		{
			tmp->right = node;
			node->left = tmp;
		}
		tmp = node;
	}
}
