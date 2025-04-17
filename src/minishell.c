/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:04:07 by iubieta-          #+#    #+#             */
/*   Updated: 2025/04/13 20:04:08 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

int main(int argc, char **argv) 
{ 
	t_md	*md; 
	char	*input; 

	md = initmetadata(); 
	if (argc == 1)
	{
		while (1) 
		{
			sig_init();
			md->prompt = get_prompt(*md);
			input = readline(md->prompt); 
			// printf("input: %s\n", input);
			if (!input) 
			{ 
				printf("exit\n"); 
				break; 
			}
			if (input[0])
			{
				add_history(input);
				*(md->tok) = tokenize(input); 
				// print_tokens_forward(*(md->tok)); 
				buildtreestruct(md);
				recompose_tree(md);
				// printtree(*(md->tree));
				execcmd(md);
				// cleanup(md);
				// md = ft_initmetadata();
			}
			// printf("1\n");
			// print_tokens_forward(*(md->tok)); 
			// printf("2\n");
			// if (md->tree)
			// 	printtree(*(md->tree));
		} 
	}
	else
	{
		input = artostr(++argv);
		// printf("%s\n", input);
		*(md->tok) = tokenize(input); 
		// print_tokens_forward(*(md->tok)); 
		buildtreestruct(md); 
		// printtree(*(md->tree));
		execcmd(md);
		// cleanup(md);
		// md = ft_initmetadata();
	}
} 

