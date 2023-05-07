/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 02:11:34 by sshimizu          #+#    #+#             */
/*   Updated: 2023/05/08 04:37:32 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"
#include <stdlib.h>

t_list	*new_token(char *ptr, int len)
{
	t_token	*token;
	t_list	*list;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->ptr = ptr;
	token->len = len;
	list = ft_lstnew(token);
	if (!list)
	{
		free(token);
		return (NULL);
	}
	return (list);
}

// 仮exit
void	add_token(t_list **root, t_list *token)
{
	if (!root || !token)
	{
		ft_lstclear(root, free);
		ft_lstdelone(token, free);
		exit(EXIT_FAILURE);
	}
	ft_lstadd_back(root, token);
}
