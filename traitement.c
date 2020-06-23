/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grim <grim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 12:15:45 by grim              #+#    #+#             */
/*   Updated: 2020/06/23 15:02:07 by grim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mshell.h"

int		ft_check_built_in(char *cmd, int *index)
{
	char			*built[] = {"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};
	int				i;
	int				res;

	// index: index du built_in correspondant à la commande, au sein du tableau "built"
	i = 0;
	while (built[i])
	{
		if ((res = ft_strcmp(cmd, built[i]) == 0))
		{
			*index = i;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int		ft_traitement(char **cmd, t_list **env)
{
	int	argc;
	int	built_index;

	// cas 1: la commande appelée est une commande built-in -> executée directement dans notre programme
	// cas 2: pas un built-in: on veut créer un nouveau process pour l'executer, via fork
	// --> avant de faire le fork, on vérifie que la fonction n'est pas un shell built-in
	argc = 0;
	while (cmd[argc])
		argc++;
	if (ft_check_built_in(cmd[0], &built_index) == TRUE)
	{
		ft_putstr_fd(">>built-in\n", 1);
		ft_built_in(cmd, argc, built_index, env);
		// lance la fonction "cmd";
	}
	else
	{
		ft_putstr_fd(">>fork\n", 1);
		ft_fork(cmd);
	}
	return (0);
}