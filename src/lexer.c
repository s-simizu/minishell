/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:38:07 by sshimizu          #+#    #+#             */
/*   Updated: 2023/05/08 04:42:01 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"

static void	skip_quated(char **s, char quote)
{
	(*s)++;
	while (**s && **s != quote)
		(*s)++;
	if (**s == quote)
		(*s)++;
}

static void	skip_space(char **s)
{
	int	i;

	i = 0;
	while (**s == ' ')
		(*s)++;
}

t_list	*lexer(char *s)
{
	t_list	*tokens;
	char	*ptr;

	tokens = NULL;
	ptr = s;
	while (*s)
	{
		if (*s == ' ')
		{
			skip_space(&s);
			ptr = s;
			continue ;
		}
		if (*s == '"' || *s == '\'')
			skip_quated(&s, *s);
		else
			s++;
		if (!*s || *s == ' ')
			add_token(&tokens, new_token(ptr, s - ptr));
	}
	return (tokens);
}

// /* test */
// #include <stdio.h>
// void	print_item(void *content)
// {
// 	t_token	*token;

// 	token = (t_token *)content;
// 	write(1, token->ptr, token->len);
// 	write(1, "\n", 1);
// }

// int	main(int argc, char **argv)
// {
// 	t_list	*tokens;

// 	if (argc < 2)
// 		return (0);
// 	tokens = lexer(argv[1]);
// 	ft_lstiter(tokens, print_item);
// 	ft_lstclear(&tokens, free);
// }
