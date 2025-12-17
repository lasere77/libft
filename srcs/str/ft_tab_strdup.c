/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:10:49 by mcolin            #+#    #+#             */
/*   Updated: 2025/12/17 16:15:24 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_tab_strdup(char **strs)
{
	char	**result;
	size_t	tab_size;
	size_t	i;

	if (!strs || !*strs)
		return (NULL);
	tab_size = 0;
	while (strs[tab_size])
		tab_size++;
	result = ft_calloc(tab_size + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (tab_size--)
	{
		result[i] = ft_strdup(strs[i]);
		if (!result[i])
		{
			ft_free_split(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}
