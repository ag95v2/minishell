/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:26:57 by bgian             #+#    #+#             */
/*   Updated: 2020/02/02 22:40:13 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSIONS_H
# define EXPANSIONS_H

char	*expand_dollar(char **word, t_env env);
char	*tilda_expansion(char **words, t_env env);

#endif
