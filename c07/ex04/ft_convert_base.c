/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:58:27 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/14 12:23:30 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		ft_strlen(char *str);

int		ft_is_base_valid(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 1;
		while (str[i + j] != '-' && str[i + j] != '+' && str[i + j] != '\t' &&
				str[i + j] != '\n' && str[i + j] != '\v' && str[i + j] != '\f'
				&& str[i + j] != '\r' && str[i + j] != ' ' &&
				str[i + j] != str[i] && str[i + j] != '\0')
			j++;
		if (str[i + j] != '\0')
		{
			return (0);
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int		ft_nb_strlen(long nb, int baselen)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb / baselen != 0)
	{
		i++;
		nb /= baselen;
	}
	i += 2;
	return (i);
}

char	*ft_putnbr_base(long nbr, char *base, char *str_ret, int pos)
{
	int		len;

	len = ft_strlen(base);
	if (nbr < 0)
	{
		str_ret[0] = '-';
		nbr *= -1;
	}
	if (nbr / len > 0)
		ft_putnbr_base(nbr / len, base, str_ret, pos - 1);
	str_ret[pos] = base[nbr % len];
	return (str_ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		len_str;
	char	*str_ret;

	if (!ft_is_base_valid(base_from) || !ft_is_base_valid(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	len_str = ft_nb_strlen(nb, ft_strlen(base_to));
	str_ret = malloc(len_str * sizeof(char));
	str_ret[len_str - 1] = '\0';
	str_ret = ft_putnbr_base(nb, base_to, str_ret, len_str - 2);
	return (str_ret);
}
