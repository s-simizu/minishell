/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:49:30 by sshimizu          #+#    #+#             */
/*   Updated: 2023/05/08 02:44:55 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef struct s_list	t_list;

typedef struct s_token
{
	char				*ptr;
	int					len;
}						t_token;

t_list					*new_token(char *ptr, int len);
void					add_token(t_list **root, t_list *token);

#endif
