/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:29:23 by maricard          #+#    #+#             */
/*   Updated: 2023/05/10 19:18:13 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell_state g_minishell;

void    lexer_test(t_token *token)
{
	int i;

	i = 0;
	printf("---- LEXER TEST ----\n");
	printf("[tokens %d] -> ", token->n_tokens);
	while (token->args[i])
	{
		printf("[%s] ", token->args[i]);
		i++;
	}
	printf("\n");
}