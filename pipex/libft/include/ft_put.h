/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:28:09 by abarrier          #+#    #+#             */
/*   Updated: 2022/04/11 11:50:18 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_H
# define FT_PUT_H

# include <unistd.h>
# include "ft_string.h"

/**
 * @brief Return int of total printed characters
 *
 * @param int fd: File descriptor | int c: Character to be printed
 * @return int | -1: error, >= 0: total of printed characters
 */
int		ft_putchar_fd(int fd, int c);

/**
 * @brief Return int of total printed numbers
 *
 * @param int fd: File descriptor
 * const char base*: Base string as: 01, 0123456789, 0123456789ABCDEF
 * long long un: Number to print
 * @return int | >= 0: total of printed characters
 */
int		ft_putn_base_fd(int fd, const char *base, long long n);

/**
 * @brief Return int of total printed characters
 *
 * @param int fd: File descriptor | char s*: Srting to be printed
 * @return int | -1: error, >= 0: total of printed characters
 */
int		ft_putstr_fd(int fd, char *s);

/**
 * @brief Return int of total printed numbers by using recursivity
 *
 * @param int fd: File descriptor
 * const char base*: Base string as: 01, 0123456789, 0123456789ABCDEF
 * unsigned long long un: Number to print
 * int *res: Address to save each printed number
 * @return int | >= 0: total of printed characters
 */
void	ft_putun_base_fd_recursive(int fd, const char *base,
			unsigned long long un, int *res);

#endif
