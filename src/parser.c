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
		ft_exitwithmallocerror(md);
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
	node->args = ft_tokensto2parray(node->tok, md);
	node->left = NULL;
	node->right = NULL;
	return (node);
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
