/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:31:41 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/08 15:48:24 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprint(int c)
{
	if (ft_isalnum(c) == 1 || (c >= '!' - 1 && c <= '&' + 1) || (c >= '('
				&& c <= '/') || (c >= ':' && c <= '?') || c == '@' ||
			(c >= '[' && c <= '_') || c == '`' || (c >= '{' && c <= '~'))
		return (1);
	return (0);
}