/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:51:39 by antcamar          #+#    #+#             */
/*   Updated: 2026/01/22 15:55:56 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin2(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *str);
char	*get_next_line(int fd);
char	*extract_line(char **stash);
char	*ft_strchr(const char *s, int c);
char	*clear(char *buf, char *stash);

#endif