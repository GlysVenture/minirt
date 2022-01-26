/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:08:44 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/16 12:08:59 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Tadeusz Kondracki on 10/15/21.
//

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);

//utils
char	*ft_strjoin_f(char **s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strndup(const char *src, int len);
void	ft_bzero(void *b, size_t n);

#endif //GET_NEXT_LINE_H
