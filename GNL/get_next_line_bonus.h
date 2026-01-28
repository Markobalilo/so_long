/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:04:13 by antcamar          #+#    #+#             */
/*   Updated: 2026/01/22 15:55:56 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef MAX_FD
#  define MAX_FD 1024
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