/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:25:15 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 16:25:34 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPL_H
# define REPL_H

# include "environment.h"

void	repl(t_env env);
int		run_cmd(t_env env, char **words, char **cmd);

#endif
