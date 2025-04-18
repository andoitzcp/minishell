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
// #include <string.h>
 // void	prompt_loop()
 // {
 // 	char *line;
 //
 // 	sig_init();
 // 	while (1)
 // 	{
 // 		line = readline(">>");
 // 		if (!line)
 // 		{
 // 			printf("exit\n");
 // 			break;
 // 		}
 // 	}
 // }
// TEST SIGNALS: BEGGINING //
int main(int argc, char **argv) 
{ 
	t_md	*md; 
	char	*input; 

	md = ft_initmetadata(); 
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
				ft_execcmd(md);
				// ft_cleanup(md);
				// md = ft_initmetadata();
			}
			// printf("1\n");
			// print_tokens_forward(*(md->tok)); 
			// printf("2\n");
			// if (md->tree)
			// 	ft_printtree(*(md->tree));
		} 
	}
	else
	{
		input = ft_artostr(++argv);
		// printf("%s\n", input);
		*(md->tok) = tokenize(input); 
		// print_tokens_forward(*(md->tok)); 
		buildtreestruct(md); 
		// ft_printtree(*(md->tree));
		ft_execcmd(md);
		// ft_cleanup(md);
		// md = ft_initmetadata();
	}
} 

// TEST SIGNALS: ENDING //

// TEST EXEC: BEGINING //
// int main(void)
// {
// 	t_md *md;
// 	char *s;
//
// 	printf("=== TEST EXEC===\n");
// 	s = strdup("cat Makefile | grep -i SRC | wc -l");
// 	printf("\nTest 1: input = <i>%s<\\i>\n", s);
// 	md = ft_initmetadata();
// 	*(md->tok) = tokenize(s);
// 	buildtreestruct(md);
// 	/* ft_printtree(*(md->tree)); */
// 	ft_execcmd(md);
// }
// TEST EXEC: ENDING//


// TEST PARSE: BEGINING //
/* int main(void) */
/* { */
/*     t_md *md; */
/*     char *s; */

/*     printf("=== TEST PARSE===\n"); */
/*     s = strdup("cat Makefile | grep -i SRC | wc -l"); */
/*     printf("\nTest 1: input = <i>%s<\\i>\n", s); */
/*     md = ft_initmetadata(); */
/*     *(md->tok) = tokenize(s); */
/*     buildtreestruct(md); */
/*     ft_printtree(*(md->tree)); */
/*     free(s); */
/*     printf("Test 1: End\n"); */

/*     s = strdup("\'cat Makefile | grep -i SRC \' | wc -l"); */
/*     printf("\nTest 2: input = <i>%s<\\i>\n", s); */
/*     md = ft_initmetadata(); */
/*     *(md->tok) = tokenize(s); */
/*     buildtreestruct(md); */
/*     ft_printtree(*(md->tree)); */
/*     free(s); */
/*     printf("Test 2: End\n"); */
/* } */
// TEST PARSE: ENDING//

// TEST TOKENIZE: BEGINING //
// int main(void)
// {
//     t_token *tokens;
//     char *s;
//
//     printf("=== TEST TOKENIZE ===\n");
//     printf("\nTest 1: input = \"\\\"cat Makefile | grep -i SRC \" | wc -l\\\"\n");
//     tokens = tokenize(ft_strdup("\"cat Makefile | grep -i SRC \" | wc -l"));
//     print_tokens_forward(tokens);
//     free_tokens(tokens);
//     printf("Test 1: End\n");
//
//
//     s = strdup("cat Makefile | grep -i SRC | wc -l | test");
//     printf("\nTest 2: input = <i>%s<\\i>\n", s);
//     tokens = tokenize(s);
//     print_tokens_forward(tokens);
//     free_tokens(tokens);
//     free(s);
//     printf("Test 2: End\n");
//
//     s = strdup("\'cat Makefile | grep -i SRC \' | wc -l");
//     printf("\nTest 3: input = <i>%s<\\i>\n", s);
//     tokens = tokenize(s);
//     print_tokens_forward(tokens);
//     free_tokens(tokens);
//     free(s);
//     printf("Test 3: End\n");
//
//     s = strdup("cat Makefile | grep -i SRC\\\" | wc -l | test");
//     printf("\nTest 4: input = <i>%s<\\i>\n", s);
//     tokens = tokenize(s);
//     print_tokens_forward(tokens);
//     free_tokens(tokens);
//     free(s);
//     printf("Test 4: End\n");
//
//     s = strdup("\"cat Makefile | grep -i SRC\' \" | wc -l");
//     printf("\nTest 5: input = <i>%s<\\i>\n", s);
//     tokens = tokenize(s);
//     print_tokens_forward(tokens);
//     free_tokens(tokens);
//     free(s);
//     printf("Test 5: End\n");
//
//     s = strdup("\"cat Makefile | grep -i SRC\\\" \" | wc -l");
//     printf("\nTest 6: input = <i>%s<\\i>\n", s);
//     tokens = tokenize(s);
//     print_tokens_forward(tokens);
//     free_tokens(tokens);
//     free(s);
//     printf("Test 6: End\n");
//
//     s = strdup("ls < \"file1 file2\" < \'file3 file4\' < file5 < file6");
//     printf("\nTest 7: input = <i>%s<\\i>\n", s);
//     tokens = tokenize(s);
//     print_tokens_forward(tokens);
//     free_tokens(tokens);
//     free(s);
//     printf("Test 7: End\n");
//
//     s = strdup("ls < \"file1 file2\" < \'file3 file4\' < \file5 < file6");
//     printf("\nTest 7: input = <i>%s<\\i>\n", s);
//     tokens = tokenize(s);
//     print_tokens_forward(tokens);
//     free_tokens(tokens);
//     free(s);
//     printf("Test 7: End\n");
//
//     s = strdup("cat Makefile | grep -i SRC\" | wc -l | test");
//     printf("\nTest 9: input = <i>%s<\\i>\n", s);
//     tokens = tokenize(s);
//     print_tokens_forward(tokens);
//     free_tokens(tokens);
//     free(s);
//     printf("Test 9: End\n");
//
// }
// // TEST TOKENIZE: ENDING //

// TEST READLINE: BEGINING //
/* int main(void) */
/* { */
/*     char *line; */

/*     while (1) */
/*     { */
/*         line = readline("$prompt>"); */
/*         add_history(line); */
/*         printf("line: %s\n", line); */
/*         free(line); */
/*     } */
/*     return (0); */
/* } */
// TEST READLINE: ENDING //
