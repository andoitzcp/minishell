/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:28:39 by iubieta-          #+#    #+#             */
/*   Updated: 2025/02/22 17:33:02 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <ctype.h>

char	**split_quotation_blobs(char *s, char c)
{
	int		i;
	char	*p;
	char	*tmp;
	char	**arr;

	arr = ft_calloc(4, sizeof(char *));
	p = s;
	i = 0;
	if (c == '\0')
		return (arr[0] = s, arr);
	arr[i] = p;
	p = ft_strchr(p, c);
	while (p != NULL && i < 2)
	{
		if (p == s)
			arr[++i] = p;
		else if (*(p - 1) != '\\')
			arr[++i] = p;
		p++;
	    p = ft_strchr(p, c);
	}
	if (i % 2 != 0)
		return (perror(ERR_QUOTE), NULL);
	while (i > 0)
	{
		tmp = arr[i];
		arr[i] = strdup(arr[i] + 1);
		ft_bzero(tmp, ft_strlen(tmp));
		i--;
	}
	return (arr);
}

// Falta comprobar que no tenga un "\"
char	find_first_quote_char(char *s)
{
	char	*p[2];

	p[0] = ft_strchr(s, '"');
	p[1] = ft_strchr(s, '\'');
	if (p[0] != NULL && p[1] != NULL)
	{
		if (p[0] < p[1])
			return ('"');
		else
			return ('\'');
	}
	else if (p[0] != NULL)
		return ('"');
	else if (p[1] != NULL)
		return ('\'');
	else
		return ('\0');
}

t_toktype	determine_token_type(char *s)
{
	if (ft_memcmp(s, "|", 2) == 0)
		return (TOKEN_PIPE);
	else if (ft_memcmp(s, ">", 2) == 0)
		return (TOKEN_REDIR_OUT);
	else if (ft_memcmp(s, "<", 2) == 0)
		return (TOKEN_REDIR_IN);
	else if (ft_memcmp(s, ">>", 3) == 0)
		return (TOKEN_REDIR_APPEND);
	else if (ft_memcmp(s, "<<", 3) == 0)
		return (TOKEN_REDIR_HEREDOC);
	else if (s[0] == '$' && ft_strlen(s) > 1)
	{
		if (isalpha(s[1]))
			return (TOKEN_ENV_VAR);
		else if (s[1] == '_' && ft_strlen(s))
			return (TOKEN_ENV_VAR);
		else
			return (TOKEN_WORD);
	}
	else
		return (TOKEN_WORD);
}

void	classify_tokens(t_token **head)
{
	t_token	*t;

	t = *head;
	while (t)
	{
		if (t->type == TOKEN_UNKNOWN)
			t->type = determine_token_type(t->value);
		t = t->right;
	}
	return ;
}

void	append_tokens(t_token **tokens, char **arr, char *blob, char blob_type)
{
	int		i;
	char	**tmp;

	tmp = arr;
	arr = ft_split(arr[0], ' ');
	i = 0;
	while (arr[i])
		add_token(tokens, arr[i++], TOKEN_UNKNOWN);
	free(tmp);
	if (blob != NULL && blob_type == '"')
		add_token(tokens, blob, TOKEN_BLOB_DQ);
	if (blob != NULL && blob_type == '\'')
		add_token(tokens, blob, TOKEN_BLOB_SQ);
}

t_token	*tokenize(char *s)
{
	t_token	*tokens;
	char	c;
	char	**arr;
	char	*blob;

	tokens = NULL;
	while (s)
	{
		c = find_first_quote_char(s);
		arr = split_quotation_blobs(s, c);
		if (arr == NULL)
			return (NULL);
		s = arr[2];
		blob = arr[1];
		append_tokens(&tokens, arr, blob, c);
	}
	classify_tokens(&tokens);
	return (tokens);
}
