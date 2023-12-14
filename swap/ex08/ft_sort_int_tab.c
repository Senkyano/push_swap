/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:49:05 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/14 18:04:59 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	*ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			j = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = j;
			tab = ft_sort_int_tab(tab, size);
		}
		i++;
	}
	return (tab);
}

int main()
{
	int t[] = {0,1,2,4,5,1,4,9,8};
	int i;
	int	*tab;

	i = 0;
	tab = ft_sort_int_tab(t,9);
	while (i < 9)
	{
		printf("%d ",t[i]);
		i++;
	}
	
	return 0;
}
