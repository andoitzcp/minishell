/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:10:32 by iubieta-          #+#    #+#             */
/*   Updated: 2025/04/13 19:47:45 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_prompt(t_md md)
{
	char	*cur_dir;
	char	*user;
	char	*prompt;
	char	*home_dir;

	if (md.prompt)
		free (md.prompt);
	cur_dir = getcwd(NULL, 0);
	cur_dir = ft_strjoin(cur_dir, "\n>");
	user = expand_var(md.env, "$USER");
	home_dir = ft_strjoin("/home/", user);
	if (ft_strncmp(home_dir, cur_dir, ft_strlen(home_dir)) == 0)
	{
		home_dir = ft_strjoin("~", &cur_dir[ft_strlen(home_dir)]);
		free(cur_dir);
		cur_dir = home_dir;
	}
	user = ft_strjoin(user, "@");
	prompt = ft_strjoin(user, cur_dir);
	free(cur_dir);
	free(user);
	return (prompt);
}

