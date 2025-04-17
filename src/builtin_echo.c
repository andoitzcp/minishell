/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:15:10 by iubieta-          #+#    #+#             */
/*   Updated: 2025/03/23 19:28:47 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(char **args)
{
	int		i;
	int		flag;

	flag = 0;
	if (args[1] == NULL)
	{
		printf("\n");
		return (0);
	}
	i = 0;
	if (strncmp(args[++i], "-n", 2) == 0)
		flag = 1;
	i += flag;
	if (args[i])
		printf("%s", args[i]);
	else
		return (0);
	while (args[++i])
		printf(" %s", args[i]);
	if (!flag)
		printf("\n");
	return (0);
}

/* int main (void) */
/* { */
/*     char *s; */
/*     t_tree node; */

/*     s = strdup("echo -n hola mundo"); */
/*     node.args = ft_split(s, ' '); */
/*     printf("===TEST 1===\n"); */
/*     printf("EXPECTED: hola mundo\n"); */
/*     printf("ACTUAL: "); */
/*     echo(&node); */
/*     printf("\n"); */
/*     free(s); */

/*     s = strdup("echo hola mundo"); */
/*     node.args = ft_split(s, ' '); */
/*     printf("===TEST 2===\n"); */
/*     printf("EXPECTED: hola mundo\n\n"); */
/*     printf("ACTUAL: "); */
/*     echo(&node); */
/*     printf("\n"); */
/*     free(s); */

/*     s = strdup("echo"); */
/*     node.args = ft_split(s, ' '); */
/*     printf("===TEST 3===\n"); */
/*     printf("EXPECTED:\n\n"); */
/*     printf("ACTUAL:"); */
/*     echo(&node); */
/*     printf("\n"); */
/*     free(s); */

/*     s = strdup("echo -n"); */
/*     node.args = ft_split(s, ' '); */
/*     printf("===TEST 4===\n"); */
/*     printf("EXPECTED:\n"); */
/*     printf("ACTUAL:"); */
/*     echo(&node); */
/*     printf("\n"); */
/*     free(s); */
/* } */
