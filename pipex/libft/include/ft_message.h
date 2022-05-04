/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:41:35 by abarrier          #+#    #+#             */
/*   Updated: 2022/04/16 13:22:44 by antho            ###   ########.fr       */
/*   Updated: 2022/04/11 07:58:28 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MESSAGE_H
# define FT_MESSAGE_H

# include "ft_color.h"

/***GLOBAL***/
# define SEP_P "******************************"
# define SEP_S "------------------------------"
# define ERR_ARG "Wrong argument definition"
# define ERR_FILEOPEN "File is missing or not readable"
# define ERR_MALLOC "Malloc issue"

/***FILE DESCRIPTOR***/
# define ERR_FD "File descriptor not defined"

/**STRING***/
# define ERR_MAXLEN_INT "Length string is more than MAX_LEN_INT"

/**
 * @brief Print error message on stderr in RED color according to 
 * the following structure
 * 	Error\n
 *	Function: xxxx
 *	Data string: xxxx
 *	Data character: xxxx
 *	Message: xxxx
 *
 * @param int fd: File descriptor | char *f: Function where the error is
 * char *s: Message to print | char *data: Data of the error
 * @return int | >= 1: Total of printed characters
 */
int	ft_error(char *f, char *data, char c, char *msg);

/**
 * @brief Print warning message on stdout in YELLOW color according to
 * the following structure
 * 	Warning\n
 *	Function: xxxx
 *	Data string: xxxx
 *	Data character: xxxx
 *	Message: xxxx
 *
 * @param int fd: File descriptor | char *f: Function where the error is
 * char *s: Message to print | char *data: Data of the error
 * @return int | >= 1: Total of printed characters
 */
int	ft_warning(char *f, char *data, char c, char *msg);

#endif
