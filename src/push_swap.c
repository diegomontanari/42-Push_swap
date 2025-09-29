/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:03:33 by dmontana          #+#    #+#             */
/*   Updated: 2025/09/28 17:03:36 by dmontana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// argc e argv non sono variabili speciali come
// __name__ in Python, ma sono solo nomi di variabili.
// Il compilatore capisce che sono gli argomenti della linea
// di comando perché sono dati in input al main.
// Quindi, possono avere un qualsiasi altro nome.
int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_process(argc, argv);
	if (!a)
		return (0);
	if (ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
