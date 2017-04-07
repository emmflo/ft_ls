/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:17:01 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/08 21:07:43 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	len;

	if (s == NULL)
		return (NULL);
	start = 0;
	len = ft_strlen(s);
	if (len == 0)
		return ("");
	end = len - 1;
	while (s[start] != '\0' &&
			(s[start] == ' ' || s[start] == '\n' || s[start] == '\t'))
		start++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end > start)
		end--;
	end++;
	return (ft_strsub(s, start, end - start));
}
