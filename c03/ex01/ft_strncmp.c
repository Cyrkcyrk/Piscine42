/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:05:32 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/09 15:06:50 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1 && s2 && s1[i] != '\0' && s2[i] != '\0'
		&& s1[i] == s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}
