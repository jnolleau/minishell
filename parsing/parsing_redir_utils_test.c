/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redir_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grim <grim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:58:19 by grim              #+#    #+#             */
/*   Updated: 2020/07/22 16:18:58 by grim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mshell.h"


int set_redir_state(char *buf, int *state)
{
    int ret;
    
	if (buf[0] == '>' && buf[1] == '>')
    {
		ret = 2;
        *state = REDIR_APPEND;
    }
	else
    {
        if (buf[0] == '>')
            *state = REDIR_OUT;
        if (buf[0] == '<')
            *state = REDIR_IN;
		ret = 1;
    }
	while (buf[ret] == 9 || buf[ret] == 32)
		ret++;
    return (ret);
}

int ft_join_to_buf(char *added_str, char **initial_str)
{
    char *tmp;
    
    tmp = *initial_str;
	if ((*initial_str = ft_strjoin(tmp, added_str)) == NULL)
		return (FAILURE);
    free(tmp);
    free(added_str);
    #ifdef DEBUG_PARSING
		printf("buf: [%s]\n", *initial_str);
	#endif
    return (SUCCESS);
}

int ft_join_to_redir(char *added_str, t_list *redir_list)
{
    char	*tmp;
	t_redir	*redir;
 
	while (redir_list->next)
		redir_list = redir_list->next;
	redir = (t_redir*)redir_list->content;
    tmp = redir->file;
	if ((redir->file = ft_strjoin(tmp, added_str)) == NULL)
		return (FAILURE);
    free(tmp);
    free(added_str);
    #ifdef DEBUG_PARSING
		printf("file: [%s]\n", redir->file);
	#endif
    return (SUCCESS);
}