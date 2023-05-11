/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:26:56 by maricard          #+#    #+#             */
/*   Updated: 2023/05/11 15:44:35 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**dup_env_var(char **ev)
{
	int		i;
	char	**env_copy;

	i = 0;
	while (ev[i])
		i++;
	env_copy = malloc(sizeof(char *) * (i + 1));
	if (!env_copy)
		return (0);
	i = -1;
	while (ev[++i])
		env_copy[i] = ft_strdup(ev[i]);
	env_copy[i] = 0;
	return (env_copy);
}

void	minishell_init(char **ev)
{
    errno = 0;//limpa qualquer codigo de erro anterior
	g_minishell.parent_pid = getpid();//armazena ID
    g_minishell.child_pids = (int *)malloc(sizeof(int) * 100);//aloca memoria para o array de pids
    g_minishell.child_pids_count = 0;//inicializa o contador de pids filhos
    g_minishell.opening_prompt = 0;//inicia a flag de prompt, determinar se o shell está no processo de exibir um prompt.
    g_minishell.in_file = STDIN_FILENO;//inicializa o arquivo de entrada
    g_minishell.out_file = STDOUT_FILENO;//inicializa o arquivo de saida
	g_minishell.ev = dup_env_var(ev);//duplica a variavel de ambiente
	g_minishell.paths = ft_split(getenv("PATH"), ':');//Divide a variável de ambiente PATH em strings separadas por ':', cada uma representando um caminho de diretório onde os executáveis podem ser encontrados. Estes são armazenados no campo paths da estrutura g_minishell
}
