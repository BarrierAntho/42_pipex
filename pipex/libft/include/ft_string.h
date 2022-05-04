/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:05:35 by abarrier          #+#    #+#             */
/*   Updated: 2022/04/07 20:54:01 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_chartype.h"

/**
 * @brief Return the index to the first occurrence of the character c in the
 * string s.
 *
 * @param const char *s: String to be read | int c: Character to be searched
 * @return int | -1: is not existing, >= 0: index in the string
 */
int		ft_index(const char *s, int c);

/**
 * @brief Return the index to the last occurrence of the character c in the
 * string s.
 *
 * @param const char *s: String to be read | int c: Character to be searched
 * @return int | -1: is not existing, >= 0: index in the string
 */
int		ft_rindex(const char *s, int c);

/**
 * @brief Return a string array from string s splitted.
 *
 * @param const char *s: String to be read | int c: Character to be searched
 * @return char* | 0: is not existing, >= 0: pointer of the string array
 */
char	**ft_split(const char *s, int c);

/**
 * @brief Return a pointer to the first occurrence of the character c in the
 * string s.
 *
 * @param const char *s: String to be read | int c: Character to be searched
 * @return char* | 0: is not existing, >= 0: pointer in the string
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Return a pointer to the first character different than a character
 * from charset in the string s.
 *
 * @param char *s: String to be read | const char *chrset: Character set
 * to be searched
 * @return char* | 0: is not existing, >= 0: pointer in the string
 */
char	*ft_strchrset_exclude(const char *s, const char *chrset);

/**
 * @brief Return a pointer of destination string.
 *
 * @param char *dst: String to be modified | const char *src: String to be copied
 * @return char* | 0: is not existing, >= 0: pointer of the destination string
 */
char	*ft_strcpy(char *dst, const char *src);

/**
 * @brief Return a copy of a string in a new one.
 *
 * @param const char *s: String to be copied
 * @return char* | 0: is not existing, >= 0: pointer of the new string
 */
char	*ft_strdup(const char *s);

/**
 * @brief Return a pointer of destination string.
 *
 * @param char *dst: String to be modified | const char *src: String to be copied
 * size_t: Length of copy
 * @return char* | 0: is not existing, >= 0: pointer of the destination string
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief Return the length of the string s.
 *
 * @param const char *s: String to be read
 * @return size_t 
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Return the length of the string s.
 *
 * @param char *start: Begining pointer of the string to be read
 * char *end: Ending pointer of the string to be read.
 * @return size_t 
 */
size_t	ft_strlen_addr(char *start, char *end);

/**
 * @brief Return int of total char occurences in the string.
 *
 * @param const char *s: String to be read | int c: Character to be searched
 * @return int | 0: no occurence, >= 0: total of occurence
 */
int		ft_strnchar(const char *s, int c);

/**
 * @brief Return a pointer of destination string.
 *
 * @param char *dst: String to be modified | const char *src: String to be copied
 * size_t n: Length of copied character
 * @return char* | 0: is not existing, >= 0: pointer of the destination string
 */
char	*ft_strncpy(char *dst, const char *src, size_t n);

/**
 * @brief Return a pointer to the last occurrence of the character c in the
 * string s.
 *
 * @param const char *s: String to be read | int c: Character to be searched
 * @return char* | 0: is not existing, >= 0: pointer in the string
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Return a pointer to the last character different than a character
 * from charset in the string s.
 *
 * @param const char *s: String to be read | const char *chrset: Character set
 * to be searched
 * @return char* | 0: is not existing, >= 0: pointer in the string
 */
char	*ft_strrchrset_exclude(const char *s, const char *chrset);

/**
 * @brief Return a pointer of a new string without leading and trailing
 * space char (isspace).
 *
 * @param const char *s: String to be read
 * @return char* | 0: is not existing, >= 0: pointer of the new string
 */
char	*ft_strtrim(const char *s);

#endif
