/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 11:28:47 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/24 15:51:58 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f)(char*))
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (++i < length)
	{
		if ((*f)(tab[i]) != 0)
			count++;
	}
	return (count);
}
